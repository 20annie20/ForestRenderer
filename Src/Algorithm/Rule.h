#pragma once
#include "Common.h"

class Tree;

/// L-system rule struct
/** L-systems are used in the application to simulate naturally looking growth
*/
struct Rule {
    /**
    * \brief Applies a rule to the tree.
    * \param tree - Tree to grow.
    */
    virtual void Apply(Tree& tree) = 0;

    /**
	* \brief Moves a point by a distance at a direction specified by an angle.
	* \param start - Point to move.
    * \param angle - Direction angle.
    * \param distance - Distance to move the point.
    * \returns The transformed point.
	*/
    static Point Move(Point start, Point angle, float distance);
};

/// L-system rule split struct
/** Rule to add a split at the end of the branch that can be a beginning for new branches
*/
struct RuleSplit : public Rule {
    /**
    * \brief Applies a split rule to the tree.
    * \param tree - Tree to grow.
    */
    void Apply(Tree& tree);
};

/// L-system rule branch struct
/** Rule to create a new branch
*/
struct RuleBranch : public Rule {
    /**
    * \brief Applies a branch rule to the tree.
    * \param tree - Tree to grow.
    */
    void Apply(Tree& tree);
};

/// L-system rule replace struct
/** this rule replaces occurence of the replace symbol (R) in the tree grammar string
with new randomly picked vector of rules selected from axioms defined per species.
*/
struct RuleReplace : public Rule {
    /**
    * \brief Applies a replace rule to the tree.
    * \param tree - Tree to grow.
    */
    void Apply(Tree& tree);
};