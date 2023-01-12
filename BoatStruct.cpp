#include "BoatStruct.h"

BoatStruct::BoatStruct() {
    boatOwnerName = " ";
    boatName = " ";
    boatSize = 0;
    next = NULL;
}

BoatStruct::BoatStruct(std::string oName, std::string bName, double size) {
    boatOwnerName = oName;
    boatName = bName;
    boatSize = size;
    next = NULL;
}

void BoatStruct::print() {
    std::cout << "Boat " << boatName << " owned by " << boatOwnerName << " size " << boatSize << std::endl;
}