#pragma once
#include "SpeciesTable.h"

SpeciesEntry::SpeciesEntry(Species_ID id, int depth, float length, Point angle, std::deque<IRule*> rules, std::vector<std::string> axioms)
{
	this->id = id;
	this->stackDepth = depth;
	this->branchLength = length;
	this->angle = angle;
	this->rules = rules;
	this->axioms = axioms;
}

SpeciesTable::SpeciesTable()
{
	//starter rules for each species
	oakRules.push_back(new RuleLeaf());
	oakRules.push_back(new RuleLeaf());
	mapleRules.push_back(new RuleReplace());
	mapleRules.push_back(new RuleSplit());
	mapleRules.push_back(new RuleBranch());	
	
	oakRules.push_back(new RuleLeaf());
	oakRules.push_back(new RuleLeaf());
	pineRules.push_back(new RuleReplace());
	pineRules.push_back(new RuleSplit());
	pineRules.push_back(new RuleBranch());
	pineRules.push_back(new RuleBranch());
	pineRules.push_back(new RuleSplit());
	pineRules.push_back(new RuleReplace());
	pineRules.push_back(new RuleBranch());

	oakRules.push_back(new RuleBranch());
	oakRules.push_back(new RuleBranch());
	oakRules.push_back(new RuleSplit());
	oakRules.push_back(new RuleReplace());
	oakRules.push_back(new RuleBranch());
	oakRules.push_back(new RuleBranch());
	oakRules.push_back(new RuleBranch());

	rules->insert(std::pair<Species_ID, std::deque<IRule*>>(MAPLE, mapleRules));
	rules->insert(std::pair<Species_ID, std::deque<IRule*>>(PINE, pineRules));
	rules->insert(std::pair<Species_ID, std::deque<IRule*>>(OAK, oakRules));

	this->push_back(
		SpeciesEntry( MAPLE, 5, 10.0f, Point(0.1f, 0.1f, 0), rules->at(MAPLE), axioms[MAPLE])
	);

	this->push_back(
		SpeciesEntry(PINE, 12, 20.0f, Point(0.2f, 0.2f, 0.2f), rules->at(PINE), axioms[PINE] )
	);

	this->push_back(
		SpeciesEntry(OAK, 12, 5.0f, Point(0.1f, 0.3f, 0.2f), rules->at(OAK), axioms[OAK])
	);
}