#include "sensors.h"
#include <algorithm>
#include <iostream>
/*
 *       Control Switches
 */

void Control::add(ISensor *is)
{
    auto sensors_ = this->getSensors();
    sensors_->push_back(is);
};

void Control::remove(ISensor *is)
{
    auto sensors_ = this->getSensors();
    auto it = std::remove_if(sensors_->begin(), sensors_->end(), [&](ISensor *i){
      return i == is;
    });
    sensors_->erase(it,sensors_->end());
};

void Control::notifyAll()  
{
    auto sensors_ = this->getSensors();
    for(auto it=sensors_->begin(); it != sensors_->end(); it++)
    {
      (*it)->update();
    }
};

/*
 *       Limit Switches
 */
void LimitSwitch::update()
{
    if(this->getSignal())
    {
        this->control->getMotor()->setStart(false);
        std::cout << "Limite Actuado" << std::endl;
    }
};

/*
 *        Floor Switches
 */

void FloorSwitch::update()
{
    if(this->getSignal())
        std::cout << "Ha pasado por el piso X" << std::endl;
};


