#pragma once
class IDGenerator
{
public:
	IDGenerator() = default;
	~IDGenerator();
	unsigned getID();
private:
	unsigned ID = 1;
};

