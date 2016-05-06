#include "Timer.h"

void Timer::Start()
{
	QueryPerformanceFrequency(&m_Frequency);
	QueryPerformanceCounter(&m_StartTime);
}

void Timer::Stop()
{
	QueryPerformanceCounter(&m_EndTime);
	double elapsedTime = (double)(m_EndTime.QuadPart - m_StartTime.QuadPart) / m_Frequency.QuadPart;
	cout << "Elapsed time: " << elapsedTime << "s" << endl;
}
