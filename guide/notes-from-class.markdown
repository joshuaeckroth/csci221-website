---
layout: default
title: Notes from class
---

## hangman.cpp

{% highlight cpp %}
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string answer = "softwares";
    string attempt = "_________";
    int gc = 5;

    // loop to check inputs
    while(true)
    {
        cout << attempt << endl;
        char guess;
        cin >> guess;
        int pos;
        int startpos = 0;
        while(-1 != (pos = answer.find(guess, startpos)))
        {
            attempt[pos] = guess;
            startpos = pos + 1;
        }
        if(startpos == 0)
        {
            cout << "Did not find that character." << endl;
            if(--gc < 0)
            {
                cout << "You lost!" << endl;
                break;
            }
        }
        if(attempt == answer)
        {
            cout << "You won!" << endl;
            break;
        }
    }

    return 0;
}
{% endhighlight %}

{% comment %}
## hangman.cpp

{% highlight cpp %}
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string guessed = "";
    string ans = "stetson";
    string partial = "_______";
    int errors = 0;

    char c;
    do {
        cout << partial << endl;
        cout << "Enter a letter: ";
        cin >> c;
        guessed += c;
        if(-1 == ans.find(c))
        {
            cout << "Bad guess." << endl;
            errors++;
        }
        else
        {
            int pos = ans.find(c);
            do {
                partial[pos] = c;
                ans[pos] = '_';
                pos = ans.find(c);
            } while(pos != -1);
        }
    } while(errors < 7 && -1 != partial.find('_'));
    if(errors == 7)
    {
        cout << "Bad job." << endl;
    }
    else
    {
        cout << "Good job." << endl;
    }

    return 0;
}
{% endhighlight %}

## pointers.cpp

{% highlight cpp %}
#include <iostream>
using namespace std;

int main()
{
    int pos = 0;
    float *y = new float[1000];
    while(true)
    {
        //cin >> *(y + pos);
        cin >> y[pos];

        if(y[pos] < 0)
        {
            break;
        }
        pos++;
    }

    for(int i = 0; i < pos; i++)
    {
        //cout << "Value at index " << i << " is " << *(y + i) << endl;
        cout << "Value at index " << i << " is " << y[i] << endl;
    }
    delete[] y;
}
{% endhighlight %}

## trees.cpp

{% highlight cpp %}
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Tree
{
public:
    Tree();
    void print_preorder();
    void print_postorder();
    void print_inorder();
    double eval();
    Tree *left;
    Tree *right;
    double val;
    string op;
};

Tree::Tree()
{
    left = NULL;
    right = NULL;
    val = 0.0;
}

double Tree::eval()
{
    if(op != "" && left != NULL && right != NULL)
    {
        if(op == "+")
        {
            return (left->eval() + right->eval());
        }
        else if(op == "-")
        {
            return (left->eval() - right->eval());
        }
        else
        {
            // should never happen
            return 0.0;
        }
    }
    else if(op != "" && left != NULL)
    {
        if(op == "sin")
        {
            return sin(left->eval());
        }
        else
        {
            // should never happen
            return 0.0;
        }
    }
    else
    {
        return val;
    }
}

void Tree::print_preorder()
{
    if(op != "")
    {
        cout << op << " ";
    }
    else
    {
        cout << val << " ";
    }
    if(left != NULL)
    {
        left->print_preorder();
    }
    if(right != NULL)
    {
        right->print_preorder();
    }
}

void Tree::print_postorder()
{
    if(left != NULL)
    {
        left->print_postorder();
    }
    if(right != NULL)
    {
        right->print_postorder();
    }
    if(op != "")
    {
        cout << op << " ";
    }
    else
    {
        cout << val << " ";
    }
}
    

void Tree::print_inorder()
{
    if(op != "" && left != NULL && right == NULL)
    {
        cout << op << "(";
        left->print_inorder();
        cout << ")";
    }
    else
    {
        if(op != "" && left != NULL)
        {
            left->print_inorder();
        }
        if(op != "")
        {
            cout << op << " ";
        }
        else
        {
            cout << val << " ";
        }
        if(right != NULL)
        {
            right->print_inorder();
        }
    }
}

int main()
{
    Tree *a = new Tree;
    Tree *b = new Tree;
    Tree *c = new Tree;
    Tree *d = new Tree;
    Tree *e = new Tree;
    Tree *f = new Tree;
    a->op = "+";
    b->op = "-";
    c->op = "sin";
    f->val = 3.1;
    c->left = f;
    d->val = 7.2;
    e->val = 8.0;
    a->left = b;
    a->right = e;
    b->left = c;
    b->right = d;

    a->print_inorder();
    cout << endl;

    cout << "Evaluated = " << a->eval() << endl;
    
    return 0;
}
{% endhighlight %}

{% endcomment %}