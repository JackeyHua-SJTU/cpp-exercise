#include "student.h"
#include <gtest/gtest.h>

namespace {

TEST(test_student, test_constructor) {
    student s(20, "John");
    EXPECT_EQ(s.get_age(), 20);
    EXPECT_EQ(s.get_name(), "John");
}
}
// int main(int argc, char **sargv) {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
