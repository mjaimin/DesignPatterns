## GOF Design Patterns

Creational: **(decouple constructors)** Factory Method, Abstract Factory, Builder, Prototype, Singleton

	Responsible for efficient object creation mechanisms, which increase the flexibility and reuse of existing code.

	Class (change class relationships at compile time)

Structural: **(create large composition)** Adapter, Bridge, Composite, Decorator, Facade, Flyweight, Proxy

	Responsible for building simple and efficient class hierarchies and relations between different classes.

	Class (change class relationships at compile time)

Behavioral: **(divide responsibilities)** Chain of responsibility, Command, Momento, Observer, State, Strategy, Iterator, Mediator, Template, Visitor

	Responsible for the efficient and safe distribution of behaviors among the program's objects.

	Class (change class relationships at compile time)

## Creational patterns
Creational patterns are ones that create objects for you, rather than having you
instantiate objects directly. This gives your program more flexibility in deciding
which objects need to be created for a given case.
+   **Abstract Factory**: Groups object factories that have a common theme.
+   **Builder**: Constructs complex objects by separating construction and
representation.
+   **Factory Method**: Creates objects without specifying the exact class to create.
+   **Prototype creates**: Objects by cloning an existing object.
+   **Singleton**: Restricts object creation for a class to only one instance.

## Behavioral patterns
Most of these design patterns are specifically concerned with communication between objects.
+   **Chain of responsibility**: Delegates commands to a chain of processing objects.
+   **Iterator**: Accesses the elements of an object sequentially without exposing its underlying representation.
+   **Observer**: Is a publish/subscribe pattern which allows a number of observer objects to see an event.

## Structural patterns.
These concern class and object composition. They use inheritance to compose interfaces and define ways to compose objects to obtain new functionality.
+   **Adapter**: Allows classes with incompatible interfaces to work together by wrapping its own interface around that of an already existing class.
+   **Bridge**: Decouples an abstraction from its implementation so that the two can vary independently.
+   **Composite**: Composes zero-or-more similar objects so that they can be manipulated as one object.
+   **Decorator**: Dynamically adds/overrides behaviour in an existing method of an object.
+   **Facade**: Provides a simplified interface to a large body of code.
+   **Proxy**: provides a placeholder for another object to control access, reduce cost, and reduce complexity.


 **Intent** | **Patterns** 
:-----------|:------------
 *Interfaces*    |Adapter, Facade, Composite, Bridge                                       
 *Responsibility*|Singleton, Observer, Mediator, Proxy, Chain Of Responsibility, Flyweight
 *Construction*  |Builder, Factory Method, Abstract Factory, Prototype, Memento            
 *Operations*    |Template Method, State, Strategy, Command, Interpreter                    
 *Extensions*    |Decorator, Iterator, Visitor                                            
 
