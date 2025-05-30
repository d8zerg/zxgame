add_executable(tests 
    test_dice.cpp)

target_link_libraries(tests
    GTest::GTest
    GTest::Main
    Threads::Threads
)

enable_testing()
add_test(NAME DiceTests COMMAND tests)