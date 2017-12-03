#ifndef __LINKED_H__
#define __LINKED_H__
//linked list function
#include "Thread.h"
#include <stdio.h>
#include <stdlib.h>

Thread* init_link(){
	Thread* ptr;
	ptr = (Thread*)malloc(sizeof(Thread));
	ptr->pPrev = NULL;
	ptr->pNext = NULL;

	return ptr;
}

void add_tcb(Thread** tail_ptr, Thread* new_node){
	Thread* prev_node = *tail_ptr;
	
	set_prev(new_node, prev_node);
	set_next(prev_node, new_node);
	
	*tail_ptr = prev_node->pNext;
}

void add_tcb_head(Thread** head_ptr, Thread** tail_ptr, Thread* new_node){
	if(*head_ptr == NULL && *tail_ptr == NULL){
		*head_ptr = new_node;
		*tail_ptr = new_node;
	}
	else {
		Thread* head_node = *head_ptr;

		set_prev(head_node, new_node);
		set_next(new_node, head_node);

		*head_ptr = head_node->pPrev;
	}
}

Thread* copy_head_tcb(Thread* node){
	Thread* copy_node = init_link();
	
	if(node != NULL){
		copy_node->status = node->status;
		copy_node->tid = node->tid;
		copy_node->readyCond = node->readyCond;
		copy_node->bRunnable = node->bRunnable;
		copy_node->readyMutex = node->readyMutex;
		copy_node->parentTid = node->parentTid;
	}
	else {
		printf("wrong input happended in copy_head_tcb func\n");
		return NULL;
	}

	return copy_node;
}

void remove_head_tcb(Thread** head_ptr){
	Thread* remove_node = *head_ptr;
	Thread* remove_next_node = remove_node->pNext;

	*head_ptr = remove_next_node;
	free(remove_node);
}

void head_to_tail(Thread** head_ptr, Thread** tail_ptr){
	Thread* copy_node = copy_head_tcb(*head_ptr);

	remove_head_tcb(head_ptr);
	add_tcb(tail_ptr, copy_node);
}

Thread* find_tcb(Thread* head_ptr, char tid){
	Thread* cursor;

	for(cursor = head_ptr; cursor != NULL; cursor = cursor->pNext){
		if(cursor->name == tid){
			return cursor;
		}
	}
}

void move_tcb(Thread* head_ptr, pthread_t tid, Thread** anothre_head_ptr){}
#endif /* __LINKED_H__ */
