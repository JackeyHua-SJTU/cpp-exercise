#include "student.h"
#include <gtest/gtest.h>

// fixture 的结构是为了方便多个测试案例有相同的初始化配置
// SetUp() and TearDown() are called for EACH TEST_F() test case
// equivalent to constructor and destructor

namespace {
class studentTest : public testing::Test {
protected:

    void SetUp() override {
        s1 = student(20, "John");
        s2 = student(21, "Jacky");
        s3 = student(22, "Joseph");
    }

    student s1, s2, s3;

};

TEST_F(studentTest, test_constructor) {
    EXPECT_EQ(s1.get_age(), 20);
    EXPECT_EQ(s1.get_name(), "John");
    EXPECT_EQ(s2.get_age(), 21);
    EXPECT_EQ(s2.get_name(), "Jacky");
    EXPECT_EQ(s3.get_age(), 22);
    EXPECT_EQ(s3.get_name(), "Joseph");
}

TEST_F(studentTest, test_change_name) {
    EXPECT_EQ(s1.get_name(), "John");
    s1.change_name("Johny");
    EXPECT_EQ(s1.get_name(), "Johny");
    s2.change_name("Jack");
    EXPECT_EQ(s2.get_name(), "Jack");
    s3.change_name("Joe");
    EXPECT_EQ(s3.get_name(), "Joe");
}

// TEST(test_student, test_constructor) {
//     student s(20, "John");
//     EXPECT_EQ(s.get_age(), 20);
//     EXPECT_EQ(s.get_name(), "John");
// }
}
// int main(int argc, char** argv) {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }