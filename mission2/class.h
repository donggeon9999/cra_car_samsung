#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define CLEAR_SCREEN "\033[H\033[2J"


#define EXIT_FLAG -1
#define NONUM_FLAG -2

using namespace std;


int stack[10];

void selectCarType(int answer);
void selectEngine(int answer);
void selectbrakeSystem(int answer);
void selectSteeringSystem(int answer);
void runProducedCar();
void testProducedCar();
void delay(int ms);

enum QuestionType
{
    CarType_Q,
    Engine_Q,
    brakeSystem_Q,
    SteeringSystem_Q,
    Run_Test,
};

enum CarType
{
    SEDAN = 1,
    SUV,
    TRUCK
};
enum ComponentType
{
    ENGINE = 1,
    BRAKE,
    STEERING
};
enum Engine
{
    GM = 1,
    TOYOTA,
    WIA
};

enum brakeSystem
{
    MANDO = 1,
    CONTINENTAL,
    BOSCH_B
};

enum SteeringSystem
{
    BOSCH_S = 1,
    MOBIS
};

class CarComponent {
private:
    int manufact;

public:
    int comp;

    int getManufact() {
        return this->manufact;
    }
    void setManufact(int manufact) {
        this->manufact = manufact;
    }
};
class CarEngine : public CarComponent {
public:
    CarEngine() {
        this->comp = ENGINE;
    }

};

class CarBrake : public CarComponent {
public:
    CarBrake() {
        this->comp = BRAKE;
    }

};
class CarSteering : public CarComponent {
public:
    CarSteering() {
        this->comp = STEERING;
    }

};


class Car {
public:

    int carType;
    CarComponent* carEngine;
    CarComponent* carBrake;
    CarComponent* carSteering;

    Car() {
        carEngine = new CarEngine;
        carBrake = new CarBrake;
        carSteering = new CarSteering;
    }
    ~Car() {
        delete carEngine;
        delete carBrake;
        delete carSteering;
    }
    void setType(int type) {
        this->carType = type;
    }
    void setEngine(int type)
    {
        this->carEngine->setManufact(type);
        return;
    }
    void setBrake(int type)
    {
        this->carBrake->setManufact(type);
        return;
    }
    void setSteering(int type)
    {
        this->carSteering->setManufact(type);
        return;
    }

    virtual void run() {}
    virtual void test() {}

};

class Sedan : public Car {
public:

    Sedan() {
        printf("차량 타입으로 Sedan을 선택하셨습니다.\n");
        this->setType(SEDAN);
    }

