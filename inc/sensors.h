#include <vector>
#include <algorithm>

#include "simulator.h"

class ISensor
{
public:
    virtual void update() = 0;
    virtual ~ISensor(){};
};

class IControl
{
private:
    std::vector<ISensor *> sensors;
public:
    virtual void notifyAll() = 0;
    virtual void add(ISensor *is) = 0;
    virtual void remove(ISensor *is) = 0;
    std::vector<ISensor *> *getSensors(){return &sensors;};
    virtual ~IControl(){};
};



class Control: public IControl
{
private:
    bool positive_switch = false;
    bool negative_switch = false;
    Motor *motor;

public:
    void notifyAll() override;
    void add(ISensor *is) override;
    void remove(ISensor *is) override;
    bool getPosive_switch();
    bool getNegative_switch();
    void setPositive_switch(bool val);
    void setNegative_switch(bool val);
    Motor *getMotor(){return motor;}
    Control(Motor *motor_):motor(motor_){};
    virtual ~Control(){};
};

class LimitSwitchPos: public ISensor
{
private:
    Control *control;
public:
    void update() override;
    LimitSwitchPos(Control *control_):control(control_){};
    virtual ~LimitSwitchPos(){};
};

class LimitSwitchNeg: public ISensor
{
private:
    Control *control;
public:
    void update() override;
    LimitSwitchNeg(Control *control_):control(control_){};
    virtual ~LimitSwitchNeg(){};
};

