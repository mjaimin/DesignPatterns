# Template Structure #

## Basic Elements of a Design Pattern ##

Each pattern has four essential elements:

### Pattern name ###

Naming a pattern immediately increases the design vocabulary of programmers. Having a vocabulary for patterns enables to talk about patterns with other programmers, in the documentation, etc

### Problem ###

The problem describe specific design problem and when to apply the pattern. Problem may also includes a list of conditions that must be met before it makes sense to apply the pattern.

### Solution ###

The solution describes the elements that make up the design, their relationships, responsibilities, and collaborations. The solution doesn’t describe a particular concrete design or implementation, because a pattern is like a template that can be applied in many different situations. Instead, the pattern provides an abstract description of a design problem and how a general arrangement of elements (classes and objects) solves it.

### Consequences ###

The consequences are the results and trade-offs of applying the pattern. They may address language and implementation issues as well. Since reuse is often a factor in object-oriented design, the consequences of a pattern include its impact on a system’s flexibility, extensibility, or portability.

## Describing Design Patterns ##

The Gang of Four used a consistent format to describe patterns.  They developed a template for describing a design pattern.  This template describes a design pattern with:

+ Pattern name
  + Intent of the design pattern
+ Motivation
  + describes a typical scenario that illustrates the design problem
+ Applicability
  + when we can apply the design pattern
+ Structure
  + a graphical representation of the classes and their collaborations in the pattern
+ Consequences of the design pattern
+ Implementation and the sample code
+ Related patterns

## Classification of Design Patterns ##

Design patterns can be classified by two criteria:

### Purpose ###

which reflects what a pattern does. Patterns can have creational, structural or behavioural purpose.

+ Creational patterns concern the process of object creation
+ Structural patterns deal with the composition of classes and objects
+ Behavioural patterns characterize the ways in which classes and objects interact and distribute responsibility

### Scope ###

which specifies whether the pattern applies primarily to classes or to objects:

+ Class patterns deal with relationships between classes and their subclasses. These relationships are established through inheritance, so they are static.
+ Object patterns deal with object relationships, which can be changed at run-time and are more dynamic.

![alt text](./Images/ClassificationOfDesignPatterns.PNG "Classification Of Design Patterns")

## Creational Design Patterns ##

+ Creational design patterns abstract the instantiation process. They help make a system independent of how its objects are created, composed, and represented.
+ Replace explicit creation problems, prevent platform dependencies
+ Allow to abstract from complex instantiation processes
+ Make the system independent from the way its objects are created, composed and represented.

+ A **class creational** pattern uses inheritance to vary the class that’s instantiated
+ An **object creational** pattern will delegate instantiation to another object.

## Structural Design Patterns ##

+ Structural patterns are concerned with how classes and objects are composed to form larger structures.
+ Handle unchangeable classes, lower coupling and offer alternatives to inheritance
+ Reduce coupling between two or more classes
+ Introduce an abstract class to enable future extensions
+ Encapsulate complex structures
+ A **class Structural** patterns use inheritance to compose interfaces or implementations. For example, multiple inheritance can be seen as a kind of structural design patterns, since it uses inheritance to mix two or more classes into a new one.
+ Rather than composing interfaces or implementations, **object structural** patterns describe ways to compose objects to realize new functionality. The added flexibility of object composition comes from the ability to change the composition at run-time, which is impossible with static class composition.

## Behavioural Design Patterns ##

+ Behavioural patterns are concerned with algorithms and the assignment of responsibility between objects. Behavioural patterns describe not just patterns of objects or classes but also the patterns of communication between them. These patterns characterize complex control flow that is difficult to follow at run-time. They shift your focus away from flow of control to let you concentrate just on the way objects are interconnected.
+ Hide implementation, hides algorithms, allows easy and dynamic configuration of objects
+ Allow a choice between algorithms and the assignment of responsibilities to objects ("Who does what?")
+ Characterize complex control flows that are difficult to follow at runtime
+ **Class Behavioural** patterns use inheritance to distribute behaviour between classes.
+ **Object Behavioural** patterns use object composition rather than inheritance.

### Intent ###

Short description of the pattern & its purpose

### Motivation ###

Describes a typical scenario that illustrates the design problem

### Applicability ###

circumstances in which pattern applies

### Structure ###

graphical representation of the pattern using modified UML notation

### Participants ###

participating classes and/or objects & their responsibilities

### Collaborations ###

how participants cooperate to carry out their responsibilities

### Consequences ###

the results of application, benefits, liabilities

### Implementation ###

pitfalls, hints, techniques, plus language-dependent issues

### Sample Code ###

sample implementations in C++, Java, C#, Smalltalk, C, etc.
