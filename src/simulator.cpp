#include <stdint.h>
#include <thread>
#include <iostream>

#include "simulator.h"

void Motor::run()
{
    while(this->start)
    {
        if (this->movement == Movement::POSITIVE)
            this->position++;
        else if (this->movement == Movement::NEGATIVE)
            this->position--;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

int32_t Motor::getPosition()
{
    return this->position;
};

Movement Motor::getMovement()
{
    return this->movement;
};

void Motor::setMovement(Movement movement_)
{
    this->movement = movement_;
};

void Motor::setStart(bool start_)
{
    this->start = start_;
}
