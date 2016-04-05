#Introduction

S.O.L.I.D principles are the set of principle fist given by Robert.C.Martin. 

SOLID software system means its allows to build system that is

- Easy to maintain
- Easy to extend
- Easy to understand
- Easy to implement
- Easy to explain

SOLID principles are related with the design and maintenance of software system. Most of the developer mix SOLID principles with OOD principles and Design patterns. Below image that removes confusion of OOD principles and Design patterns

![alt text](./Images/image001.png "Relation")

- **OOD Principle** (Abstraction, Encapsulation, Inheritance, Polymorphism)
- **SOLID principle**
- **Software Design Patterns** (GOF patterns)

#S.O.L.I.D is acronym for

###Single Responsibility Principle
Principle is related to **Designing software module** - a class or a function, **A module should perform only one task**. 

This principle is about Creation.

###Open/Close Principle
Principle is applied after Single Responsibility Principle, again this principle is related to **Designing software module**, class or function. But it about closing already designed thing for modification but opening designed thing for extension i.e. extending functionality. 

This principle is about extension.

###Liskov Substitution Principle
**Principle** is related to substitution of child in place of its parent. 

This principle is about relationship i.e. inheritance.

###Interface Segregation Principle
**Principle** is related to designing of interfaces as one of the basic rules of designing says depends on abstraction. Principle is about design interface such a way, so that client of interface not force to implement not required things. 

So principle is about efficient interface design.

###Dependency Inversion Principle
**Principle** is related to designing decoupling modules, classes of software system. This principle mostly applied after Interface Segregation principle, because interface are one form of abstraction and this principle is related to Details (module/class) should depend on abstraction, and abstraction should not depend on detail. 

This principle is about creating loosely coupled system.