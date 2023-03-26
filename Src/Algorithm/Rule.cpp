#pragma once
#include "Rule.h"
#include "Tree.h"
#include<cstdlib>

Point IRule::Move(Point start, Point angle, float distance)
{
	srand((unsigned)time(NULL));
	int x = start.x + (distance * angle.x + 0.01 * (rand() % 100));
	int y = start.y + (distance * angle.y + 0.01 * (rand() % 100));
	int z = start.z + (distance * angle.z + 0.01 * (rand() % 100));
	return Point(x, y, z);
}

void RuleSplit::apply(Tree& tree)
{
	// adds new branch rules with new angles, pushes two points for them
	auto& start = tree.stacks.startingPoints.back();
	auto& angle = tree.stacks.startingAngles.back();
	tree.stacks.startingAngles.pop_back(); // next branches will go with new angles

	if (tree.stacks.rules.size() < tree.td.stackDepth)
	{
		tree.stacks.rules.push_back(new RuleBranch);
		tree.stacks.startingAngles.push_back(angle + tree.td.angleSplit);

		for (int i = 0; i < rand() % 4; i++)
		{
			tree.stacks.rules.push_back(new RuleBranch);
			tree.stacks.startingPoints.push_back(start); // second starting point for the second branch
			if( i % 2 == 0)
				tree.stacks.startingAngles.push_back(angle + tree.td.angleSplit + Point(0.01 * (rand() % 100), 0.01 * (rand() % 100), 0.01 * (rand() % 100)));
			else
				tree.stacks.startingAngles.push_back(angle - tree.td.angleSplit + Point(0.01 * (rand() % 100), 0.01 * (rand() % 100), 0.01 * (rand() % 100)));
		}
		
	}
}

void RuleBranch::apply(Tree& tree)
{
	auto length = tree.td.branchLength;	
	auto& start = tree.stacks.startingPoints.back();
	auto& angle = tree.stacks.startingAngles.back();
	auto end = Move(start, angle, length );
	
	tree.branches.push_back(std::pair(start, end));
	tree.stacks.startingPoints.pop_back();
	tree.stacks.startingAngles.pop_back();
	tree.stacks.startingPoints.push_front(end);
	tree.stacks.startingAngles.push_front(angle);
}

void RuleLeaf::apply(Tree& tree)
{
	// pops point to mark the end of a branch
}

void RuleReplace::apply(Tree& tree)
{
	// pick axiom randomly
	if (tree.stacks.rules.size() < tree.td.stackDepth)
	{
		// for each character from replace
		tree.stacks.rules.push_front(new RuleBranch);
		tree.stacks.rules.push_front(new RuleSplit);
		tree.stacks.rules.push_front(new RuleReplace);
		tree.stacks.rules.push_front(new RuleBranch);
	}
}