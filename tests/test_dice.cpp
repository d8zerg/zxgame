#include <gtest/gtest.h>
#include "../src/dice.h"


TEST(DiceTest, RollTest) 
{
    int r = 0;
    for (int i = 0; i < 100; ++i)
    {    
        r = Dice::getInstance().roll();
        EXPECT_TRUE(r <= 20 && r >= 1);
    }    
}

