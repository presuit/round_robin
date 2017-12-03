#include <stdio.h>
#include <stdlib.h>

typedef struct _Thread {
	char						name;
	struct _Thread*				pPrev;
	struct _Thread*				pNext;
} Thread;	

//linked list function

Thread* init_link();
void set_prev(Thread* source, Thread* target){source->pPrev = target;}
void set_next(Thread* source, Thread* target){source->pNext = target;}
void add_tcb(Thread** tail_ptr, Thread* new_node);
Thread* copy_head_tcb(Thread* node);
void remove_head_tcb(Thread** head_ptr);
void head_to_tail(Thread** head_ptr, Thread** tail_ptr);

