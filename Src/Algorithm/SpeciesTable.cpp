#pragma once
#include "SpeciesTable.h"

SpeciesEntry::SpeciesEntry(Species_ID id, int depth, float length, Point angle, std::vector<IRule*> rules)
{
	this->id = id;
	this->stackDepth = depth;
	this->branchLength = length;
	this->angle = angle;
	this->rules = rules;
}

SpeciesTable::SpeciesTable()
{
	this->push_back(SpeciesEntry(MAPLE, 2, 2.0f, Point(0, 0, 0), std::vector<IRule*>()));
	this->push_back(SpeciesEntry(PINE, 3, 2.0f, Point(0, 0, 0), std::vector<IRule*>()));
	this->push_back(SpeciesEntry(OAK, 1, 3.0f, Point(0, 0, 0), std::vector<IRule*>()));
}