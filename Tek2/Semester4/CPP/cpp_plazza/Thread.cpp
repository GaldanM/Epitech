#include "Thread.h"
#include <stdio.h>

Thread::Thread(void *(*fnc)(void *), void *obj)
{
  pthread_create(&_thread, NULL, fnc, obj);
  pthread_cond_init(&_cond, NULL);
  pthread_mutex_init(&_mutex, NULL);
}

Thread::~Thread()
{
  pthread_cond_destroy(&_cond);
  pthread_mutex_destroy(&_mutex);
  pthread_exit(&_thread);
}

void 				Thread::join()
{
  pthread_join(_thread, NULL);
}

void 				Thread::wait()
{
  pthread_mutex_lock(&_mutex);
  pthread_cond_wait(&_cond, &_mutex);
  pthread_mutex_unlock(&_mutex);
}

void				Thread::signal()
{
  pthread_cond_signal(&_cond);
}

pthread_cond_t 		Thread::getCond() const
{
  return (_cond);
}
