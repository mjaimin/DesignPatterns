##GOF Design Patterns

##Creational Patterns
Deal with initializing and configuring classes and objects

  + **Abstract Factory:** Factory for building related objects

  + **Builder:** Separates object construction from its representation

  + **Factory Method:** Creates an instance of several derived classes

  + **Prototype:** A fully initialized instance to be copied or cloned

  + **Singleton:** A class in which only a single instance can exist

##Structural Patterns
Deal with decoupling interface and implementation of classes and objects.

  + **Adapter:** Match interfaces of different classes

  + **Bridge:** Separates an objects abstraction from its implementation

  + **Composite:** Allows a group of objects representing hierarchies to be treated in the same way as a single instance of an object. 

  + **Decorator:** Can dynamically surround a class and allows new behavior to be added to an existing object on the fly.

  + **Facade:** A single class that represents an entire subsystem

  + **Flyweight:** Provides a way to share data among many small classes in an efficient manner. 

  + **Proxy:** An object representing another object or Provides a placeholder to a more complex class that is costly to instantiate.


##Behavioural Patterns
Deal with dynamic interactions among societies of classes and objects.

  + **Mediator:** Defines simplified communication between classes

  + **Memento:** Capture and restore an object's internal state

  + **Interpreter:** A way to include language elements in a program

  + **Iterator:** Sequentially access the elements of a collection

  + **Chain of Responsibility:** Allows commands to be chained together dynamically to handle a request.

  + **Command:** Encapsulate a command request as an object

  + **State:** Alter an object's behaviour when its state changes

  + **Strategy:** Encapsulates an algorithm inside a class

  + **Observer:** A way of notifying change to a number of classes

  + **Template Method:** Defer the exact steps of an algorithm to a 
subclass

  + **Visitor:** Defines a new operation to a class without change


**Categorization of Patterns by Intent**


 **Intent** | **Patterns** 
:-----------|:------------
 *Interfaces*    |Adapter, Facade, Composite, Bridge                                       
 *Responsibility*|Singleton, Observer, Mediator, Proxy, Chain Of Responsibility, Flyweight
 *Construction*  |Builder, Factory Method, Abstract Factory, Prototype, Memento            
 *Operations*    |Template Method, State, Strategy, Command, Interpreter                    
 *Extensions*    |Decorator, Iterator, Visitor                                            
 
