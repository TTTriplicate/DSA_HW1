#include <iostream>
#include "IDGenerator.h"
#include "PrioritizedQueue.h"


int main()
{
	IDGenerator sequence;
	auto first = std::make_shared<QueueElement>();
	first->setPriority(1);
	auto second = std::make_shared<QueueElement>();
	second->setPriority(1);
	if (*(second) == *(first)) {
		std::cout << "==" << std::endl;
	}
	else if (*(second) > *(first)) {
		std::cout << ">" << std::endl;
	}
	else if (*(second) < *(first)) {
		std::cout << "<" << std::endl;
	}
}
