#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <utility>

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int list_size;

    void normalize_index(int *index) {
        if (list_size == 0) return;
        *index %= list_size;
        if (*index < 0) {
            *index += list_size;
        }
    }

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        list_size = 0;
    }

    ~DoublyLinkedList() {
        Node<T>* current = tail;
        while (current != nullptr) {
            Node<T>* next_node = current->get_next();
            delete current;
            current = next_node;
        }
    }

    void add_node(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            head->set_next(newNode);
            newNode->set_prev(head);
            head = newNode;
        }
        list_size++;
    }

    Node<T>* get_node(int index) {
        if (list_size == 0) {
            std::cout << "Empty list" << std::endl;
            return nullptr;
        }
        normalize_index(&index);
        Node<T>* tailCopy = tail;
        for (int i = 0; i < index; i++) {
            tailCopy = tailCopy->get_next();
        }
        return tailCopy;
    }

    void remove_node(int index) {
        if (list_size == 0) return;

        normalize_index(&index);
        Node<T>* node_to_remove = get_node(index);
        if (!node_to_remove) return;

        if (node_to_remove == tail) {
            tail = node_to_remove->get_next();
            if (tail) tail->set_prev(nullptr);
            else head = nullptr;
        } else if (node_to_remove == head) {
            head = node_to_remove->get_prev();
            if (head) head->set_next(nullptr);
            else tail = nullptr;
        } else {
            node_to_remove->get_prev()->set_next(node_to_remove->get_next());
            node_to_remove->get_next()->set_prev(node_to_remove->get_prev());
        }

        delete node_to_remove;
        list_size--;
    }

    void insert_node(int index, const T& data) {
        if (list_size == 0 || index >= list_size) {
            add_node(data);
            return;
        }

        normalize_index(&index);

        if (index == 0) {
            Node<T>* newNode = new Node<T>(data);
            newNode->set_next(tail);
            tail->set_prev(newNode);
            tail = newNode;
            list_size++;
            return;
        }

        Node<T>* current = get_node(index);
        Node<T>* prev_node = current->get_prev();

        Node<T>* newNode = new Node<T>(data);
        newNode->set_next(current);
        newNode->set_prev(prev_node);

        if (prev_node) prev_node->set_next(newNode);
        current->set_prev(newNode);

        list_size++;
    }

    void swap_node(int index1, int index2) {
        if (index1 == index2 || list_size < 2) return;

        normalize_index(&index1);
        normalize_index(&index2);

        if (index1 > index2) {
            std::swap(index1, index2);
        }

        Node<T>* node1 = get_node(index1);
        Node<T>* node2 = get_node(index2);

        if (!node1 || !node2) return;

        if (node1->get_next() == node2) {
            Node<T>* prev_of_node1 = node1->get_prev();
            Node<T>* next_of_node2 = node2->get_next();

            if (prev_of_node1) prev_of_node1->set_next(node2);
            if (next_of_node2) next_of_node2->set_prev(node1);

            node2->set_prev(prev_of_node1);
            node2->set_next(node1);
            node1->set_prev(node2);
            node1->set_next(next_of_node2);
        } else {
            Node<T>* prev1 = node1->get_prev();
            Node<T>* next1 = node1->get_next();
            Node<T>* prev2 = node2->get_prev();
            Node<T>* next2 = node2->get_next();

            if (prev2) prev2->set_next(node1);
            if (next2) next2->set_prev(node1);

            if (prev1) prev1->set_next(node2);
            if (next1) next1->set_prev(node2);

            node1->set_prev(prev2);
            node1->set_next(next2);
            node2->set_prev(prev1);
            node2->set_next(next1);
        }

        if (head == node1) head = node2;
        else if (head == node2) head = node1;

        if (tail == node1) tail = node2;
        else if (tail == node2) tail = node1;
    }

    void swap_data(int index1, int index2) {
        Node<T>* node1 = get_node(index1);
        Node<T>* node2 = get_node(index2);

        if (node1 && node2) {
            T temp = node1->get_data();
            node1->set_data(node2->get_data());
            node2->set_data(temp);
        }
    }

    int get_list_size() const {
        return list_size;
    }

    void print_list() const {
        Node<T>* current = tail;
        while (current != nullptr) {
            std::cout << current->get_data() << " ";
            current = current->get_next();
        }
        std::cout << std::endl;
    }
};

#endif