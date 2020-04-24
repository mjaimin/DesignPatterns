## GOF Design Patterns

## Creational patterns
Creational patterns are ones that create objects for you, rather than having you
instantiate objects directly. This gives your program more flexibility in deciding
which objects need to be created for a given case.
+   **Abstract Factory** groups object factories that have a common theme.
Builder constructs complex objects by separating construction and
representation.
+   **Factory Method** creates objects without specifying the exact class to create.
+   **Prototype creates** objects by cloning an existing object.
+   **Singleton** restricts object creation for a class to only one instance.

## Behavioral patterns
Most of these design patterns are specifically concerned with communication between objects.
+   **Chain of responsibility** delegates commands to a chain of processing objects.
+   **Iterator** accesses the elements of an object sequentially without exposing its underlying representation.
+   **Observer** is a publish/subscribe pattern which allows a number of observer objects to see an event.

## Structural patterns.
These concern class and object composition. They use inheritance to compose interfaces and define ways to compose objects to obtain new functionality.
+   **Adapter** allows classes with incompatible interfaces to work together by wrapping its own interface around that of an already existing class.
+   **Bridge** decouples an abstraction from its implementation so that the two can vary independently.
+   **Composite** composes zero-or-more similar objects so that they can be manipulated as one object.
+   **Decorator** dynamically adds/overrides behaviour in an existing method of an object.
+   **Facade** provides a simplified interface to a large body of code.
+   **Proxy** provides a placeholder for another object to control access, reduce cost, and reduce complexity.


 **Intent** | **Patterns** 
:-----------|:------------
 *Interfaces*    |Adapter, Facade, Composite, Bridge                                       
 *Responsibility*|Singleton, Observer, Mediator, Proxy, Chain Of Responsibility, Flyweight
 *Construction*  |Builder, Factory Method, Abstract Factory, Prototype, Memento            
 *Operations*    |Template Method, State, Strategy, Command, Interpreter                    
 *Extensions*    |Decorator, Iterator, Visitor                                            
 
