#include "IDGenerator.h"

unsigned IDGenerator::getID() {
	return ID++;
}

IDGenerator::~IDGenerator() {};