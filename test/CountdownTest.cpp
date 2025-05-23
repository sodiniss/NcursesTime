
#include "gtest/gtest.h"
#include <thread>
#include <unistd.h>
#include "../Countdown.h"


TEST(CountdownTest, Costruttore) {
    Countdown c;
    EXPECT_EQ(c.getSeconds(), 0);
    EXPECT_FALSE(c.isRunning());
    EXPECT_FALSE(c.isComplete());
}


TEST(CountdownTest, AddTime) {
    Countdown c;
    c.addTime(10);
    EXPECT_EQ(c.getSeconds(), 10);

    c.addTime(-5);
    EXPECT_EQ(c.getSeconds(), 5);
    
    //qui devo avere un reset
    c.addTime(-10); 
    EXPECT_EQ(c.getSeconds(), 0);
}


TEST(CountdownTest, StartPause) {
    Countdown c;
    c.addTime(10);
    c.start();
    EXPECT_TRUE(c.isRunning());
    c.pause();
    EXPECT_FALSE(c.isRunning());
}


TEST(CountdownTest, Reset) {
    Countdown c;
    c.addTime(10);
    c.start();

    c.reset();
    EXPECT_EQ(c.getSeconds(), 0);
    EXPECT_FALSE(c.isRunning());
    EXPECT_FALSE(c.isComplete());
}

TEST(CountdownTest, UpdateTest) {
    Countdown c;
    c.addTime(10);
    c.start();

    auto lastUpdate = std::chrono::steady_clock::now();
    long elapsed = 0;
    while (elapsed <= 3) {
        c.refreshTime();
        auto now = std::chrono::steady_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - lastUpdate).count();
        usleep(50);
    }
    EXPECT_EQ(c.getSeconds(), 7);
}



TEST(CountdownTest, ToString) {
    Countdown c;
    c.addTime(1*3600+5*60+45); 

    EXPECT_EQ(c.secondsToString(), "01:05:45");
}
