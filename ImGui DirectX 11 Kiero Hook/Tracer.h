#pragma once
#include "Vector.h"
class Tracer
{
public:
	void Render();
	float LineSize = 1;
	float colorTracer[4] = { 0.0f,1.0f,0.0f,1.0f };
	bool teamcheck = false;
};