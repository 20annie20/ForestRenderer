#pragma once
#include "Common.h"

class Tree;

/// L-system rule struct
/** L-systems are used in the application to simulate naturally looking growth
*/
struct Rule {
	virtual void Apply(Tree& tree) = 0;
	static Point Move(Point start, Point angle, float distance);
};

/// L-system rule split struct
/** Rule to add a split at the end of the branch that can be a beginning for new branches
*/
struct RuleSplit : public Rule {
	void Apply(Tree& tree);
};

/// L-system rule branch struct
/** Rule to create a new branch
*/
struct RuleBranch : public Rule {
	void Apply(Tree& tree);
};

/// L-system rule replace struct
/** this rule replaces occurence of the replace symbol (R) in the tree grammar string
with new randomly picked vector of rules selected from axioms defined per species.
*/
struct RuleReplace : public Rule {
	void Apply(Tree& tree);
};