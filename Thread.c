#include "linked.h"
#include "Init.h"
#include "Scheduler.h"
#include "Thread.h"


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
	thread_t return_val = pthread_self();
	return return_val;
}	
