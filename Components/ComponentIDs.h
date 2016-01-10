#pragma once

enum ComponentID
{
	Building,
	Level,
	Position,
	Type
};

const int TOTAL_COMPONENTS = ComponentID::Type + 1;

const char* const COMPONENT_NAMES[TOTAL_COMPONENTS] = {
	"Building",
	"Level",
	"Position",
	"Type"
};
