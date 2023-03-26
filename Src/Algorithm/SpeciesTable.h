#pragma once
#include "Common.h"
#include <vector>
#include "Rule.h"

enum Species_ID
{
	MAPLE,
	PINE,
	OAK
};

struct SpeciesEntry
{
	static constexpr auto NO_SPECIES = 0;
	int		stackDepth = 0;
	Point	angle = { 0, 0, 0 };
	std::vector<Rule> rules;
};

struct SpeciesTable : std::vector<SpeciesEntry>
{
	SpeciesTable()
	{
		this->push_back({ MAPLE, 2, Point(0, 0, 0) });
	}
};
