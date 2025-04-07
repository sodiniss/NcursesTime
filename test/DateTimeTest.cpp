
#include "gtest/gtest.h"
#include <unistd.h>
#include "../DateTime.h"


TEST(DateTimeTest, Costruttore) {
    DateTime dt;
    EXPECT_EQ(dt.getFormat(), getFormatEU());
}

TEST(DateTimeTest, CostruttorePieno) {
    
    DateTime dt(12,12,2025,22,30,10);
    EXPECT_EQ(dt.getFormat(), getFormatEU());
    EXPECT_EQ(dt.toString(),"12/12/2025, 22:30:10");
}

TEST(DateTimeTest, FormatTest) {
    DateTime dt(12,12,2025,22,30,10);
    dt.setFormatEU();
    EXPECT_EQ(dt.getFormat(), getFormatEU());
    EXPECT_EQ(dt.toString(),"12/12/2025, 22:30:10");

    dt.setFormatISO();
    EXPECT_EQ(dt.getFormat(), getFormatISO());
    EXPECT_EQ(dt.toString(),"2025/12/12, 22:30:10");

    dt.setFormatUSA();
    EXPECT_EQ(dt.getFormat(), getFormatUSA());
    EXPECT_EQ(dt.toString(),"12/12/2025, 10:30:10 PM");

}