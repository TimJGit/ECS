#pragma once

enum ComponentID
{
	Position
};

const int TOTAL_COMPONENTS = ComponentID::Position + 1;

const char* const COMPONENT_NAMES[TOTAL_COMPONENTS] = {
	"Position"
};
