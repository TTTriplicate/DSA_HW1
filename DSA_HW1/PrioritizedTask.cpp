#include "PrioritizedTask.h"

PrioritizedTask::PrioritizedTask() {};

PrioritizedTask::PrioritizedTask(std::string fields[5]) {
	setSummary(fields[0]);
	setAssignedTo(fields[1]);
	setDuration(std::stoi(fields[2]));
	setPriority(std::stoi(fields[3]));
	setID(std::stoi(fields[4]));
}

PrioritizedTask::~PrioritizedTask() {};

void PrioritizedTask::setPriority(int p) {
	priority = p;
}
const int PrioritizedTask::getPriority() {
	return priority;
}

const int PrioritizedTask::getDuration() {
	return duration;
}
void PrioritizedTask::setDuration(int d) {
	duration = d;
}

const int PrioritizedTask::getID() {
	return id;
}
void PrioritizedTask::setID(int ID) {
	id = ID;
}

const std::string PrioritizedTask::getSummary() {
	return summary;
}
void PrioritizedTask::setSummary(std::string s) {
	summary = s;
}

const std::string PrioritizedTask::getAssignedTo() {
	return assignedTo;
}
void PrioritizedTask::setAssignedTo(std::string who) {
	assignedTo = who;
}

bool PrioritizedTask::operator==(int a) {
	return id == a;
}

std::ostream& operator<<(std::ostream& out, PrioritizedTask& task) {
	out << "Summary: " + task.getSummary() << std::endl << "Assigned To: " + task.getAssignedTo() << std::endl
		<< "Duration: " + std::to_string(task.getDuration()) + "days." << std::endl << "Priority: " + std::to_string(task.getPriority()) << std::endl
		<< "ID: " + std::to_string(task.getID()) << std::endl;
	return out;
}