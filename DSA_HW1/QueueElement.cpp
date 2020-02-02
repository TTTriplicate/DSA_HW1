#include "QueueElement.h"

QueueElement::QueueElement() {
	next = nullptr;
	prev = nullptr;
};

QueueElement::~QueueElement() {};

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

void QueueElement::setPriority(int p) {
	priority = p;
}
const int QueueElement::getPriority() {
	return priority;
}

void QueueElement::setID(int ID) {
	id = ID;
}
const int QueueElement::getID() {
	return id;
}


void QueueElement::setTask(std::shared_ptr<PrioritizedTask> t) {
	task = t;
}
std::shared_ptr<PrioritizedTask> QueueElement::getTask() {
	return task;
}

bool QueueElement::operator<(const QueueElement& a) {
	return priority < a.priority;
}

bool QueueElement::operator== (const QueueElement& a) {//once priority is established, check id for exact item
	return id == a.id;
}
bool QueueElement::operator== (const int& ID) {
	return id == ID;
}

bool QueueElement::operator> (const QueueElement& a) {
	return priority > a.priority;
}