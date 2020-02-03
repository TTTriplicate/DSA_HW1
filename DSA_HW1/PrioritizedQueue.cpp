#include "PrioritizedQueue.h"
#include <stdexcept>

PrioritizedQueue::PrioritizedQueue() {
	head = nullptr;
}

PrioritizedQueue::~PrioritizedQueue() {
//delete everything
}

void PrioritizedQueue::addElement(std::shared_ptr<PrioritizedTask> task, int priority, int id) {
	QueueElement newTask;
	newTask.setTask(task);
	newTask.setPriority(priority);
	newTask.setID(id);
	std::shared_ptr<QueueElement> insert = std::make_shared<QueueElement>(newTask);
	if (head == nullptr) {
		head = insert;
	}
	else {
		cursor = head;
		while (cursor != nullptr) {
			if (cursor->getNext() == nullptr) {
				if (*(cursor) > * (insert)) {
					insert->setPrev(cursor->getPrev());
					insert->setNext(cursor);
					cursor->setPrev(insert);
					break;
				}
				else {
					cursor->setNext(insert);
					insert->setPrev(cursor);
					break;
				}
			}
			else if (*(cursor) > *(insert)) {
				insert->setPrev(cursor->getPrev());
				insert->setNext(cursor);
				cursor->setPrev(insert);
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
	if (cursor->getPrev() != nullptr && cursor->getNext()!= nullptr) {
		cursor->getNext()->setPrev(cursor->getPrev());
		cursor->getPrev()->setNext(cursor->getNext());
	}
	else if (cursor->getNext() == nullptr) {
		cursor->getPrev()->setNext(nullptr);
	}
	else if (cursor->getPrev() == nullptr) {
		head = cursor->getNext();
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