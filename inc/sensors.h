#include <vector>
#include <map>
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
public:
    virtual void add(ISensor *is) = 0;
    virtual void remove(ISensor *is) = 0;
    virtual void notifyAll() = 0;
    virtual ~IControl(){};
};

class Control: public IControl
{
private:
    std::vector<ISensor *> sensors;

public:
    void notifyAll() override;
    void add(ISensor *is) override;
    void remove(ISensor *is) override;
    std::vector<ISensor *> *getSensors(){return &sensors;};
    virtual ~Control(){};
};

class FuncControl
{
private:
    Motor *motor;
    Control *control;

public:
    Motor *getMotor(){return motor;}
    Control *getControl(){return control;}
    FuncControl(Motor *motor_, Control *control_):motor(motor_),control(control_){};
    virtual ~FuncControl(){};
};

class LimitSwitch: public ISensor
{
private:
    FuncControl *control;
    bool signal = false;
public:
    void update() override;
    void setSignal(bool val){this->signal = val;};
    bool getSignal(){return signal;};
    LimitSwitch(FuncControl *control_):control(control_){};
    virtual ~LimitSwitch(){};
};

class FloorSwitch: public ISensor
{
private:
    FuncControl *control;
    bool signal = false;
public:
    void update() override;
    void setSignal(bool val){this->signal = val;};
    bool getSignal(){return signal;};
    FloorSwitch(FuncControl *control_):control(control_){};
    virtual ~FloorSwitch(){};
};
