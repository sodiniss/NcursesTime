
#include "gtest/gtest.h"
#include <unistd.h>
#include "../DateTime.h"


TEST(DateTimeTest, Costruttore) {
    DateTime dt;
    EXPECT_EQ(dt.getFormat(), getFormatEU());
}

TEST(DateTimeTest, CostruttorePieno) {
    
    DateTime dt(13,12,2025,22,30,10);
    EXPECT_EQ(dt.getFormat(), getFormatEU());
    EXPECT_EQ(dt.toString(),"13/12/2025, 22:30:10");
}

TEST(DateTimeTest, FormatTest) {
    DateTime dt(13,12,2025,22,30,10);
    dt.setFormatEU();
    EXPECT_EQ(dt.getFormat(), getFormatEU());
    EXPECT_EQ(dt.toString(),"13/12/2025, 22:30:10");

    dt.setFormatISO();
    EXPECT_EQ(dt.getFormat(), getFormatISO());
    EXPECT_EQ(dt.toString(),"2025/12/13, 22:30:10");

    dt.setFormatUSA();
    EXPECT_EQ(dt.getFormat(), getFormatUSA());
    EXPECT_EQ(dt.toString(),"12/13/2025, 10:30:10 PM");

}

TEST(DateTimeTest, DataNonValida) {
    EXPECT_THROW(DateTime dt(311, 2, 2025, 12, 0, 0), std::invalid_argument);
}