#pragma once
#include "../Main/stdafx.h"

struct Timer
{
public:
	void Start();
	void Stop();

private:
	LARGE_INTEGER m_StartTime, m_EndTime, m_Frequency;
};
