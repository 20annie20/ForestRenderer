#pragma once
#include "Rule.h"
#include "Tree.h"
#include<cstdlib>

Point IRule::Move(Point start, Point angle, float distance)
{
	int x, y, z;
	srand((unsigned)time(NULL));
	if (rand() % 2 == 0) 
	{
		x = start.x + (distance * angle.x + 0.01 * (rand() % 100));
		y = start.y + (distance * angle.y + 0.01 * (rand() % 100));
		z = start.z + (distance * angle.z + 0.01 * (rand() % 100));
	}
	else
	{
		x = start.x + (distance * angle.x - 0.01 * (rand() % 100));
		y = start.y + (distance * angle.y - 0.01 * (rand() % 100));
		z = start.z + (distance * angle.z - 0.01 * (rand() % 100));
	}
	
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
		int splits = rand() % tree.td.splitAmount;
		for (int i = splits / 2; i < splits; i++)
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

void RuleReplace::apply(Tree& tree)
{
	auto option = rand() % tree.td.axioms.size();
	auto axiom = tree.td.axioms.at(option);

	for (auto& ch : axiom) {
		if (tree.stacks.rules.size() < tree.td.stackDepth)
		{
			switch (ch) {
			case 'R':
				tree.stacks.rules.push_front(new RuleReplace);
				break;
			case 'S':
				tree.stacks.rules.push_front(new RuleSplit);
				break;
			case 'B':
				tree.stacks.rules.push_front(new RuleBranch);
				break;
			default:
				break;
			}
		}
	}
}