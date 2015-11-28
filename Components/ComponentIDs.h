#pragma once

enum ComponentID
{
	Position,
	Level,
	Type
};

const int TOTAL_COMPONENTS = ComponentID::Type + 1;

const char* const COMPONENT_NAMES[TOTAL_COMPONENTS] = {
	"Position",
	"Level",
	"Type"
};
