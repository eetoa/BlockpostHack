#pragma once
class Lock
{
public:
	void LockAll();
	bool active = true;
};