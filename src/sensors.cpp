#include "sensors.h"
#include <algorithm>
#include <iostream>

void LimitSwitchPos::update()
{
    if(this->control->getPosive_switch() &&
       this->control->getMotor()->getMovement() == Movement::POSITIVE )
    {
        this->control->getMotor()->setStart(false);
        std::cout << "Limite Positivo Actuado" << std::endl;
    }
};

void LimitSwitchNeg::update()
{
    if(this->control->getNegative_switch()  &&
       this->control->getMotor()->getMovement() == Movement::NEGATIVE)
    {
        this->control->getMotor()->setStart(false);
        std::cout << "Limite Negativo Actuado" << std::endl;
    }
};

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

bool Control::getPosive_switch()
{
    return positive_switch;
}

bool Control::getNegative_switch()
{
    return negative_switch;
}

void Control::setPositive_switch(bool val)
{
    this->positive_switch = val;
}
void Control::setNegative_switch(bool val)
{
    this->negative_switch = val;
};