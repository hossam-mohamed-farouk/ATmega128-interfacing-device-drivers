#ifndef _QUEUE_H_
#define _QUEUE_H_

#define MAX_Q_SIZE 20
#define QUEUE_ENTRY int

typedef struct
{
    QUEUE_ENTRY entry[MAX_Q_SIZE];
    QUEUE_ENTRY rear;
    QUEUE_ENTRY frnt;
    int q_size;
}queue_t;

void create_queue(queue_t* pq);
void append(QUEUE_ENTRY e,queue_t* pq);
void serve(QUEUE_ENTRY* e,queue_t* pq);
int queue_empty(queue_t* pq);
int queue_full(queue_t* pq);
int queue_size(queue_t* pq);
void clear_queue(queue_t* pq);

#endif // _QUEUE_H_
