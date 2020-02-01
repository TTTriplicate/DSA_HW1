#pragma once
#include <string>
class PrioritizedTask
{
public:
	PrioritizedTask();
	~PrioritizedTask();

	unsigned getPriority();
	void setPriority(unsigned p);

	unsigned getDuration();
	void setDuration(unsigned d);

	std::string getSummary();
	void setSummary(std::string s);

	std::string getAssignedTo();
	void setAssignedTo(std::string who);
private:
	unsigned priority;
	unsigned duration;
	std::string summary;
	std::string assignedTo;
};

