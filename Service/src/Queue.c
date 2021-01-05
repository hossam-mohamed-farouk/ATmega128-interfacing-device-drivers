#include "Queue.h"

void create_queue(queue_t* pq)
{
    pq->frnt = 0;
    pq->rear = -1;
    pq->q_size = 0;
}
void append(QUEUE_ENTRY e,queue_t* pq)
{
    if(pq->rear == (MAX_Q_SIZE - 1))
    {
        pq->rear = 0;
    }
    else
    {
        pq->rear ++;
    }
    pq->entry[pq->rear] = e;
    pq->q_size ++;
}
void serve(QUEUE_ENTRY* e,queue_t* pq)
{
    *e = pq->entry[pq->frnt];
    if(pq->frnt == (MAX_Q_SIZE - 1))
    {
        pq->frnt = 0;
    }
    else
    {
        pq->frnt ++;
    }
    pq->q_size --;
}
int queue_empty(queue_t* pq)
{
    return !pq->q_size;
}
int queue_full(queue_t* pq)
{
    return (pq->q_size  == MAX_Q_SIZE);
}
int queue_size(queue_t* pq)
{
    return pq->q_size;
}
void clear_queue(queue_t* pq)
{
    pq->frnt = 0;
    pq->rear = -1;
    pq->q_size = 0;
}
