
#include "pqueue.h"
#include "freq.h"

template <typename T> AscedingPQueue<T>::AscedingPQueue(T value, int priority) {
    this->value = value;
    this->priority = priority;
    this->next = nullptr;
}

template <typename T> void AscedingPQueue<T>::delete_queue() {
    AscedingPQueue<T>* to_delete = this;
    AscedingPQueue<T>* next = this->next;
    while (to_delete->next != nullptr) {
        next = to_delete->next;
        delete to_delete;
        to_delete = next;
    }
    delete to_delete;
}

template <typename T> void pq_insert(AscedingPQueue<T>** pqueue, T value, int priority) {
    AscedingPQueue<T>* pqueue_to_insert = new AscedingPQueue<T>(value, priority);
    AscedingPQueue<T>* current_node = *pqueue;
    if (priority <= current_node->priority) {
        // Should insert before first element
        pqueue_to_insert->next = current_node;
        *pqueue = pqueue_to_insert;
    }
    else {
        // Should insert after first element
        while (current_node->next != nullptr && priority > current_node->next->priority) {
            current_node = current_node->next;
        }
        pqueue_to_insert->next = current_node->next;
        current_node->next = pqueue_to_insert;
    }
}

template <typename T> T pq_pop_min(AscedingPQueue<T>** pqueue) {
    if (pqueue != nullptr && (*pqueue) != nullptr) {
        T value = (*pqueue)->value;
        AscedingPQueue<T>* to_delete = *pqueue;
        *pqueue = (*pqueue)->next;
        delete to_delete;
        return value;
    } else {
        throw "Queue underflow exception!";
    }
}

template class AscedingPQueue<Freq<char>>;
template void pq_insert<Freq<char>> (AscedingPQueue<Freq<char>>**, Freq<char>, int);
template Freq<char> pq_pop_min<Freq<char>> (AscedingPQueue<Freq<char>>**);
