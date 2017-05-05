#ifndef MYFIFO_H_
#define MYFIFO_H_ value

#include	<sstream>
#include	<unistd.h>
#include	<string.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<stdlib.h>
#include	<fcntl.h>

class MyFifo
{
private:
	int			_read;
	int			_write;
	const char*	_fileWrite;
	const char*	_fileRead;

public:
	MyFifo(int);
	~MyFifo();

	int		getRead() const;
	int		getWrite() const;

	void	swap();
};

#endif