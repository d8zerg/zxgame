#include <gtest/gtest.h>
#include "../src/dice.h"


TEST(DiceTest, RollTest) 
{
    EXPECT_FALSE(Dice::getInstance().roll() == Dice::getInstance().roll());
}

