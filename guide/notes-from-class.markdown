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
