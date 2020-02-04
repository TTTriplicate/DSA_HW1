#pragma once
#include <memory>
#include "PrioritizedTask.h"
class QueueElement
{
public:
	QueueElement();
	QueueElement(std::shared_ptr<PrioritizedTask> t);
	
	~QueueElement();

	std::shared_ptr<PrioritizedTask> getTask();
	void setTask(std::shared_ptr<PrioritizedTask> t);

	std::shared_ptr<QueueElement> getNext();
	void setNext(std::shared_ptr<QueueElement> newNext);

	std::shared_ptr<QueueElement> getPrev();
	void setPrev(std::shared_ptr<QueueElement> newPrev);

	bool operator< (const QueueElement& a);
	bool operator> (const QueueElement& a);
	bool operator== (const QueueElement& a);
	bool operator== (const int& ID);

private:
	std::shared_ptr<QueueElement> next;
	std::shared_ptr<QueueElement> prev;
	std::shared_ptr<PrioritizedTask> task;

};

