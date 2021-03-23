#ifndef TICKET_LOCK_H
#define TICKET_LOCK_H
#define _GNU_SOURCE
      
#include <pthread.h>
#include <sched.h>

typedef struct __lock_t 
{
    int ticket;
    int turn;
} lock_t;

void lock_init(lock_t* lock)
{
    lock->ticket = 0;
    lock->turn = 0;
}

void lock(lock_t* lock)
{
    int myturn = __sync_fetch_and_add(&(lock->ticket), 1);
    while (lock->turn != myturn); // spin
    //while (lock->turn != myturn)
    //    sched_yield();
}

void unlock(lock_t* lock)
{
    __sync_fetch_and_add(&(lock->turn), 1);
}

#endif
