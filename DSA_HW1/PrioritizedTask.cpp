#include "PrioritizedTask.h"

PrioritizedTask::PrioritizedTask() {};
PrioritizedTask::~PrioritizedTask() {};

void PrioritizedTask::setPriority(unsigned p) {
	priority = p;
}
unsigned PrioritizedTask::getPriority() {
	return priority;
}

unsigned PrioritizedTask::getDuration() {
	return duration;
}
void PrioritizedTask::setDuration(unsigned d) {
	duration = d;
}

std::string PrioritizedTask::getSummary() {
	return summary;
}
void PrioritizedTask::setSummary(std::string s) {
	summary = s;
}

std::string PrioritizedTask::getAssignedTo() {
	return assignedTo;
}
void PrioritizedTask::setAssignedTo(std::string who) {
	assignedTo = who;
}