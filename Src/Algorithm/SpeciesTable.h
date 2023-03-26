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
	Species_ID id = MAPLE;
	int		stackDepth = 0;
	float	branchLength = 0;
	Point	angle = { 0, 0, 0 };
	std::vector<IRule*> rules;

	SpeciesEntry(Species_ID id, int depth, float length, Point angle, std::vector<IRule*> rules);
};

struct SpeciesTable : std::vector<SpeciesEntry>
{
	SpeciesTable();
};
