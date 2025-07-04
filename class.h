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

    virtual bool isValid() { return true; }
    virtual void run() {}
    virtual void test() {}

};

class Sedan : public Car {
public:

    Sedan() {
        printf("���� Ÿ������ Sedan�� �����ϼ̽��ϴ�.\n");
        this->setType(SEDAN);
    }

    bool isValid()
    {
        if (this->carBrake->getManufact() == CONTINENTAL)
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
            printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
        }
        else
        {
            if (engine == 4)
            {
                printf("������ ���峪�ֽ��ϴ�.\n");
                printf("�ڵ����� �������� �ʽ��ϴ�.\n");
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

                printf("�ڵ����� ���۵˴ϴ�.\n");
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
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Sedan���� Continental������ġ ��� �Ұ�\n");
        }
        else
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
        }
    }
};

class Suv : public Car {
public:

    Suv() {
        printf("���� Ÿ������ SUV�� �����ϼ̽��ϴ�.\n");
        this->setType(SUV);
    }

    bool isValid()
    {
        if (this->carEngine->getManufact() == TOYOTA)
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
            printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
        }
        else
        {
            if (engine == 4)
            {
                printf("������ ���峪�ֽ��ϴ�.\n");
                printf("�ڵ����� �������� �ʽ��ϴ�.\n");
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

                printf("�ڵ����� ���۵˴ϴ�.\n");
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
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("SUV���� TOYOTA���� ��� �Ұ�\n");
        }
        else if (brake == BOSCH_B && steering != BOSCH_S)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
        }
        else
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
        }
    }
    /* void call() override {
         std::cout << "@#!!@#" << std::endl;
     }*/
};

class Truck : public Car {

public:

    Truck() {
        printf("���� Ÿ������ Truck�� �����ϼ̽��ϴ�.\n");
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
            printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
        }
        else
        {
            if (engine == 4)
            {
                printf("������ ���峪�ֽ��ϴ�.\n");
                printf("�ڵ����� �������� �ʽ��ϴ�.\n");
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

                printf("�ڵ����� ���۵˴ϴ�.\n");
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
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Truck���� WIA���� ��� �Ұ�\n");
        }
        else if (brake == MANDO)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Truck���� Mando������ġ ��� �Ұ�\n");
        }
        else if (brake == BOSCH_B && steering != BOSCH_S)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
        }
        else
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
        }
    }
};

