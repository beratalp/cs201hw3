#include <iostream>
#include <string>
#include "SimplePerson.h"
#include "SimplePhoneBook.h"

using namespace std;


int main() {
    PhoneBook phoneBook = *new PhoneBook();
    phoneBook.addPerson("asd");
    phoneBook.addPerson("dfg");
    phoneBook.addPerson("bfg");
    phoneBook.displayPeople();
    cout << "---" << endl;
    phoneBook.removePerson("asd");
    phoneBook.removePerson("jkl");
    phoneBook.displayPeople();
    cout << "---" << endl;
    phoneBook.addPerson("ASD");
    phoneBook.addPerson("asd");
    phoneBook.displayPeople();
    PhoneBook phoneBook2 = phoneBook;
    cout << "---" << endl;
    phoneBook2.displayPeople();
    PhoneBook phoneBook3 = *new PhoneBook(phoneBook2);
    cout << "---" << endl;
    phoneBook3.displayPeople();
    return 0;
}


