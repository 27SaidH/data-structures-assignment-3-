#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <vector>
using namespace std;

// Queue Class
template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& item, Node* next_node = nullptr) : data(item), next(next_node) {}
    };

    Node* front_of_queue;
    Node* back_of_queue;
    int num_items;

public:
    Queue() : front_of_queue(nullptr), back_of_queue(nullptr), num_items(0) {}
    ~Queue();

    void push(const T& item);
    void pop();
    T front() const;
    int size() const;
    bool empty() const;
    void move_to_rear();
    void display_all();
};

//Recursive Linear Search
template <typename Item_Type>
int linear_search_last(const vector<Item_Type>& items, const Item_Type& target, size_t pos_last) {
    if (pos_last == static_cast<size_t>(-1))
        return -1;
    if (items[pos_last] == target)
        return pos_last;
    return linear_search_last(items, target, pos_last - 1);
}

#endif
