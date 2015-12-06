#pragma once

enum ComponentID
{
	Level,
	Position,
	Type
};

const int TOTAL_COMPONENTS = ComponentID::Type + 1;

const char* const COMPONENT_NAMES[TOTAL_COMPONENTS] = {
	"Level",
	"Position",
	"Type"
};
