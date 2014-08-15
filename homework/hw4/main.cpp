#include <iostream>
#include <string>
#include <cmath>
#include "math_tree.h"
#include "calc_parser.h"
using namespace std;

double evalOp(string op, double val)
{
    // for evaluating functions like sin, cos, etc.
}

double evalOp(string op, double val1, double val2)
{
    // for evaluating operators like +, -, etc.
}

double eval(Tree *root)
{
    // for (recursively) evaluating a tree; this function will refer
    // back to itself (for evaluating subtrees) and will use the
    // evalOp() functions
}

// this is a global variable used by the parser
Tree* math_tree;

int main()
{
    // hand-code a tree for this expression:
    //  sin(3.14159/4.0)+cos(8.0*2.0)

    // ...

    // here we print your hand-coded tree
    print_ascii_tree(....);

    // and evaluate the hand-coded tree (should equal -0.25)
    cout << "Result: " << eval(....) << endl << endl << endl;


    // this is the user-input loop; there is no need to change it
    while(true)
    {
        Parser parser;
        cout << "Enter expression: ";

        // this function gets the input and does the parsing
        parser.yyparse();

        // the yyparse() function sets the global variable math_tree
        // to a new tree; if that tree is NULL (no tree), just quit
        if(math_tree == NULL)
            break;

        // otherwise, print the tree
        print_ascii_tree(math_tree);

        // and evaluate it
        cout << "Result: " << eval(math_tree) << endl << endl;

        // reset the tree back to NULL before looping
        math_tree = NULL;
    }

    return 0;
}