    bool isValid()
    {
        if (this->carBrake->getManufact() == CONTINENTAL)
        {
            return false;
        }
        if (stack[brakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
        {
            return false;
        }
        return true;
    }

    void run() {

        int type, engine, brake, steering;

        type = this->carType;
        engine = this->carEngine->getManufact();
        brake = this->carBrake->getManufact();
        steering = this->carSteering->getManufact();


        if (this->isValid() == false)
        {
            printf("자동차가 동작되지 않습니다\n");
        }
        else
        {
            if (engine == 4)
            {
                printf("엔진이 고장나있습니다.\n");
                printf("자동차가 움직이지 않습니다.\n");
            }
            else
            {
                printf("Car Type : Sedan\n");

                if (engine == 1)
                    printf("Engine : GM\n");
                if (engine == 2)
                    printf("Engine : TOYOTA\n");
                if (engine == 3)
                    printf("Engine : WIA\n");
                if (brake == 1)
                    printf("Brake System : Mando");
                if (brake == 2)
                    printf("Brake System : Continental\n");
                if (brake == 3)
                    printf("Brake System : Bosch\n");
                if (steering == 1)
                    printf("SteeringSystem : Bosch\n");
                if (steering == 2)
                    printf("SteeringSystem : Mobis\n");

                printf("자동차가 동작됩니다.\n");
            }
        }
    }

    void test() {
        int type, engine, brake, steering;

        type = this->carType;
        engine = this->carEngine->getManufact();
        brake = this->carBrake->getManufact();
        steering = this->carSteering->getManufact();

        if (brake == CONTINENTAL)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Sedan에는 Continental제동장치 사용 불가\n");
        }
        if (stack[brakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
        {
            return false;
        }
        else
        {
            printf("자동차 부품 조합 테스트 결과 : PASS\n");
        }
    }
};

class Suv : public Car {
public:

    Suv() {
        printf("차량 타입으로 SUV을 선택하셨습니다.\n");
        this->setType(SUV);
    }

    bool isValid()
    {
        if (this->carEngine->getManufact() == TOYOTA)
        {
            return false;
        }
        if (stack[brakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
        {
            return false;
        }
        return true;
       
    }

    void run() {

        int type, engine, brake, steering;

        type = this->carType;
        engine = this->carEngine->getManufact();
        brake = this->carBrake->getManufact();
        steering = this->carSteering->getManufact();


        if (this->isValid() == false)
        {
            printf("자동차가 동작되지 않습니다\n");
        }
        else
        {
            if (engine == 4)
            {
                printf("엔진이 고장나있습니다.\n");
                printf("자동차가 움직이지 않습니다.\n");
            }
            else
            {
                printf("Car Type : SUV\n");

                if (engine == 1)
                    printf("Engine : GM\n");
                if (engine == 2)
                    printf("Engine : TOYOTA\n");
                if (engine == 3)
                    printf("Engine : WIA\n");
                if (brake == 1)
                    printf("Brake System : Mando");
                if (brake == 2)
                    printf("Brake System : Continental\n");
                if (brake == 3)
                    printf("Brake System : Bosch\n");
                if (steering == 1)
                    printf("SteeringSystem : Bosch\n");
                if (steering == 2)
                    printf("SteeringSystem : Mobis\n");

                printf("자동차가 동작됩니다.\n");
            }
        }
    }
    void test() {
        int type, engine, brake, steering;

        type = this->carType;
        engine = this->carEngine->getManufact();
        brake = this->carBrake->getManufact();
        steering = this->carSteering->getManufact();

        if (engine == TOYOTA)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("SUV에는 TOYOTA엔진 사용 불가\n");
        }
        else if (brake == BOSCH_B && steering != BOSCH_S)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
        }
        else
        {
            printf("자동차 부품 조합 테스트 결과 : PASS\n");
        }
    }
    /* void call() override {
         std::cout << "@#!!@#" << std::endl;
     }*/
};

class Truck : public Car {

public:

    Truck() {
        printf("차량 타입으로 Truck을 선택하셨습니다.\n");
        this->setType(TRUCK);
    }
    bool isValid()
    {
        int type, engine, brake, steering;

        type = this->carType;
        engine = this->carEngine->getManufact();
        brake = this->carBrake->getManufact();
        steering = this->carSteering->getManufact();
        
        if (engine == WIA)
        {
            return false;
        }
        else if (brake == MANDO)
        {
            return false;
        }
        else if (type == BOSCH_B && steering != BOSCH_S)
        {
            return false;
        }
     
        return true;
    }

    void run() {

        int type, engine, brake, steering;

        type = this->carType;
        engine = this->carEngine->getManufact();
        brake = this->carBrake->getManufact();
        steering = this->carSteering->getManufact();


        if (this->isValid() == false)
        {
            printf("자동차가 동작되지 않습니다\n");
        }
        else
        {
            if (engine == 4)
            {
                printf("엔진이 고장나있습니다.\n");
                printf("자동차가 움직이지 않습니다.\n");
            }
            else
            {
                printf("Car Type : Truck\n");

                if (engine == 1)
                    printf("Engine : GM\n");
                if (engine == 2)
                    printf("Engine : TOYOTA\n");
                if (engine == 3)
                    printf("Engine : WIA\n");
                if (brake == 1)
                    printf("Brake System : Mando");
                if (brake == 2)
                    printf("Brake System : Continental\n");
                if (brake == 3)
                    printf("Brake System : Bosch\n");
                if (steering == 1)
                    printf("SteeringSystem : Bosch\n");
                if (steering == 2)
                    printf("SteeringSystem : Mobis\n");

                printf("자동차가 동작됩니다.\n");
            }
        }
    }
    void test() {

        int type, engine, brake, steering;

        type = this->carType;
        engine = this->carEngine->getManufact();
        brake = this->carBrake->getManufact();
        steering = this->carSteering->getManufact();

        if (engine == WIA)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Truck에는 WIA엔진 사용 불가\n");
        }
        else if (brake == MANDO)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Truck에는 Mando제동장치 사용 불가\n");
        }
        else if (brake == BOSCH_B && steering != BOSCH_S)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
        }
        else
        {
            printf("자동차 부품 조합 테스트 결과 : PASS\n");
        }
    }
};

