#include "linked.h"
#include "Init.h"
#include "Scheduler.h"
#include "Thread.h"
#include <signal.h>

void* __wrapperFunc(void* arg){
	void* ret;
	WrapperArg* pArg = (WrapperArg*)arg
	sigset_t set;
	int retsig;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigwait(&set, &retsig);

	__thread_wait_handler(0);
	void* funcPtr = PArg->funcptr;
	void* funcArg = pArg->funcArg;

	ret = (*funcPtr)(funcArg);
	return ret;
}

int 	thread_create(thread_t *thread, thread_attr_t *attr, void *(*start_routine) (void *), void *arg)
{
	pthread_create(thread, attr, (*start_routine)(void *), arg );
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
