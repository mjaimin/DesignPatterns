**Catalog and organization of catalog**
+    We classify design patterns by two criteria. The first criterion, called purpose, reflects what a pattern does. Patterns can have a creational, structural, or behavioral purpose. Creational patterns concern the process of object creation. Structural patterns deal with the composition of classes or objects. Behavioral patterns characterize how classes or objects interact and distribute responsibility.
+    The second criterion, called a scope, specifies whether the pattern applies primarily to classes or to objects. Class patterns deal with relationships between classes and their subclasses. These relationships are established through inheritance, so they are static—fixed at compile-time. Object patterns deal with object relationships, which can be changed at run-time and are more dynamic. - - 

**Design Patterns to solve design problems**
+    Design patterns solve many of the day-to-day problems object-oriented designers face, and in many different ways. Here are several of these problems and how design patterns solve them. 
1.	**Finding Appropriate Objects**
    +    Object-oriented programs are made up of objects.
    +    An object packages both data and the procedures that operate on that data. The procedures are typically called methods or operations.
    +    An object performs an operation when it receives a request (or message) from a client.
    +    Object-oriented design methodologies favor many different approaches.
    +    You can write a problem statement, single out the nouns and verbs, and create corresponding classes and operations.
    +    Or you can focus on the collaborations and responsibilities in your system.
    +    Or you can model the real world and translate the objects found during analysis into the design.
    +    There will always be disagreement on which approach is best. 
2.	**Determining Object Granularity**
    +    Objects can vary tremendously in size and number.
    +    The Facadepattern describes how to represent complete subsystems as objects, and the Flyweight pattern describes how to support huge numbers of objects at the finest granularities.
    +    Other design patterns describe specific ways of decomposing an object into smaller objects.
    +    Abstract Factory and Builder yield objects whose only responsibilities are creating other objects.
    +    Visitor and Command yield objects whose only responsibilities are to implement a request on another object or group of objects.
3.	**Specifying Object Interface.**
    +    Every operation declared by an object specifies the operation's name, the objects it takes as parameters, and the operation's return value. This is known as the operation's signature.
    +    The set of all signatures defined by an object's operations is called the interface to the object.
    +    An object's interface characterizes the complete set of requests that can be sent to the object. 
    +    Any request that matches a signature in the object's interface may be sent to the object.
    +    Interfaces are fundamental in object-oriented systems.
    +    Objects are known only through their interfaces.
    +    There is no way to know anything about an object or to ask it to do anything without going through its interface.
    +    An object's interface says nothing about its implementation — different objects are free to implement requests differently.
    +    That means two objects having completely different implementation scans have identical interfaces.
4.	**Specifying Object Implementations.**
    +    An object's implementation is defined by its class.
    +    The class specifies the object's internal data and representation and defines the operations the object can perform.
    +    Our OMT-based notation depicts a class as a rectangle with the class name in bold.
    +    Operations appear in the normal type below the class name.
    +    Any data that the class defines comes after the operations;
    +    Lines separate the class name from the operations and the operations from the data:
    +    Return types and instance variable types are optional since we don't assume a statically typed implementation language.
    +    Objects are created by instantiating a class.
    +    The object is said to be an instance of the class.
    +    The process of instantiating a class allocates storage for the object's internal data and associates the operations with these data.
    +    Many similar instances of an object can be created by instantiating a class.
    +    A dashed arrowhead line indicates a class that instantiates objects of another class.
    +    The arrow points to the class of the instantiated objects.
    +    New classes can be defined in terms of existing classes using class inheritance.
    +    When a subclass inherits from a parent class, it includes the definitions of all the data and operations that the parent class defines.
    +    Objects that are instances of the subclass will contain all data defined by the subclass and its parent classes, and they'll be able to perform all operations defined by this subclass and its parents.
    +    We indicate the subclass relationship with a vertical line and a triangle:
    +    An abstract class is one whose main purpose is to define a common interface for its subclasses.
    +    An abstract class will defer some or all of its implementation to operations defined in subclasses; hence an abstract class cannot be instantiated.
    +    The operations that an abstract class declares but doesn't implement are called abstract operations.
    +    Classes that aren't abstract are called concrete classes.
    +    Subclasses can refine and redefine the behaviors of their parent classes.
    +    More specifically, a class may override an operation defined by its parent class. 

**How to Select a Design Pattern**
+    With more than 20 design patterns in the catalog to choose from, it might be hard to find the one that addresses a particular design problem, especially if the catalog is new and unfamiliar to you.
+    Here are several different approaches to finding the design pattern that's right for your problem:
1.  **Consider how design patterns solve design problems.**
    Design patterns help you find appropriate objects, determine object granularity, specify object interfaces, and several other ways in which design patterns solve design problems. Referring to these discussions can help guide your search for the right pattern.
2.  **Scan Intent sections.**
    Lists the Intent sections from all the patterns in the catalog. Read through each pattern's intent to find one or more that sounds relevant to your problem.
3.  **Study how patterns interrelate.**
    Relationships between design patterns graphically. Studying these relationships can help direct you to the right pattern or group of patterns.
4.  **Study patterns of like purpose.**
    The catalog has three chapters, one for creational patterns, another for structural patterns, and a third for behavioral patterns. Each chapter starts with introductory comments on the patterns and concludes with a section that compares and contrasts them. These sections give you insight into the similarities and differences between patterns of like purpose.
5.  **Examine a cause of redesign.**
    Look at the causes of the redesign, Then look at the patterns that help you avoid the causes of the redesign.
6.  **Consider what should be variable in your design.**
    This approach is the opposite of focusing on the causes of the redesign. Instead of considering what might force a change to a design, consider what you want to be able to change without redesign.

**Use a DesignPattern**
+    Once you've picked a design pattern, how do you use it? Here's a step-by-step approach to applying a design pattern effectively:
1.  **Read the pattern once through for an overview.** 
    Pay particular attention to the Applicability and Consequences sections to ensure the pattern is right for your problem.
2.  **Go back and study the Structure, Participants, and Collaborations sections.** 
    Make sure you understand the classes and objects in the pattern and how they relate to one another.
3.  **Look at the Sample Code section to see a concrete example of the pattern in code.**
    Studying the code helps you learn how to implement the pattern.
4.  **Choose names for pattern participants that are meaningful in the application context.**
    The names for participants in design patterns are usually too abstract to appear directly in an application. Nevertheless, it's useful to incorporate the participant name into the name that appears in the application. That helps make the pattern more explicit in the implementation. For example, if you use the Strategy pattern for a text compositing algorithm, then you might have classes SimpleLayoutStrategyor TeXLayoutStrategy.
5.  **Define the classes.**
    Declare their interfaces, establish their inheritance relationships, and define the instance variables that represent data and object references. Identifyexistingclasses in your application that the pattern will affect, and modify them accordingly.
6.  **Define application-specific names for operations in the pattern.**
    Here again, the names generally depend on the application. Use the responsibilities and collaborations associated with each operation as a guide. Also, be consistent in your naming conventions. For example, you might use the "Create-" prefix consistently to denote a factory method.
7.  **Implement the operations to carry out the responsibilities and collaborations in the pattern.**
    The Implementationsectionoffershints to guide you in the implementation. The examples in the Sample Code section can help as well. Shubham Narkhede 6th Semester CSE, Design Patterns
