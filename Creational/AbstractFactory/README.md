README

## Intent ##

Provide an interface for creating families of related or dependent objects without specifying their concrete classes

## Purpose ##

Enables a class to delegate the responsibility of creating a valid object.

## Image ##

![alt text](./Images/AbstractFactory-1.md.png "AbstractFactory")

## Participants ##

+ AbstractFactory: Declares an interface for operations that create abstract product objects
+ ConcreteFactory: Implements the operations to create concrete product objects
+ AbstractProduct: Declares an interface for a type of product object
+ ConcreteProduct: Defines a product object to be created by the corresponding +	Concrete factory: Implements the AbstractProduct interface
+ Client: Uses only interfaces declared by AbstractFactory and AbstractProduct classes

## Applicability ##

+ When a system should be independent of how its products are created, composed, and represented.
+ When a system should be configured with one of multiple families of products or a developer needs to enforce a family of related objects to be used together.
+ Need to hide product implementations and just present interfaces.

## Collaborations ##

The creator relies on its subclasses to define the factory method so that it returns an instance of the appropriate subclass

## Consequences ##

**Benefits**

+ An Abstract Factory isolates concrete classes by encapsulating the process and responsibility of creating
objects.
+ Clients are only able to manipulate instances of objects through the interface.
+ Abstract Factories limit hardware platform dependencies because of the abstract interface.
+ Abstract Factories force consistency among products because all object instances are accessed through the same
interface.
+ Increases cohesion (by moving unrelated instantiation out of client)
+ Decreases coupling (decouples instantiations from the client)

**Potential Drawbacks**

+ Supporting new Products Means a New Interface
+ Supporting new kinds of products is difficult because it requires the extension of the entire interface. In other words, the train factory now has to make boats, which have different process of being made.
+ All of the product objects are returned to the client with the same abstract interface as given by the return type. This means that the client will not be able to access subclass specific operations through the abstract interface.
+ Subclass Specific Operations May Require Runtime Dependent Casting

