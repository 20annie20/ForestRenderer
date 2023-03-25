#pragma once

class Renderer
{
public:
	virtual void Init() = 0;
	virtual void Run() = 0;
	virtual void Cleanup() = 0;
};