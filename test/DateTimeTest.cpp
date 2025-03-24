
#include "gtest/gtest.h"
#include <unistd.h>
#include "../DateTime.h"


TEST(DateTimeTest, Costruttore) {
    DateTime dt;
    EXPECT_EQ(dt.getFormat(), getFormatEU());
}

TEST(DateTimeTest, CostruttorePieno) {
    
    DateTime dt(12,44,2025,21,30,10);
    EXPECT_EQ(dt.getFormat(), getFormatEU());
    EXPECT_EQ(dt.print(),"12/44/2025, 22:30:10");
}
