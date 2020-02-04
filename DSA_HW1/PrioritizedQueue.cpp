#include "PrioritizedQueue.h"
#include <stdexcept>

PrioritizedQueue::PrioritizedQueue() {
	head = nullptr;
}

PrioritizedQueue::~PrioritizedQueue() {
	if (head == nullptr) {

	}
	else if (head->getNext() == nullptr) {
		head.reset();
	}
	else {
		cursor = head->getNext();
		do {
			cursor->getPrev().reset();
			cursor = cursor->getNext();
		} while (cursor->getNext() != nullptr);
		head.reset();
		cursor.reset();
	}
}

void PrioritizedQueue::addElement(std::shared_ptr<PrioritizedTask> task) {
	auto insert = std::make_shared<QueueElement>(QueueElement(task));
	if (head == nullptr) {
		head = insert;
	}
	else {
		cursor = head;
		while (cursor != nullptr) {
			if (cursor->getNext() == nullptr) {
				if (*(cursor) > *(insert)) {
					insert->setPrev(cursor->getPrev());
					insert->setNext(cursor);
					if (cursor->getPrev() != nullptr) {
						cursor->getPrev()->setNext(insert);
					}
					cursor->setPrev(insert);
					break;
				}
				else {
					cursor->setNext(insert);
					insert->setPrev(cursor);
					break;
				}
			}
			else if (*(cursor) > * (insert)) {
				if (cursor->getPrev() != nullptr) {
					insert->setNext(cursor);
					insert->setPrev(cursor->getPrev());
					cursor->getPrev()->setNext(insert);
					cursor->setPrev(insert);
				}
				else {
					insert->setNext(cursor);
					cursor->setPrev(insert);
				}
				break;
			}
			else {
				cursor = cursor->getNext();
			}
		}
		if (insert->getPrev() == nullptr) {
			head = insert;
		}
	}
}

std::shared_ptr<PrioritizedTask> PrioritizedQueue::findTask(int id) {
	if (head == nullptr) {
		throw std::runtime_error("Error: Queue is empty.");
	}
	cursor = head;
	while (cursor != nullptr) {
		if (*(cursor) == id) {
			return cursor->getTask();
		}
		else {
			cursor = cursor->getNext();
		}
	}
	throw std::invalid_argument("Task not found.");
}

std::shared_ptr<PrioritizedTask> PrioritizedQueue::deleteElement(int id) {
	findTask(id);
	if (cursor->getPrev() == nullptr) {
		if (cursor->getNext() == nullptr) {
			head = nullptr;
		}
		else {
			cursor->getNext()->setPrev(nullptr);
			head = cursor->getNext();
		}
	}
	else {
		if (cursor->getNext() == nullptr){
			cursor->getPrev()->setNext(nullptr);
		}
		else {
			cursor->getPrev()->setNext(cursor->getNext());
			cursor->getNext()->setPrev(cursor->getPrev());
		}
	}
	return cursor->getTask();
}

std::ostream& operator<<(std::ostream& out, PrioritizedQueue& queue) {
	if (queue.head == nullptr) {
		throw std::runtime_error("List is empty.");
	}
	queue.cursor = queue.head;
	while (queue.cursor != nullptr) {
		out << *(queue.cursor->getTask());
		queue.cursor = queue.cursor->getNext();
	}
	return out;
}