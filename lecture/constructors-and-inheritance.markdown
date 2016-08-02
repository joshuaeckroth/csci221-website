---
title: Constructors and inheritance
layout: default
---

# Constructors and inheritance

When a class inherits from another class, often the subclass will want
to have its own constructors that refer back to the parent class's
constructors.

## Bank account example

Consider the following class hierarchy:

![Bank Account UML diagram](/images/bankaccount-uml.png "Bank Account UML diagram")

The `BankAccount` class should have a constructor that allows the
`owner` and `balance` properties to be set:

{% highlight cpp %}
class BankAccount
{
    string owner;   // these are private
    double balance;

public:
    BankAccount();
    BankAccount(string _owner);
    BankAccount(string _owner, double _balance);

    // ... other methods
};

// default constructor
BankAccount::BankAccount()
{
    owner = "";
    balance = 0.0;
}

BankAccount::BankAccount(string _owner)
{
    owner = _owner;
    balance = 0.0;
}

BankAccount::BankAccount(string _owner, double _balance)
{
    owner = _owner;
    balance = _balance;
}
{% endhighlight %}

Now, the `MoneyMarketAccount` class should use those constructors in its
own constructors, like so:

{% highlight cpp %}
class MoneyMarketAccount : public BankAccount
{
    int numWithdraws; // private data

    public:
    MoneyMarketAccount();
    MoneyMarketAccount(string _owner);
    MoneyMarketAccount(string _owner, double _balance);
};

MoneyMarketAccount::MoneyMarketAccount()
  : BankAccount()
{
    numWithdraws = 0;
}

MoneyMarketAccount::MoneyMarketAccount(string _owner)
  : BankAccount(_owner)
{
    numWithdraws = 0;
}

MoneyMarketAccount::MoneyMarketAccount(string _owner, double _balance)
  : BankAccount(_owner, _balance)
{
    numWithdraws = 0;
}
{% endhighlight %}

In order to call the parent's constructor, we use the `:` followed by
the parent's constructor function call (e.g. `BankAccount(_owner)`).

## Public, protected, private

The `BankAccount` class above has two private data members (indicated
by the minus signs in the diagram): `owner` and `balance`. Why should
those be private? We don't want to allow other classes or other code
to decide that the owner has changed, or that the balance has changed
without using the `deposit` or `withdraw` function.

Here is how we specify that those variables are private:

{% highlight cpp %}
class BankAccount
{
private: // not necessary; default is private
    string owner;
    double balance;

    // ...
};
{% endhighlight %}

The construct for `BankAccount` (as shown above) sets the values for
`owner` and `balance`, and the `deposit` and `withdraw` functions
change the balance.  However, given a `BankAccount` object
`myaccount`, how do we find out the owner and the balance? These are
private data members, so we are not allowed to do this: `cout <<
myaccount.balance << endl;`

Instead, we would add "getters" and "setters":

{% highlight cpp %}
class BankAccount
{
private: // not necessary; default is private
    string owner;
    double balance;

public:
    string getOwner();
    void setOwner(string _owner);
    double getBalance();

    // ...
};
{% endhighlight %}

Now we can find out the balance like this: `cout <<
myaccount.getBalance() << endl;` Notice there is no function for
changing the balance (except via `deposit` and `withdraw`, which are
not shown here).

A class may also have private methods. For example, maybe both the
`deposit` and `withdraw` methods call a method named
`notifyOwnerByEmail` that send deposit/withdraw receipts to the
owner. This method should *only* be used after a deposit or withdraw,
so there is no reason for other code to call `notifyOwnerByEmail`
directly. Thus, that method should be private, so that only code that
is part of the `BankAccount` class can use the method.

You can also put constructors in the private section. If all constructors are marked as private, then no instances of the object can be created. This is a rarely-used but sometimes necessary feature.

Here is how public/protected/private works in terms of inheritance (copied from [StackOverflow](http://stackoverflow.com/a/1372858)):

{% highlight cpp %}
class A 
{
public:
    int x;
protected:
    int y;
private:
    int z;
};

class B : public A
{
    // x is public
    // y is protected
    // z is not accessible from B
};

class C : protected A
{
    // x is protected
    // y is protected
    // z is not accessible from C
};

class D : private A
{
    // x is private
    // y is private
    // z is not accessible from D
};
{% endhighlight %}

## Post scriptum

> **class** *n. & adj.*
> [Origin: Latin *classis* via *calare*, "to call to arms."] **1**
> *n.* (Object-orienteering) Data members encapsulated with a set of
> methods dying to get at them. **2** *n.* (Marxism) A subset of
> society encapsulated with a set of methods for exploiting and
> exterminating both itself and other subsets of society. **3** *n.*
> (Style) Someth'n' you jest plain got or don't. **4** *adj.* (Of a
> struggle) iterative, as in the attempted modularization of
> real-world activities. -- *The computer contradictionary*

