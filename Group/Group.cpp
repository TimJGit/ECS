#include "Group.h"

Group::Group()
{
}

Group::~Group()
{
}

void Group::SetComponentIDs(const vector<ComponentID>& componentIDs)
{
	m_ComponentIDs = componentIDs;
	sort(m_ComponentIDs.begin(), m_ComponentIDs.end());
}

bool Group::CompareComponentIDs(vector<ComponentID>& componentIDs) const
{
	if(m_ComponentIDs.size() != componentIDs.size()){
		return false;
	}

	sort(componentIDs.begin(), componentIDs.end());

	for(unsigned int i = 0; i < m_ComponentIDs.size(); ++i){
		if(m_ComponentIDs[i] != componentIDs[i]){
			return false;
		}
	}

	return true;
}
