#pragma once
#include "../Helpers/stdafx.h"

class IObserver
{
public:
	virtual ~IObserver() { }

	virtual void EventCallback() = 0;

protected:
	IObserver();

private:
	vector<ComponentID> m_ComponentIDs;
};
