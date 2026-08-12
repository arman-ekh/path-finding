#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
private:
    T data;
    Node<T>* next;
    Node<T>* prev;

public:
    Node(T data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

    void set_prev(Node<T>* last) {
        this->prev = last;
    }

    void set_next(Node<T>* next_node) {
        this->next = next_node;
    }

    T get_data() const {
        return data;
    }

    void set_data(T new_data) {
        this->data = new_data;
    }

    Node<T>* get_prev() const {
        return prev;
    }

    Node<T>* get_next() const {
        return next;
    }
};

#endif