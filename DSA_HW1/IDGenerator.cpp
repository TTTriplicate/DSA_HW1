#include "IDGenerator.h"

IDGenerator::IDGenerator() {
	ID = 1;
}

int IDGenerator::getID() {
	return ID++;
}

IDGenerator::~IDGenerator() {};