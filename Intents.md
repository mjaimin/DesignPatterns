Intents

## Adapter (Wrapper) ##
**Intent:** Converts the interface of a class into another interface clients expect. This lets classes work together that couldn't otherwise because of incompatible interfaces.

## Bridge (Handle/Body) ##
**Intent:** Decouple (separate) an abstraction from its implementation so that the two can vary independently.

## Composite (Handle/Body) ##
**Intent:** Compose objects into tree structures to represent part-whole hierarchies. Lets clients treat individual objects and compositions of objects uniformly.

## Decorator (Wrapper) ##
**Intent:** Attach additional responsibilities to an object dynamically. Provide a flexible alternative to sub-classing for extending functionality.

## Façade ##
**Intent:** Provide a unified interface to a set of interfaces in a subsystem. Defines a high -level interface that makes the subsystem easier to use.

## Flyweight ##
**Intent:** Use sharing to support large numbers of fine grained objects efficiently.

## Proxy (Surrogate) ##
**Intent:** Provide a surrogate or placeholder for another object to control access to it.

## Chain of Responsibility (Handle/Body) ##
**Intent:** Avoid coupling the sender of a request to its receiver by giving more than one object a chance to handle the request. Chain the receiving objects and pass the request along the chain until an object handles it.

## Command (Action / Transaction) ##
**Intent:** Encapsulate a request as an object, thereby letting you parameterize clients with different requests, queue or log requests, and support undoable operations.

## Interpreter ##
**Intent:** Given a language, define a representation for its grammar along with an interpreter that uses the representation to interpret sentences in the language.

## Iterator (Cursor) ##
**Intent:** Provide a way to access the elements of an aggregate object sequentially without exposing its underlying representation.

## Mediator ##
**Intent:** Define an object that encapsulates how a set of objects interact. Promotes loose coupling by keeping objects from referring to each other explicitly and it lets you vary their interactions independently.

## Memento (Token) ##
**Intent:** Without violating encapsulation, capture and externalize an object's internal state so that the object can be restored to this state later.

## Observer (Dependents, Publish-Subscribe) ##
**Intent:** Define a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.

## State ##
**Intent:** Allow an object to alter its behavior when its internal state changes. The object will appear to change its class.

## Strategy (Policy) ##
**Intent:** Define a family of algorithms, encapsulate each one, and make them interchangeable. Lets the algorithm vary independently from clients that use it.

## Template Method ##
**Intent:** Define the skeleton of an algorithm in an operation, deferring some steps to subclasses. Lets subclasses redefine certain steps of an algorithm without changing the algorithm's structure.

## Visitor (Agent) ##
**Intent:** Represent an operation to be performed on the elements of an object structure. Lets you define a new operation without changing the classes of the elements on which it operates.

## Abstract Factory (Kit) ##
**Intent:** Provides an interface for creating families of related or dependent objects without specifying their concrete class.

## Builder ##
**Intent:** Separate the construction of a complex object from its representing so that the same construction process can create different representations.
                                                                                        
## Factory Method (Virtual Constructor) ##
**Intent:** Define an interface for creating an object, but let subclasses decide which class to instantiate. Lets a class defer instantiation to subclasses.

## Singleton ##
**Intent:** Ensure a class only has one instance and provide a global point of access to it.

## Prototype ##
**Intent:** Specify the kinds of objects to create using a prototypical instance, and create new objects by copying this prototype.
