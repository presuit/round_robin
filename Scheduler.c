#include "Init.h"
#include "Thread.h"
#include "linked.h"
#include "Scheduler.h"
#include <unistd.h>

int		RunScheduler( void )
{
	Thread* back_ptr;

	while(1){
		if(ReadyQHead == NULL){
			sleep(2);
		}else {
			__thread_wakeup(ReadyQHead);
			 head_to_tail(&ReadyQHead, &ReadyQTail);
			__ContextSwitching();
		}
	}
}



void            __ContextSwitch(Thread pCurThread, Thread* pNewThread)
{

}

