//
// Created by Alp Erbil on 2018-12-21.
//

#include "SimplePhoneBook.h"
#include "SimplePerson.h"
#include <iostream>
#include <string>


using namespace std;


PhoneBook::PhoneBook() {
    head = NULL;
    numberOfPeople = 0;
}

PhoneBook::~PhoneBook() {
    while(head != NULL){
        PersonNode *temp = head;
        head = head->next;
        delete temp;
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
    string endString1 = "";
    string endString2 = "";
    for(int i = 0; i < name.length(); i++){
        char c = name[i];
        if(c <= 'Z' && c >= 'A')
            endString1 +=  c - ('Z' - 'z');
        else
            endString1 += c;
    }

    for(int i = 0; i < name.length(); i++){
        char c = name[i];
        if(c <= 'z' && c >= 'a')
            endString2 +=  c + ('Z' - 'z');
        else
            endString2 += c;
    }
    if(findPerson(endString1) != NULL)
        return false;
    if(findPerson(endString2) != NULL)
        return false;
    if(head == NULL){
        PersonNode *newNode = new PersonNode;
        Person newPerson = *new Person(name);
        newNode->t = newPerson;
        numberOfPeople++;
        head = newNode;
        head->next = NULL;
        return true;
    }
    PersonNode *newNode = new PersonNode;
    Person newPerson = *new Person(name);
    newNode->t = newPerson;
    newNode->next = head;
    head = newNode;
    numberOfPeople++;
    return true;
}


bool PhoneBook::removePerson(const string name) {
    PersonNode* temp = head;
    PersonNode* cur = head->next;
    while(cur != NULL) {
        if(cur->t.getName() == name) {
            temp->next = cur->next;
            numberOfPeople--;
            return true;
        }
        else {
            temp = cur;
            cur = cur->next;
        }
    }
    return false;
}


void PhoneBook::displayPeople() {
    if(numberOfPeople == 0){
        cout << "--EMPTY--" << endl;
    }
    else{
        PersonNode* temp = head;
        while(temp != NULL) {
            cout << "Person " << temp->t.getName() << endl;
            temp = temp->next;
        }
    }
}

PhoneBook::PersonNode* PhoneBook::findPerson(string name) {
    if(head == NULL)
        return NULL;
    PersonNode* temp = head;
    while(temp != NULL){
        if(name == temp->t.getName())
            return temp;
        temp = temp->next;
    }
    return NULL;
}



