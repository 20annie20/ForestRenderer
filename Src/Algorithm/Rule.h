#pragma once
#include "Common.h"

class Tree;

struct IRule {
	virtual void apply(Tree& tree) = 0;
	static Point Move(Point start, Point angle, float distance);
};

struct RuleSplit : public IRule {
	void apply(Tree& tree);
};

struct RuleBranch : public IRule {
	void apply(Tree& tree);
};

struct RuleLeaf : public IRule {
	void apply(Tree& tree);
};

struct RuleReplace : public IRule {
	void apply(Tree& tree);
};