#include "QueueElement.h"

QueueElement::QueueElement() {
	priority = 1;
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

void QueueElement::setPriority(unsigned p) {
	priority = p;
}
const unsigned QueueElement::getPriority() {
	return priority;
}

void QueueElement::setTask(PrioritizedTask t) {
	task = t;
}
PrioritizedTask QueueElement::getTask() {
	return task;
}

bool operator<(const QueueElement& a, const QueueElement& b) {
	return a.priority < b.priority;
}

bool operator== (const QueueElement& a, const QueueElement& b) {
	return a.priority == b.priority;
}

bool operator> (const QueueElement& a, const QueueElement& b) {
	return a.priority > b.priority;
}