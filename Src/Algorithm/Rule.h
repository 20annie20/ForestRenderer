#pragma once
#include "Common.h"

struct IRule {
	virtual void apply() = 0;
};

struct RuleRotateR : public IRule {
	void apply();
};

struct RuleRotateL : public IRule {
	void apply();
};

struct RuleBranch : public IRule {
	void apply();
};

struct RulePush : public IRule {
	void apply();
};

struct RulePop : public IRule {
	void apply();
};

struct RuleLeaf : public IRule {
	void apply();
};