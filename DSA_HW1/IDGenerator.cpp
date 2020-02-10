#include "IDGenerator.h"

IDGenerator::IDGenerator() {
	ID = 1;
}

int IDGenerator::getID() {
	return ID++;//returns current ID, then increments it
}

IDGenerator::~IDGenerator() {};