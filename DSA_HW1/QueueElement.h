#pragma once
#include <memory>
#include "PrioritizedTask.h"
class QueueElement
{
public:
	QueueElement();
	~QueueElement();

	PrioritizedTask getTask();
	void setTask(PrioritizedTask t);

	std::shared_ptr<QueueElement> getNext();
	void setNext(std::shared_ptr<QueueElement> newNext);

	std::shared_ptr<QueueElement> getPrev();
	void setPrev(std::shared_ptr<QueueElement> newPrev);

	const unsigned getPriority();
	void setPriority(unsigned p);

	bool operator< (const QueueElement& a);
	bool operator> (const QueueElement& a);
	bool operator== (const QueueElement& a);

private:
	unsigned priority;
	std::shared_ptr<QueueElement> next;
	std::shared_ptr<QueueElement> prev;
	PrioritizedTask task;

};

