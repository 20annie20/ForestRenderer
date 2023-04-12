#pragma once
#include "Common.h"

class Tree;

struct IRule {
	virtual void Apply(Tree& tree) = 0;
	static Point Move(Point start, Point angle, float distance);
};

struct RuleSplit : public IRule {
	void Apply(Tree& tree);
};

struct RuleBranch : public IRule {
	void Apply(Tree& tree);
};

struct RuleReplace : public IRule {
	void Apply(Tree& tree);
};