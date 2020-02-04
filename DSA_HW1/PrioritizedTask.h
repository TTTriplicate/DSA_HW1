#pragma once
#include <string>
#include <iostream>
class PrioritizedTask
{
public:
	PrioritizedTask();
	PrioritizedTask(std::string fields[5]);
	~PrioritizedTask();

	const int getPriority();
	void setPriority(int p);

	const int getDuration();
	void setDuration(int d);

	const int getID();
	void setID(int ID);

	const std::string getSummary();
	void setSummary(std::string s);

	const std::string getAssignedTo();
	void setAssignedTo(std::string who);

	bool operator==(const int& a);

	bool operator==(const PrioritizedTask& t);
	bool operator<(const PrioritizedTask& t);
	bool operator>(const PrioritizedTask& t);
	

private:
	int priority;
	int duration;
	int id;
	std::string summary;
	std::string assignedTo;
};

std::ostream& operator<<(std::ostream& out, PrioritizedTask& t);


