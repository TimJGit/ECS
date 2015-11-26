#pragma once

class INotifiable
{
public:
	virtual ~INotifiable() { }

	virtual void Notify(void* pData) = 0;
};
