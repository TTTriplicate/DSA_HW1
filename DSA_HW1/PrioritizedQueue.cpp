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
		while (*(cursor) < *(insert)) {
			if (cursor->getNext() == nullptr) {
				cursor->setNext(insert);
				insert->setPrev(cursor);
				break;
			}
			else {
				cursor = cursor->getNext();
			}
		}
		if (*(cursor->getNext()) > *(insert)) {
			insert->setNext(cursor->getNext());
			insert->setPrev(cursor);
			cursor->setNext(insert);
		}
	}


}

std::shared_ptr<PrioritizedTask> PrioritizedQueue::findTask(int id) {
	if (head == nullptr) {
		throw std::runtime_error("Error: Queue is empty.");
	}
	cursor = head;
	if (*(cursor) == id) {
		return cursor->getTask();
	}
	else if (cursor->getNext() == nullptr) {
		throw std::invalid_argument("Task not found.");
	}
	else {
		cursor = cursor->getNext();
	}
}

void PrioritizedQueue::deleteElement(int id) {
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
	delete &cursor;
}