
#include "IMutex.h"

IMutex::IMutex()
{
	pthread_mutex_init(&_IMutex, NULL);
}

IMutex::~IMutex() {}

pthread_mutex_t 	IMutex::getMutex() const
{
	return (_IMutex);
}

void 	IMutex::lock(void)
{
	pthread_mutex_lock(&_IMutex);
}

void 	IMutex::unlock(void)
{
	pthread_mutex_unlock(&_IMutex);
}

void	IMutex::trylock(void)
{
  pthread_mutex_trylock(&_IMutex);
}
