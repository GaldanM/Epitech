
#ifndef COOK_H_
#define COOK_H_

#include <list>
#include <fstream>
#include "IMutex.h"
#include "Thread.h"
#include "Pizza.hpp"

typedef enum Status
	{
		WAITING,
		BUSY,
		FINISHED
	}			Status;
	
class Cook
{

	private:
		Status			_stat;
		Thread 			*_th;
		Pizza			*_toDo;
		std::ofstream   _pipe;
	public:
		Cook(void *(*fnc)(void *));
		~Cook();

		void			startCook();
		void			signalPizza();
		Status			getStatus() const;
		void			setStatus(Status);
		void			setPizza(Pizza *pizza);
};

#endif /* !COOK_H_ */
