#include "PrioritizedQueue.h"
#include <stdexcept>

PrioritizedQueue::PrioritizedQueue() {
	head = nullptr;
}

PrioritizedQueue::~PrioritizedQueue() {
	cursor = nullptr;
	while (head != nullptr) {
		deleteElement(head->getTask()->getID());
	}
}

void PrioritizedQueue::addElement(std::shared_ptr<PrioritizedTask> task) {
	auto insert = std::make_shared<QueueElement>(QueueElement(task));
	if (head == nullptr) {
		head = insert;		//quick insert if list is empty
	}
	else {
		cursor = head;
		while (cursor != nullptr) {
			if (cursor->getNext() == nullptr) {				//at end of list
				if (*(cursor) > *(insert)) {				//if new one goes before end
					insert->setPrev(cursor->getPrev());
					insert->setNext(cursor);
					if (cursor->getPrev() != nullptr) {		//prevent read-access error on list of len(1)
						cursor->getPrev()->setNext(insert);
					}
					cursor->setPrev(insert);
					break;
				}
				else {						//append to list
					cursor->setNext(insert);
					insert->setPrev(cursor);
					break;
				}
			}
			else if (*(cursor) > * (insert)) {		
				if (cursor->getPrev() != nullptr) {	//insert in middle of list
					insert->setNext(cursor);
					insert->setPrev(cursor->getPrev());
					cursor->getPrev()->setNext(insert);
					cursor->setPrev(insert);
				}
				else {							//Push in at head of list
					insert->setNext(cursor);
					cursor->setPrev(insert);
				}
				break;
			}
			else {								//keep looking
				cursor = cursor->getNext();
			}
		}
		if (insert->getPrev() == nullptr) {		//only happens when inserted at the 
			head = insert;						//head of the list
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

std::shared_ptr<PrioritizedTask> PrioritizedQueue::peek() {
	return head->getTask();
}

std::shared_ptr<PrioritizedTask> PrioritizedQueue::deleteElement(int id) {
	findTask(id);//set cursor to correct task, or throw exception
	if (cursor->getPrev() == nullptr) {
		if (cursor->getNext() == nullptr) {//had a lot of read access errors on nullptr links
			head = nullptr;					//this nested if/else ended it. Curious if theres a better way
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
	out << "ID:" << '\t' << "Priority:" << '\t' << "Summary:" << std::endl;
	while (queue.cursor != nullptr) {//makes a decent looking table of tasks
		out << std::to_string(queue.cursor->getTask()->getID()) << '\t'
			<< std::to_string(queue.cursor->getTask()->getPriority()) << "\t\t"
			<< queue.cursor->getTask()->getSummary() << std::endl << std::endl;
		queue.cursor = queue.cursor->getNext();
	}


	return out;
}