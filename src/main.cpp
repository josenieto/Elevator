#include <iostream>
#include <thread>
#include "simulator.h"
#include "sensors.h"

int main(int, char**) 
{
    Motor motor;
    
    motor.setMovement(Movement::POSITIVE);
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    
    Control limit_control;
    FuncControl limit_ctrl(&motor, &limit_control);
    
    LimitSwitch sensor_positive(&limit_ctrl);
    LimitSwitch sensor_negative(&limit_ctrl);

    limit_ctrl.getControl()->add(&sensor_positive);
    limit_ctrl.getControl()->add(&sensor_negative);
    
    sensor_negative.setSignal(true);
    limit_ctrl.getControl()->notifyAll();

    std::cout << "Posicion: " << limit_ctrl.getMotor()->getPosition() << std::endl;

    Control floor_control;
    FuncControl floor_ctrl(&motor, &floor_control);

    FloorSwitch sensor_first_floor(&floor_ctrl);
    FloorSwitch sensor_second_floor(&floor_ctrl);
    FloorSwitch sensor_third_floor(&floor_ctrl);
    FloorSwitch sensor_fourth_floor(&floor_ctrl);
    FloorSwitch sensor_fifth_floor(&floor_ctrl);
    
    floor_ctrl.getControl()->add(&sensor_first_floor);
    floor_ctrl.getControl()->add(&sensor_second_floor);
    floor_ctrl.getControl()->add(&sensor_third_floor);
    floor_ctrl.getControl()->add(&sensor_fourth_floor);
    floor_ctrl.getControl()->add(&sensor_fifth_floor);

    sensor_second_floor.setSignal(true);
    floor_ctrl.getControl()->notifyAll();
}
