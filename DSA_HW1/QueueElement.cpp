#include "QueueElement.h"

QueueElement::QueueElement() {
	next = nullptr;
	prev = nullptr;
};

QueueElement::QueueElement(std::shared_ptr<PrioritizedTask> t) {
	next = nullptr;
	prev = nullptr;
	task = t;
};


QueueElement::~QueueElement() {//clear pointers, decrementing shared_ptr reference counts
	task.reset();
	next.reset();
	prev.reset();

};

std::shared_ptr<QueueElement> QueueElement::getNext() {
	return next;
}
void QueueElement::setNext(std::shared_ptr<QueueElement> newNext) {
	next = newNext;
}

std::shared_ptr<QueueElement> QueueElement::getPrev() {
	return prev;
}
void QueueElement::setPrev(std::shared_ptr<QueueElement> newPrev) {
	prev = newPrev;
}



void QueueElement::setTask(std::shared_ptr<PrioritizedTask> t) {
	task = t;
}
std::shared_ptr<PrioritizedTask> QueueElement::getTask() {
	return task;
}

bool QueueElement::operator<(const QueueElement& a) {//compare tasks to find location in list
	return *(task) < *(a.task);
}

bool QueueElement::operator== (const QueueElement& a) {//once priority is established, check id for exact item
	return *(task) == *(a.task);						//unused
}
bool QueueElement::operator== (const int& ID) {//compare task to int
	return *(task) == ID;
}

bool QueueElement::operator> (const QueueElement& a) {//compare tasks to find location in list
	return *(task) > *(a.task);							
}