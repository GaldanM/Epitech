
#ifndef WATER_RECLAIMER_HPP_
#define WATER_RECLAIMER_HPP_

#include <cstddef>
#include "BaseComponent.hpp"

class WaterReclaimer : public BaseComponent
{
    public:
        WaterReclaimer();
        virtual ~WaterReclaimer() {}

        void start() throw(MissionCriticalError);
        void generateWater();
        void useWater(int water);

    private:
        int     _water;
        bool    _started;
        int     _count;
};

#endif // WATER_RECLAIMER_HPP_
