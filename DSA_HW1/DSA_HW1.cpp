#include <iostream>
#include "IDGenerator.h"
#include "PrioritizedQueue.h"


int main()
{
	IDGenerator sequence;
	PrioritizedQueue queue;

	while (true) {
		std::string input;
		std::cout << "Please enter an option:" << std::endl;
		std::cout << "(C)reate a task, (S)elect a task, (R)emove a task, (V)iew all tasks, or e(X)it:" << std::endl;
		getline(std::cin, input);
		try {
			if (input.length() > 1) {
				throw std::invalid_argument("Please select one of the listed options.");
			}
			if (tolower(input[0] == 'c')) {
				std::string fields[5]{ "" };

				while (true) {
					std::cout << "Enter a summary of the task:" << std::endl;
					getline(std::cin, fields[0]);
					if (fields[0].length() == 0) {
						std::cout << "A summary is required." << std::endl;
					}
					else {
						break;
					}
				}

				std::cout << "Who will complete this task?" << std::endl;
				getline(std::cin, fields[1]);

				while (true) {
					std::cout << "Enter a duration in days, between 1 and 15:" << std::endl;
					getline(std::cin, fields[2]);
					if (!isdigit(fields[2][0]) || (fields[2].length() > 1 && !isdigit(fields[2][1]))) {
						std::cout << "Please only enter numbers." << std::endl;
					}
					else if (std::stoi(fields[2]) < 1 || std::stoi(fields[2]) > 15) {
						std::cout << "Please enter a duration between 1 and 15:" << std::endl;
					}
					else {
						break;
					}
				}
				while(true) {
					std::cout << "Please enter a priority, between 1 and 5:" << std::endl;
					getline(std::cin, fields[3]);
					if (fields[3].length() > 1) {
						std::cout << "Input too long.  Please enter one number, between 1 and five." << std::endl;
					}
					else if (!isdigit(fields[3][0])) {
						std::cout << "Please enter only numbers." << std::endl;
					}
					else if (std::stoi(fields[3]) < 1 || std::stoi(fields[3]) > 5) {
						std::cout << "Please enter a priority that is between 1 and 5." << std::endl;
					}
					else {
						break;
					}
				}
				int id = sequence.getID();
				fields[4] = std::to_string(id);
				std::cout << "The unique ID for this task is: " << fields[4] << std::endl;

				PrioritizedTask newTask(fields);
				auto toAdd = std::make_shared<PrioritizedTask>(newTask);
				queue.addElement(toAdd);
				std::cout << *(queue.findTask(std::stoi(fields[4]))) << std::endl;
			}

			else if (tolower(input[0]) == 's') {
				bool Digits = true;

				while (Digits) {
					std::cout << "Enter the ID of the task you'd like to view: " << std::endl;
					getline(std::cin, input);
					for (char c : input) {
						if (!isdigit(c)) {
							Digits = false;
							break;
						}
						}
					if(!Digits){
						std::cout << "Please enter only numbers." << std::endl;
						Digits = true;
						continue;
					}
					else {
						break;
					}
				}
				std::cout << *(queue.findTask(std::stoi(input)));
			}

			else if (tolower(input[0]) == 'v') {
				std::cout << queue;
			}

			else if (tolower(input[0]) == 'r') {
				std::string toRem;
				bool digits = false;
				while (!digits) {
					std::cout << "Enter the ID of the task you want to remove:" << std::endl;
					digits = true;
					getline(std::cin, toRem);
					for (char c : toRem) {
						if (!isdigit(c)) {
							digits = false;
						}
					}
				}
				std::shared_ptr<PrioritizedTask> toDel = queue.deleteElement(std::stoi(toRem));
				std::cout <<  "Task " << *(toDel) << "Has been removed from the queue." << std::endl;
			}

			else if (tolower(input[0]) == 'x') {
				break;
			}
		}

		catch (std::invalid_argument& e) {
			std::cerr << e.what() << std::endl;
		}
		catch (std::runtime_error & e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
