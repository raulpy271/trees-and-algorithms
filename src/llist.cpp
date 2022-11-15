
#include "llist.h"

template <typename T> LinkedList<T>::LinkedList(T value) {
    this->value = value;
    this->next = nullptr;
}

template <typename T> void LinkedList<T>::delete_list() {
    LinkedList<T>* to_delete = this;
    LinkedList<T>* next = this->next;
    while (to_delete->next != nullptr) {
        next = to_delete->next;
        delete to_delete;
        to_delete = next;
    }
    delete to_delete;
}

template <typename T> void list_insert_start(LinkedList<T>** list, T value) {
    LinkedList<T>* node = new LinkedList<T>(value);
    node->next = (*list);
    (*list) = node;
}

template <typename T> T list_pop_start(LinkedList<T>** list) {
    if (list != nullptr && (*list) != nullptr) {
        T value = (*list)->value;
        LinkedList<T>* to_delete = *list;
        *list = (*list)->next;
        delete to_delete;
        return value;
    } else {
        throw "Linked list underflow exception!";
    }
}

template class LinkedList<bool>;
template void list_insert_start<bool>(LinkedList<bool>**, bool);
template bool list_pop_start<bool>(LinkedList<bool>**);