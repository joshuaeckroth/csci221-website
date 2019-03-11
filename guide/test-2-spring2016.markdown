---
title: Test 2 from Spring 2016
layout: default
categories: [studyguides]
---

# Test 2 from Spring 2016

**Note, you may only refer to this site and [cppreference.com](http://en.cppreference.com/w/) during the test. Do not look at other notes or code or Google, etc.** Total points is 100.

## Task 1 (100 pts)

Create the classes represented in this UML diagram:

![Shopping Cart UML](https://raw.githubusercontent.com/joshuaeckroth/csci221-website/gh-pages/images/ShoppingCart.png)

Note, Product::getPriceWithTax() should be "pure virtual", and its subclasses should implement two different versions of this method: Food just returns the price (no tax), while NonFood returns 1.06 \* price (i.e., add 6% tax). Otherwise, Food and NonFood classes don't do anything special.

**You must do each of the following for full credit. I recommend (but do not require) that you go in order listed. Partial credit will be given for partial solutions:**

1. Copy the main.cpp given below.
2. Define the ShoppingCart class (.h and .cpp files). Add the methods but don't write their code (yet).
3. Define the Product class and constructor (with no implementation code yet). Add the methods but don't write their code yet.
4. Define the Food and NonFood classes and constructors (they shouldn't do anything yet). Add the methods but don't write their code (yet).
5. Compile everything by hand. Make sure it compiles cleanly (but the methods still don't do anything). Use this command: `g++ -Wall -g -o shoppingcart *.cpp`
6. Fully define the Product constructor and make sure the Food/NonFood constructors call the parent (Product) constructor.
7. Implement all the methods; decide which STL container to use (vector, list, set, etc.) for itemsInCart private field in ShoppingCart class.
8. Write a Makefile that separately compiles every .cpp to a .o file, then compiles the final program from the .o files.

Add any getters/setters and constructors and destructors that you need.

Use some type of STL container (vector, list, set, etc.) for the internal itemsInCart field.

Don't leak memory.

Use the main.cpp provided below, which should print the following if everything is working:

```
My cart:
 - Peas! ($0.68)
 - Kimchi Korean Marinated Spicy Cabbage ($8.47)
 - Louisville Slugger ($29.99)
Subtotal: $39.14, Total (with tax): $40.9394
My cart (no peas):
 - Kimchi Korean Marinated Spicy Cabbage ($8.47)
 - Louisville Slugger ($29.99)
Subtotal: $38.46, Total (with tax): $40.2594
My cart (empty):
Subtotal: $0, Total (with tax): $0
```

Note, the order of the items printed in the shopping cart summary does not matter.

Here is the main.cpp file:

```
#include <iostream>
using namespace std;

#include "shoppingcart.h"
#include "product.h"
#include "food.h"
#include "nonfood.h"

int main()
{
    ShoppingCart *sc = new ShoppingCart;

    Food *peas = new Food("Peas!", 0.68);
    Food *kimchi = new Food("Kimchi Korean Marinated Spicy Cabbage", 8.47);
    NonFood *slugger = new NonFood("Louisville Slugger", 29.99);

    sc->addItem(peas);
    sc->addItem(kimchi);
    sc->addItem(slugger);

    cout << "My cart:" << endl;
    sc->printSummary();
    cout << "Subtotal: $" << sc->getSubtotal() << ", Total (with tax): $" << sc->getTotalWithTax() << endl;

    sc->removeItem(peas);

    cout << "My cart (no peas):" << endl;
    sc->printSummary();
    cout << "Subtotal: $" << sc->getSubtotal() << ", Total (with tax): $" << sc->getTotalWithTax() << endl;

    sc->clearCart();

    cout << "My cart (empty):" << endl;
    sc->printSummary();
    cout << "Subtotal: $" << sc->getSubtotal() << ", Total (with tax): $" << sc->getTotalWithTax() << endl;

    delete sc;
    delete peas;
    delete kimchi;
    delete slugger;

    return 0;
}
```
