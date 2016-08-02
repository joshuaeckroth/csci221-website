---
layout: default
title: UML
---

# UML

That is, "Unified Modeling Language."

![UML Diagrams](/images/UML_diagrams_overview-highlighted.png)

## Types of diagrams

UML actually specifies 15 types of diagrams. They are mostly distinct from each other, and presumably useful in various circumstances. For our purposes, we'll only focus on the class diagrams.

- Note that class diagrams do not show when/how objects are created and destroyed. A [sequence diagram](http://www.sparxsystems.com/enterprise_architect_user_guide/9.3/standard_uml_models/example_sequence_diagram.html) can do that.
- Class diagrams also do not show how the users interact with the system. A [use case diagram](http://www.sparxsystems.com/enterprise_architect_user_guide/9.3/standard_uml_models/example_use_case_diagram.html) can do that.
- Class diagrams also hide the "logic" of the code, i.e., how actual decisions are made. An [activity diagram](http://www.sparxsystems.com/enterprise_architect_user_guide/9.3/standard_uml_models/example_activity_diagram.html) can show that.

Finally, note that UML is useful for modeling structures and behaviors that have nothing to do with code. You could model [libraries](http://www.uml-diagrams.org/library-domain-uml-class-diagram-example.html) (checking out books, etc.), [airport check-in and screening](http://www.uml-diagrams.org/airport-checkin-uml-use-case-diagram-example.html), [electronic medical prescriptions](http://www.uml-diagrams.org/electronic-prescriptions-activity-diagram-example.html?context=activity-examples), etc.

## Class representation

A class is represented by its name at the top, then its variables ("attributes"), finally its methods. A "-" means private, a "+" means public, and a "#" means protected.

![File class](/images/uml-file-class.png)

## Association

A line between two classes indicates an "association." The word "association" doesn't mean much; just that the two classes are somehow related. This is important to know because it means that if one of the classes is modified, the other might need to be updated as well.

In the two examples below, we have a File associated with a User via its "owner" attribute, and a Student associated with a Class via its "enrolled" attribute. The File can have one User, while a Student can be in zero or more Classes.

![File user association](/images/uml-file-association.png)

![Student class association](/images/uml-student-class.png)

## Aggregation

A class "aggregates" another class if the first class has a collection of objects of the second class. Aggregation is like Composition, described below, but it's a "weak" form of composition. They differ in one important way: if class A aggregates objects of class B, then A is not responsible for the "lifecycle" (creating/deleting) objects of class B. So if an object of class A is deleted, it does not need to delete the stuff it aggregated; some other code will take care of that.

In the two examples below, a User has friends, but deleting the User should not cause her friends to be deleted as well. Likewise, a Player has some Items in his inventory, but deleting the Player should not delete the Items as well. Likewise, the Player class probably does not create objects in the Item class either. The User and Player are not responsible for the "lifecycle" of the objects they aggregate.

![Aggregation examples](/images/uml-aggregation.png)

## Composition

Composition is like Aggregation because it means the class A has a collection of objects of class B whenever A is a "composition" of B. However, Composition is different than Aggregation because the composite class is responsible for the "lifecycle" of the objects it composes. Thus, if you delete the composing object, it will need to delete the stuff it holds in its collection.

In the examples below, a Directory has a composition of Files. This means that if the Directory object is deleted, it will need to delete the collected File objects. This makes sense because every File has to be in some Directory. Likewise, a Spreadsheet is composed of Rows, and when the Spreadsheet is deleted, so are the Rows.

![Directory-File composition](/images/uml-directory-file-composition.png)

## Inheritance

Inheritance is the familiar superclass/subclass relationship. It's also called "generalization" since the parent class is a generalization of the child class. The examples below should be clear. Note that the Shape class has a "virtual" (or possibly "pure virtual") method, which is overloaded or concretized in the Ellipse class (refer to the [polymorphism](/lecture/polymorphism.html) notes).

![Inheritance examples](/images/uml-inheritance-examples.png)

## Dependency

A class is dependent on another if it uses objects of the second class but does not have a strict inheritance, composition, or aggregation relation. Dependency is a kind of association link but more often directed. The example below shows that the Room class depends on the LinkedList class to keep track of linked rooms, but the LinkedList class does not depend on the Room class (it has no idea the Room class exists). It's good to document dependencies so you know which classes might need to be updated if the dependent class changes its behavior.

![Room / LinkedList dependency](/images/uml-room-linkedlist-dep.png)

## Interfaces

Finally, a class may implement an interface, which we show with a "lollipop" diagram. The interface is the lollipop. C++ does not have interfaces explicitly, while Java does. But we can create abstract classes in C++ (classes with at least one pure virtual method), or even classes where all methods are pure virtual and there are no class variables, and thus get approximately the same thing as a Java interface.

![List interface](/images/uml-interface-list.png)

## Guidelines for writing UML

- Use human-readable names rather than coding syntax
- Use nouns for class names
- Use verbs for method names
- Do not include every class variable and method; avoid showing obvious elements like constructors and pointers to objects already shown in the diagram (as association links, for example)

## UML editors

Check out these free packages:

- [StarUML](http://staruml.io/) -- supports drawing class diagrams; you can download a Java code generator and reverse engineering tool from the StarUML program, but I don't think it's too sophisticated yet.
- [Dia](http://dia-installer.de/) -- supports drawing class diagrams and lots of other (non-UML) kinds of diagrams.
- [Doxygen](http://www.stack.nl/~dimitri/doxygen/) -- generates class diagrams and source code listings from your code; see the [documentation](/lecture/documentation.html) notes on this site.

