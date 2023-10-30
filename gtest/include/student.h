#ifndef GTEST_STUDENT_H
#define GTEST_STUDENT_H

#include <string>

class student {
private:
    int age;
    std::string name;

public:
    student() = default;
    student(int age, std::string name);
    int get_age() const;
    std::string get_name() const;
    void change_name(std::string name);
};

#endif //GTEST_STUDENT_H
