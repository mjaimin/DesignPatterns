## Purpose
Identifies the framework of an algorithm, allowing implementing classes to define the actual behavior.

## Intent
Defines the skeleton of an algorithm in a method, deferring some steps to subclasses. Template method lets subclasses redefine certain steps of an algorithm without changing the algorithm’s structure.

## Description

## Motivation
Sometimes you want to specify the order of operations that a method uses, but allow subclasses to provide their own implementations of some of these operations

##
![alt text](./Images/Template-1.md.png "Template Design Pattern")
##

## Participant
### Abstract class
+   Defines abstract primitive operations that concrete subclasses define to implement steps of an algorithm.
+   Implements a template method defining the skeleton of an algorithm. The template method calls primitive operations as well as operations defined in AbstractClass or those of other objects.

### Concrete class
+   Implements the primitive operations to carry out subclass-specific steps of the algorithm.

## Collaborations
+   ConcreteClass relies on AbstractClass to implement the invariant steps of the algorithm.

## Use Template When
+   To implement the invariant parts of an algorithm once in base class and leave it up to subclasses to implement the behavior that can vary
+   To localize common behavior among subclasses and place it in a common class (in this case, a superclass) to avoid code duplication. This is a classic example of ”code refactoring.”
+   We want to avoid code duplication, implementing variations of the algorithm in subclasses
+   We want to control the point that sub classing is allowed.

## CONSEQUENCES

## Benifit


## Potential Drawbacks
+   Operations which must be overridden by a subclass should be made abstract
+   If the template method itself should not be overridden by a subclass,it should be made final
+   In a template method, the parent class calls the operations of a subclass and not the other way around. This is an inverted control structure that’s sometimes referred to as "the Hollywood principle," as in, "Don't call us, we'll call you".
+   When inheritance is used as the way to add new functionality, it becomes impossible to add functionality in more than one axis at the same time without defining more and more classes.  This kind of system can rapidly become fragile. Changes at any one level can disturb operation above or below that level in the template methods. There is often a feeling of unpredictability when adding new functionality as it difficult to predict how behavior will change in all cases. You often also tend to build finer and finer tweaks by splitting the algorithmic parts of the template class and inserting more layers, thus exacerbating the problem.


## Misc

## Guideline
Use Template Methods to delegate to subclasses.



