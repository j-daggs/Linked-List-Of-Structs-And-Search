#ifndef BoatStruct_h
#define Boatstruct_h

#include <iostream>
#include <string>
#include <fstream>

struct BoatStruct {
    std::string boatOwnerName;
    std::string boatName;
    double boatSize;
    BoatStruct* next;
    BoatStruct();
    BoatStruct(std::string oName, std::string boatName, double size);
    void print();
};

typedef BoatStruct* BoatStructPtr;

#endif