#include "IDGenerator.h"

IDGenerator::IDGenerator() {
	ID = 1;
}

int IDGenerator::getID() {
	ID++;
	return ID - 1;
}

IDGenerator::~IDGenerator() {};