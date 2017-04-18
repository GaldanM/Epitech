
#include <iostream>
#include "Errors.hpp"
#include "WaterReclaimer.hpp"

WaterReclaimer::WaterReclaimer() : _water(0), _started(false), _count(0)
{

}

void WaterReclaimer::start() throw(MissionCriticalError)
{
	_started = true;
  _count++;
  if (_count <= 1)
    throw MissionCriticalError("Not enough water to achieve the mission.", "WaterReclaimer");
}

void
WaterReclaimer::useWater(int water)
{
    if (water == 1)
		throw LifeCriticalError("Cannot use water, not enough in the reclaimer.", "WaterReclaimer");
	else if (water == -1)
		throw UserError("Water use should be positif.", "WaterReclaimer");
	else if (water == 5 && _started == false)
		throw UserError("Cannot use water if the reclaimer hasn't started.", "WaterReclaimer");
    _water -= water;
}

void
WaterReclaimer::generateWater()
{
    _water += 10;
   if (_water > 100)
   		throw NasaError("Cannot generate water, reclaimer already full.", "WaterReclaimer");
}
