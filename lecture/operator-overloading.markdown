---
layout: default
title: Operator overloading
---

## Arithmetic operators

{% highlight c++ %}

{% endhighlight %}

## Comparison operators

{% highlight c++ %}
bool operator==(const X& lhs, const X& rhs){ /* do actual comparison */ }
bool operator!=(const X& lhs, const X& rhs){return !operator==(lhs,rhs);}
bool operator< (const X& lhs, const X& rhs){ /* do actual comparison */ }
bool operator> (const X& lhs, const X& rhs){return  operator< (rhs,lhs);}
bool operator<=(const X& lhs, const X& rhs){return !operator> (lhs,rhs);}
bool operator>=(const X& lhs, const X& rhs){return !operator<(lhs,rhs);}
{% endhighlight %}
