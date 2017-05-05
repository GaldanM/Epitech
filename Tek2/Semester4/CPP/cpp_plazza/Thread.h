
#ifndef THREAD_H_
#define THREAD_H_

#include 	<pthread.h>
#include 	<iostream>
#include	"Pizza.hpp"

class Thread
{
private:
	pthread_t 			_thread;
	pthread_mutex_t 	_mutex;
	pthread_cond_t 		_cond;

public:
	Thread(void *(*)(void *), void *);
	~Thread();

	void 				join();
	void 				wait();
	void 				signal();

	pthread_cond_t 		getCond() const;

};

#endif /* !THREAD_H_  */
