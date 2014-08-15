#ifndef MATH_TREE_H
#define MATH_TREE_H

#include <string>

class Tree
{
public:
    std::string op;
    double val;
    Tree *left;
    Tree *right;
};

extern void print_ascii_tree(Tree * t);

#endif

