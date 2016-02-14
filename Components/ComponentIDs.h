#pragma once

enum ComponentID
{
	Building,
	Level,
	Position,
	Type,
	TOTAL_COMPONENTS // Do not move or remove
};

const char* const COMPONENT_NAMES[ComponentID::TOTAL_COMPONENTS] = {
	"Building",
	"Level",
	"Position",
	"Type"
};
