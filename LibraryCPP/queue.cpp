#include "queue.h"
#include <stdexcept>

struct Queue {
    Vector* vec;
    size_t head;
    size_t count;
};

Queue* queue_create() {
    Queue* q = new Queue;
    q->vec = vector_create();
    q->head = 0;
    q->count = 0;
    return q;
}

void queue_delete(Queue* queue) {
    if (queue) {
        vector_delete(queue->vec);
        delete queue;
    }
}

void queue_insert(Queue* queue, Data data) {
    if (queue->count == vector_size(queue->vec)) {
        size_t old_cap = vector_size(queue->vec);
        size_t new_cap = old_cap == 0 ? 4 : old_cap * 2;

        Vector* new_vec = vector_create();
        vector_resize(new_vec, new_cap);

        for (size_t i = 0; i < queue->count; ++i) {
            vector_set(new_vec, i, vector_get(queue->vec, (queue->head + i) % old_cap));
        }

        vector_delete(queue->vec);
        queue->vec = new_vec;
        queue->head = 0;
    }

    size_t tail = (queue->head + queue->count) % vector_size(queue->vec);
    vector_set(queue->vec, tail, data);
    queue->count++;
}

Data queue_get(const Queue* queue) {
    if (queue_empty(queue)) throw std::out_of_range("Queue is empty");
    return vector_get(queue->vec, queue->head);
}

void queue_remove(Queue* queue) {
    if (queue_empty(queue)) throw std::out_of_range("Queue is empty");
    queue->head = (queue->head + 1) % vector_size(queue->vec);
    queue->count--;
}

bool queue_empty(const Queue* queue) {
    return queue->count == 0;
}