
#ifndef PQUEUE_H_
#define PQUEUE_H_

#include <stddef.h>

template <typename T> class AscedingPQueue {
public:
    T value;
    int priority;
    AscedingPQueue<T>* next;

    AscedingPQueue(T value, int priority);

    size_t count_nodes();
    void delete_queue();
};

template <typename T> void pq_insert(AscedingPQueue<T>** pqueue, T value, int priority);

template <typename T> T pq_pop_min(AscedingPQueue<T>** pqueue);

#endif // PQUEUE_H_