#ifndef __THREAD_H__
#define __THREAD_H__

#include <pthread.h>



#define TIMESLICE	(2)


typedef int BOOL;
typedef pthread_t	thread_t;
typedef void thread_attr_t;


typedef enum{
	THREAD_STATUS_RUN = 0,
	THREAD_STATUS_READY = 1,
	THREAD_STATUS_BLOCKED = 2,
	THREAD_STATUS_ZOMBIE 3, 
}ThreadStatus;

typedef struct _Thread {
//	ThreadStatus			status;
//    	pthread_t			tid;
//    	pthread_cond_t     		readyCond;
//   	BOOL				bRunnable;
//   	pthread_mutex_t   		readyMutex;
//	pthread_t			parentTid;
	char					name;
	_Thread*				pPrev;
	_Thread*				pNext;
} Thread;	

typedef struct __wrapperArg {
   void*  (*funcPtr)(void*);
   void* funcArg;
} WrapperArg;


/* head and tail pointers for ready queue */ 
Thread* 	ReadyQHead;
Thread*		ReadyQTail;

/* head and tail pointers for waiting queue */
Thread*		WaitQHead;
Thread*		WaitQTail;


int 		thread_create(thread_t *thread, thread_attr_t *attr, void *(*start_routine) (void *), void *arg);
int 		thread_join(thread_t thread, void **retval);
int 		thread_suspend(thread_t tid);
int		thread_resume(thread_t tid);
thread_t 	thread_self();

//linked list function

Thread* init_link();
void set_prev(Thread* source, Thread* target){source->pPrev = target;}
void set_next(Thread* source, Thread* target){source->pNext = target;}
void add_tcb(Thread** tail_ptr, Thread* new_node);
Thread* copy_head_tcb(Thread* node);
void remove_head_tcb(Thread** head_ptr);
void head_to_tail(Thread** head_ptr, Thread** tail_ptr);
void add_tcb_head(Thread** head_ptr, Thread** tail_ptr, Thread* new_node)
Thread* find_tcb(Thread* head_ptr, pthread_t tid);

#endif /* __THREAD_H__ */


