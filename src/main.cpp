#include <iostream>
#include <thread>
#include "simulator.h"
#include "sensors.h"

int main(int, char**) {

    Motor motor;
    
    motor.setMovement(Movement::POSITIVE);
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    
    Control ctrl(&motor);
    LimitSwitchPos sensor_positive(&ctrl);
    LimitSwitchNeg sensor_negative(&ctrl);

    ctrl.add(&sensor_positive);
    ctrl.add(&sensor_negative);
    
    ctrl.setPositive_switch(true);
    ctrl.notifyAll();

    std::cout << "Posicion: " << ctrl.getMotor()->getPosition() << std::endl;
}


