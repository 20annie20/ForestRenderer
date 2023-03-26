#pragma once
#include "Common.h"
#include <unordered_map>
#include <deque>
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
	std::deque<IRule*> rules;
	std::vector<std::string> axioms;

	SpeciesEntry(Species_ID id, int depth, float length, Point angle, std::deque<IRule*> rules, std::vector<std::string> axioms);
};

struct SpeciesTable : std::vector<SpeciesEntry>
{
	std::deque<IRule*> mapleRules;
	std::deque<IRule*> pineRules;
	std::deque<IRule*> oakRules;

	std::unordered_map<Species_ID, std::vector<std::string>> axioms =
	{
		{ MAPLE, { "BBR", "BL" } },
		{ PINE, { "LBBR", "RSBBSLL" } },
		{ OAK, { "RBLSB", "SR" } }
	};
	
	std::unordered_map <Species_ID, std::deque<IRule*>>* rules = new std::unordered_map<Species_ID, std::deque<IRule*>>();

	SpeciesTable();
};
