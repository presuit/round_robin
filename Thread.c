#include "linked.h"
//#include "Thread.h"
//#include "Init.h"
//#include "Scheduler.h"

/*
int 	thread_create(thread_t *thread, thread_attr_t *attr, void *(*start_routine) (void *), void *arg)
{

}


int 	thread_join(thread_t thread, void **retval)
{

}


int 	thread_suspend(thread_t tid)
{

}


int	thread_resume(thread_t tid)
{

}




thread_t	thread_self()
{

}	
*/

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
//	copy_node->status = node->status;
//	copy_node->tid = node->tid;
//	copy_node->readyCond = node->readyCond;
//	copy_node->bRunnable = node->bRunnable;
//	copy_node->readyMutex = node->readyMutex;
//	copy_node->parentTid = node->parentTid;
		copy_node->name = node->name;
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

int main(){
	Thread* a, *b, *c, *d, *head_ptr, *tail_ptr, *cursor;
	Thread* e;

	a = init_link();
	b = init_link();
	c = init_link();
	d = init_link();
	e = init_link();

	a->name = 'a';
	b->name = 'b';
	c->name = 'c';
	d->name = 'd';
	e->name = 'e';

	set_next(a, b);
	set_prev(b, a);
	
	head_ptr = a;
	tail_ptr = b;

	add_tcb(&tail_ptr, c);
	add_tcb(&tail_ptr, d);

	printf("original\n");

	for(cursor = head_ptr; cursor != NULL; cursor = cursor->pNext){
		printf("[head_ptr] : %c\n", cursor->name);
	}

	head_to_tail(&head_ptr, &tail_ptr);
	
	printf("move head to tail\n");
	for(cursor = head_ptr; cursor != NULL; cursor = cursor->pNext){
		printf("[head_ptr] : %c\n", cursor->name);
	}

	head_to_tail(&head_ptr, &tail_ptr);
	
	printf("move head to tail\n");
	for(cursor = head_ptr; cursor != NULL; cursor = cursor->pNext){
		printf("[head_ptr] : %c\n", cursor->name);
	}
	
	add_tcb_head(&head_ptr, &tail_ptr, e);

	printf("[add_tcb_head]\n");
	for(cursor = head_ptr; cursor != NULL; cursor = cursor->pNext){
		printf("[head_ptr] : %c\n", cursor->name);
	}

	cursor = find_tcb(head_ptr, 'c');

	if(cursor != NULL){
		printf("found it %c\n", cursor->name);
	}
	else {
		printf("not found\n");
	}






	return 0;
}
