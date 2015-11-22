#pragma once

enum ComponentID
{
	PositionComponent
};

const int TOTAL_COMPONENTS = ComponentID::PositionComponent + 1;

const char* const COMPONENT_NAMES[TOTAL_COMPONENTS] = {
	"PositionComponent"
};
