// CS111Project5-Daggs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include <fstream>

#include "BoatStruct.h"

//preconditions: --
//postconditions: writes content of Linked List of Structs in the following order: boatname, 
//                ownerName, size
void printBoatData(BoatStructPtr &head);

//preconditions:  a Struct pointer head has been declared and initialized
//postconditions: A linked List of Structs is created with data from data.tx. 
//                File format is: owner name, boat size, boat name
//Notes: assumes a single string for owner name or boat name. Woods 320 Privacy is valid,
//       Tiger Woods 320 Privacy is not valid (line has three strings)
//       all file operations--opening, checking, reading, closing--must occur in readData(...)
//       It is possible that size may be one more than the number of data lines depending on
//       how the EOF character is represented.
void readData(BoatStructPtr& head);

//preconditions:  Linked List of Structs has valid data
//postconditions: prints data associated with target (boat owner); 
//                if not found, print Owner target not found
void findDataByOwnerName(BoatStructPtr& head, std::string target);

void headInsert(BoatStructPtr& head, BoatStructPtr& newItem);
void deleteList(BoatStructPtr& head); //delete all elements on the list; h points to NULL


int main(void)
{
    BoatStructPtr head = NULL;
    readData(head);
    if (head != NULL) { //added so that it doesnt try to print if list file is empty
        printBoatData(head);
    }
    std::string target;
    if (head !=NULL) { // it wont ask for target if list is empty
        std::cout << "Enter name of owner: ";
        std::cin >> target;
        findDataByOwnerName(head, target);
    }
    std::cout << std::endl;

    if (head != NULL) { //added so that it wont try to print if list is empty
        deleteList(head);
        printBoatData(head);
    }
}


void readData(BoatStructPtr& head){
    std::ifstream inFile;

    inFile.open("Data.txt");
    if (inFile.fail()) {
        std::cout << "Couldnt open data file\n";
        return;
    }

    inFile.seekg(0, std::ios::end); //to check if file is empty or not and be able to read a message that says the file is empty ... seeks from first line to end..
    int spot = inFile.tellg(); //tells position in file after it has been moved to the end of stream
    if (spot == 0) //==0 means there was nothing in file
    {
        std::cout << "File is Empty\n";
    }
    inFile.clear(); //so that I can still interact with the inFile stream 
    inFile.seekg(0); //Sets it back to first line in the file so it can be read for input to the list

    std::string name = " ";
    std::string boatName = " ";
    int boatSize = -1;

    while (inFile >> name && !inFile.eof()) {
        inFile >> boatSize;
        inFile >> boatName;
        BoatStructPtr t = new BoatStruct(name, boatName, boatSize);
        headInsert(head, t);
    }

    inFile.close();   
}

void findDataByOwnerName(BoatStructPtr& head, std::string target) {
    BoatStructPtr itr = head;
    while (itr != NULL) {
        if (itr->boatOwnerName == target) {
            itr->print();
            return;
        }
        itr = itr->next;
    }
    std::cout << "\nOwner's name not found." << std::endl;
}

void printBoatData(BoatStructPtr& head) {
    if (head == NULL) {
        std::cout << "Unable to print . . . List is empty or has been deleted." << std::endl;
    }
    for (BoatStructPtr itr = head; itr != NULL; itr = itr->next) { 
        itr->print();								   
    } 
}

void headInsert(BoatStructPtr& head, BoatStructPtr& newItem) {
    newItem->next = head;
    head = newItem;
    newItem = NULL;
}

void deleteList(BoatStructPtr& head) {
    if (head == NULL) {
        return;
    }
    for (; head != NULL; ) {
        BoatStructPtr t = head; 
        head = head->next; 
        t->next = NULL; 
        delete t;
    }
}
