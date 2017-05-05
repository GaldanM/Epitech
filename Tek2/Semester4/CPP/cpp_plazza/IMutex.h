
#ifndef _IMutex_H_
#define _IMutex_H_

#include <pthread.h>
#include <iostream>

class IMutex
{
public:
	pthread_mutex_t 	_IMutex;
public:
	IMutex();
	~IMutex();
	void 		lock(void);
	void 		unlock(void);
	void		trylock(void);

public:
	pthread_mutex_t 	getMutex() const;
};

#endif /* !_IMutex_H_ */
