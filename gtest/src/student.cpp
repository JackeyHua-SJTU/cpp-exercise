#include "student.h"

student::student(int age, std::string name) : age(age), name(std::move(name)) {}

int student::get_age() const {return this->age;}

std::string student::get_name() const {return this->name;}

void student::change_name(std::string n) {this->name = std::move(n);}