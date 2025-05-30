#ifndef DICE_H
#define DICE_H

#include <random>
#include <mutex>
#include <utility>


class Dice 
{
public:
    Dice(const Dice&) = delete;
    Dice& operator=(const Dice&) = delete;

    static Dice& getInstance() 
    {
        static Dice instance;
        return instance;
    }
    
    [[nodiscard]] int roll(int sides = 20) 
    {
        std::lock_guard lock(mutex_);
        if (sides == 20) 
        {
            return d20_(generator_);
        }
        return std::uniform_int_distribution<>{1, sides}(generator_);
    }

private:
    Dice() : generator_(rd_()), d20_(1, 20) {}

    std::random_device rd_;
    std::mt19937 generator_;
    std::uniform_int_distribution<> d20_;
    std::mutex mutex_;
};

#endif // DICE_H