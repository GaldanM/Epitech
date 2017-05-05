#include	"MyFifo.h"

MyFifo::MyFifo(int id)
{
	std::string			read("fifo_read");
	std::string			write("fifo_open");
	std::ostringstream	oss;

	oss << id;
	read += oss.str();
	write += oss.str();
	_fileWrite = write.c_str();
	_fileRead = read.c_str();
	mkfifo(_fileWrite, 0666);
	mkfifo(_fileRead, 0666);
	_write = open(_fileWrite, 0666);
	_read = open(_fileRead, 0666);
}

MyFifo::~MyFifo()
{
	unlink(_fileRead);
	unlink(_fileWrite);
}

void		MyFifo::swap()
{
	int		save;

	save = _read;
	_read = _write;
	_write = save;
}

int			MyFifo::getRead() const
{
	return _read;
}

int			MyFifo::getWrite() const
{
	return _write;
}