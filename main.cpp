#include "main.h"

//Destructor
// Frees all nodes in the queue to prevent memory leaks
template <typename T>
Queue<T>::~Queue() {
    while (!empty()) {
        pop();
    }
}

//Push function
// Adds a new item to the back of the queue
template <typename T>
void Queue<T>::push(const T& item) {
    Node* new_node = new Node(item);          // Create a new node

    if (empty()) {                            // Queue is empty
        front_of_queue = back_of_queue = new_node;
    } else {
        back_of_queue->next = new_node;       // Link new node to current last node
        back_of_queue = new_node;             // Update the back pointer
    }

    num_items++;                              // Increment item count
}

//Pop function 
// Removes the front item from the queue
template <typename T>
void Queue<T>::pop() {
    if (empty()) throw out_of_range("Queue is empty.");

    Node* old_front = front_of_queue;         // Save current front node
    front_of_queue = front_of_queue->next;    // Move front pointer

    if (front_of_queue == nullptr)            // Queue became empty
        back_of_queue = nullptr;

    delete old_front;                         // Delete the old front node
    num_items--;                              // Decrement item count
}

//Front Function
// Returns the front item in the queue
template <typename T>
T Queue<T>::front() const {
    if (empty()) throw out_of_range("Queue is empty.");
    return front_of_queue->data;
}

//Size function
// Returns the number of items in the queue
template <typename T>
int Queue<T>::size() const {
    return num_items;
}

//Empty function
// Returns true if the queue is empty
template <typename T>
bool Queue<T>::empty() const {
    return num_items == 0;
}

// Move to rear function
// Removes the front item and adds it to the rear
template <typename T>
void Queue<T>::move_to_rear() {
    if (empty()) return;

    T temp = front(); // Get front element
    pop();            // Remove front
    push(temp);       // Add it back to the rear
}

//Display function
// Displays all elements in the queue using only core functions
template <typename T>
void Queue<T>::display_all() {
    int count = size();

    for (int i = 0; i < count; ++i) {
        T val = front();         // Get front
        cout << val << " ";      // Print it
        move_to_rear();          // Cycle it to the back to preserve order
    }

    cout << endl;
}

//Insertion Sort Queue function
// Sorts a queue using insertion sort logic by building a new sorted queue
void insertion_sort_queue(Queue<int>& q) {
    Queue<int> sorted;   // Temporary queue to hold sorted elements

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        int sortedSize = sorted.size();
        bool inserted = false;

        // Insert into correct position in sorted queue
        for (int i = 0; i < sortedSize; ++i) {
            int val = sorted.front();
            sorted.pop();

            if (!inserted && curr < val) {
                sorted.push(curr);   // Insert current before larger element
                inserted = true;
            }

            sorted.push(val);        // Push element back
        }

        if (!inserted) {
            sorted.push(curr);       // If largest, add to end
        }
    }

    // Copy sorted queue back into original queue
    while (!sorted.empty()) {
        q.push(sorted.front());
        sorted.pop();
    }
}

//main
int main() {
    // test queue implementation
    Queue<int> q;
    q.push(70);
    q.push(50);
    q.push(30);
    q.push(10);

    cout << "Queue contents: ";
    q.display_all();

    q.move_to_rear();  // Test move_to_rear
    cout << "After move_to_rear: ";
    q.display_all();

    // Test Recursive Linear Search 
    vector<char> chars = {'A', 'B', 'C', 'B', 'D'};
    char target = 'B';

    int result = linear_search_last(chars, target, chars.size() - 1);

    if (result != -1)
        cout << "Last occurrence of '" << target << "' is at index: " << result << endl;
    else
        cout << "Target '" << target << "' not found." << endl;

    // Test Insertion Sort on Queue
    cout << "Before sorting queue: ";
    q.display_all();

    insertion_sort_queue(q);

    cout << "After sorting queue: ";
    q.display_all();

    return 0;
}
