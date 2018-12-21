//
// Created by Alp Erbil on 2018-12-20.
//

#include "SimplePerson.h"
#include <iostream>

using namespace std;

Person::Person(const string name) {
    this->name = name;
}

Person::~Person() {

}

Person::Person(const Person &personToCopy) {
    this->name = personToCopy.name;
}

void Person::operator=(const Person &right) {
    this->name = right.name;
}

string Person::getName() {
    return name;
}


