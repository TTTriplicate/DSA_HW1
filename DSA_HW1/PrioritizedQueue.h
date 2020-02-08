#pragma once
#include <exception>
#include "QueueElement.h"

class PrioritizedQueue
{
public:
	PrioritizedQueue();
	~PrioritizedQueue();
	int addElement(std::shared_ptr<PrioritizedTask> task);
	std::shared_ptr<PrioritizedTask> deleteElement(int id);
	std::shared_ptr<PrioritizedTask> findTask(int id);
	std::shared_ptr<PrioritizedTask> peek();
	friend std::ostream& operator<<(std::ostream& out, PrioritizedQueue& queue);
private:
	std::shared_ptr<QueueElement> head;
	std::shared_ptr<QueueElement> cursor;
};

