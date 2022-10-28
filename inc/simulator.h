#pragma once

#include <stdint.h>
#include <thread>
#include <atomic>

enum class Movement{POSITIVE,NEGATIVE,STOPPED};

class Motor
{
private:
    int32_t position;
    bool start = true;
    Movement movement = Movement::STOPPED;
    std::thread t1;

public:
    void run();
    int32_t getPosition();
    Movement getMovement();
    void setMovement(Movement movement_);
    void setStart(bool start_);
    Motor()
    {
        t1 = std::thread(&Motor::run,this);
    }
    ~Motor()
    {
        if(t1.joinable())
            t1.join();
    }
    
};
