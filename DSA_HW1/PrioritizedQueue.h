#pragma once
#include <exception>
#include "QueueElement.h"

class PrioritizedQueue
{
public:
	PrioritizedQueue();
	~PrioritizedQueue();
	bool isEmpty();
	int getCount();
	void addElement(std::shared_ptr<PrioritizedTask> task, int priority, int id);
	void deleteElement(int id);
	std::shared_ptr<PrioritizedTask> findTask(int id);
	std::shared_ptr<PrioritizedTask> peek();

private:
	std::shared_ptr<QueueElement> head;
	int countByPriority[5]{ 0 };
	std::shared_ptr<QueueElement> cursor;
};

