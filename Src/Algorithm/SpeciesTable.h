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
	int		splitAmount = 0;
	float	branchLength = 0;
	Point	angle = { 0, 0, 0 };
	std::deque<IRule*> rules;
	std::vector<std::string> axioms;

	SpeciesEntry(Species_ID id, int depth, int split, float length, Point angle, std::deque<IRule*> rules, std::vector<std::string> axioms);
};

struct SpeciesTable : std::vector<SpeciesEntry>
{
	std::deque<IRule*> mapleRules;
	std::deque<IRule*> pineRules;
	std::deque<IRule*> oakRules;

	std::unordered_map<Species_ID, std::vector<std::string>> axioms =
	{
		{ MAPLE, { "BRB", "BSB", "BSS", "SBSBR"}},
		{ PINE, { "SRB", "BRB", "RBBSS"}},
		{ OAK, { "SBSB", "RBSB", "SRB" } }
	};
	
	std::unordered_map <Species_ID, std::deque<IRule*>>* rules = new std::unordered_map<Species_ID, std::deque<IRule*>>();

	SpeciesTable();
};
