
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <string>
#include <cstddef>

template <typename T> class LinkedList {
public:
    T value;
    LinkedList<T>* next;

    LinkedList(T value);

    void delete_list();
};

std::string bool_list_to_string(LinkedList<bool>* list);

template <typename T> void delete_array_of_linked_list(LinkedList<T>** arr, size_t size);

template <typename T> void list_insert_start(LinkedList<T>** list, T value);

template <typename T> T list_pop_start(LinkedList<T>** list);

#endif // LINKED_LIST_H_