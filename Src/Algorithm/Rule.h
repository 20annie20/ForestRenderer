#pragma once
#include "Common.h"

class Tree;

struct Rule {
	virtual void Apply(Tree& tree) = 0;
	static Point Move(Point start, Point angle, float distance);
};

struct RuleSplit : public Rule {
	void Apply(Tree& tree);
};

struct RuleBranch : public Rule {
	void Apply(Tree& tree);
};

struct RuleReplace : public Rule {
	void Apply(Tree& tree);
};