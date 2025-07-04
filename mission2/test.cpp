#include "func.h"
#include "gtest/gtest.h"


TEST(ValidationTest, SEDANTEST)
{
	Sedan* car = new Sedan;
	car->setEngine(GM);
	car->setBrake(MANDO);
	car->setSteering(BOSCH_S);
	car->run();
	car->test();
	EXPECT_FALSE(car->isValid());

	car->setEngine(GM);
	car->setBrake(CONTINENTAL);
	car->setSteering(BOSCH_S);
	car->run();
	car->test();
	EXPECT_FALSE(car->isValid());

	car->setEngine(TOYOTA);
	car->setBrake(BOSCH_S);
	car->setSteering(BOSCH_S);
	car->run();
	car->test();
	EXPECT_TRUE(car->isValid());
	
	
}

TEST(ValidationTest, SUVTEST)
{
	Suv * car = new Suv;
	car->setEngine(GM);
	car->setBrake(MANDO);
	car->setSteering(BOSCH_S);
	car->run();
	car->test();
	EXPECT_FALSE(car->isValid());

	car->setEngine(TOYOTA);
	car->setBrake(CONTINENTAL);
	car->setSteering(BOSCH_S);
	car->run();
	car->test();
	EXPECT_FALSE(car->isValid());

	car->setEngine(GM);
	car->setBrake(BOSCH_S);
	car->setSteering(BOSCH_S);
	car->run();
	car->test();
	EXPECT_TRUE(car->isValid());


}


TEST(ValidationTest, TRUCKTEST)
{
	Suv* car = new Suv;
	car->setEngine(GM);
	car->setBrake(MANDO);
	car->setSteering(BOSCH_S);
	car->run();
	car->test();
	EXPECT_FALSE(car->isValid());

	car->setEngine(TOYOTA);
	car->setBrake(CONTINENTAL);
	car->setSteering(BOSCH_S);
	car->run();
	car->test();
	EXPECT_FALSE(car->isValid());

	car->setEngine(GM);
	car->setBrake(BOSCH_S);
	car->setSteering(BOSCH_S);
	car->run();
	car->test();
	EXPECT_TRUE(car->isValid());


}
