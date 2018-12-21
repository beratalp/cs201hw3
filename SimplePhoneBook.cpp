//
// Created by Alp Erbil on 2018-12-21.
//

#include "SimplePhoneBook.h"
#include <iostream>
#include <string>


using namespace std;

PhoneBook::PhoneBook() {
    head = NULL;
    numberOfPeople = 0;
}

PhoneBook::~PhoneBook() {
    while(!isEmpty()){
        removePerson(findPerson(head->t.getName())->t.getName());
    }
}

PhoneBook::PhoneBook(const PhoneBook &phoneBookToCopy) {
    numberOfPeople = phoneBookToCopy.numberOfPeople;
    if(phoneBookToCopy.head == NULL){
        head = NULL;
    }
    else{
        head = new PersonNode;
        head->t = phoneBookToCopy.head->t;
        PersonNode *person = head;
        for(PersonNode *orig = phoneBookToCopy.head->next; orig!= NULL; orig = orig->next){
            person->next = new PersonNode;
            person = person->next;
            person->t = orig->t;
        }
        person->next = NULL;
    }
}

void PhoneBook::operator=(const PhoneBook &right) {
    numberOfPeople = right.numberOfPeople;
    if(right.head == NULL){
        head = NULL;
    }
    else{
        head = new PersonNode;
        head->t = right.head->t;
        PersonNode *person = head;
        for(PersonNode *orig = right.head->next; orig!= NULL; orig = orig->next){
            person->next = new PersonNode;
            person = person->next;
            person->t = orig->t;
        }
        person->next = NULL;
    }
}

bool PhoneBook::addPerson(const string name) {
    string endString = "";
    for(int i = 0; i < name.length(); i++){
        char c = name[i];
        if(c <= 'Z' && c >= 'A')
            endString +=  c - ('Z' - 'z');
        else
            endString += c;
    }
    if(findPerson(endString) != NULL)
        return false;

    PersonNode *newNode = new PersonNode;
    Person newPerson = *new Person(name);
    newNode->t = newPerson;
    newNode->next = head;
    head = newNode;
    numberOfPeople++;
    return true;
}

bool PhoneBook::removePerson(const string name) {
    string endString = "";
    for(int i = 0; i < name.length(); i++){
        char c = name[i];
        if(c <= 'Z' && c >= 'A')
            endString +=  c - ('Z' - 'z');
        else
            endString += c;
    }
    if(findPerson(endString) != NULL)
        return false;
    PersonNode* temp = head;
    while(temp->next != NULL){
        if(temp->next->t.getName() == endString){
            delete temp->next;
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }
}

void PhoneBook::displayPeople() {
    if(isEmpty()){
        cout << "--EMPTY--";
    }
    else{
        PersonNode* temp = head;
        while(temp->next != NULL){
            cout << "Person " << temp->t.getName() << endl;
            temp = temp->next;
        }
    }
}

PersonNode* PhoneBook::findPerson(string name) {}
