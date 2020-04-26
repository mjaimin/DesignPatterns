Class (change class relationships at compile time)

**Factory Method**
is a creational design pattern that provides an interface for creating objects in superclass, but allow subclasses to alter the type of objects that will be created.

(Subclass of object that is instantiated can vary)

+	**Purpose**
Exposes a method for creating objects, allowing subclasses to control the actual creation process.
+	**Use When**
	+	A class will not know what classes it will be required to create.
	+	Subclasses may specify what objects should be created.
	+	Parent classes wish to defer creation to their subclasses.

object (change object relationships at runtime)

**Abstract Factory**
is a creational design pattern that lets you produce families of related objects without specifying their concrete classes.

(Families of product objects can vary)
+	**Purpose**
	Provide an interface that delegates creation calls to one or more concrete classes in order to deliver specific objects.
+	**Use When**
	+	The creation of objects should be independent of the system utilizing them.
	+	Systems should be capable of using multiple families of objects.
	+	Families of objects must be used together.
	+	Libraries must be published without exposing implementation details.
	+	Concrete classes should be decoupled from clients.

object (change object relationships at runtime)

**Builder**
is a creational design pattern that lets you produce different types and representations of an object using the same building process. Builder allows constructing complex objects step by step.

(How a composite object gets created can vary)
+	**Purpose**
Allows for the dynamic creation of objects based upon easily interchangeable algorithms.
+	**Use When**
	+	Object creation algorithms should be decoupled from the system.
	+	Multiple representations of creation algorithms are required.
	+	The addition of new creation functionality without changing the core code is necessary.
	+	Runtime control over the creation process is required.

director = new Director();
CarBuilder builder = new CarBuilder();
director.constructSportsCar(builder);
Car car = builder.getResult();

object (change object relationships at runtime)

**Prototype**
is a creational design pattern that lets you produce new objects by copying existing ones without compromising their internals.

(Class of object that is instantiated can vary)
+	**Purpose**
Create objects based upon a template of an existing objects through cloning.
+	**Use When**
	+	Composition, creation, and representation of objects should be decoupled from a system.
	+	Classes to be created are specified at runtime.
	+	A limited number of state combinations exist in an object.
	+	Objects or object structures are required that are identical or closely resemble other existing objects or object structures.
	+	The initial creation of each object is an expensive operation.
private Shape clone() {
    return new Circle(this);
}

object (change object relationships at runtime)

**Singleton**
is a creational design pattern that lets you ensure that a class has only one instance and provide a global access point to this instance.
(The sole instance of a class can vary)
+	**Purpose**
Ensures that only one instance of a class is allowed within a system.
+	**Use When**
	+	Exactly one instance of a class is required.
	+	Controlled access to a single object is necessary.
	+	Structural -- (create large composition)
	+	Responsible for building simple and efficient class hierarchies and relations between different classes.

Class (change class relationships at compile time)

**Adapter**
is a structural design pattern that allows objects with incompatible interfaces to collaborate.

(Interface to an object can vary)
+	**Purpose**
Permits classes with disparate interfaces to work together by creating a common object by which they may communicate and interact.
+	**Use When**
	+	A class to be used doesn’t meet interface requirements.
	+	Complex conditions tie object behavior to its state.
	+	Transitions between states need to be explicit.
public class SquarePegAdapter extends RoundPeg {
    private SquarePeg peg;

    public SquarePegAdapter(SquarePeg peg) {
        this.peg = peg;
    }

    public SquarePeg getRadius(){
        // Get half of the diagonal's length using the Pythagorean equation.
        return  Math.sqrt(2 * Math.pow(peg.getWidth(), 2))/ 2;
    }
}

object (change object relationships at runtime)

**Bridge**
is a structural design pattern that lets you split a giant class or a set of closely related classes into two separate hierarchies, abstraction and implementation, which can be developed independently of each other.

(Implementation of an object can vary, let abstractions and implementations vary independently)
+	**Purpose**
Defines an abstract object structure independently of the implementation object structure in order to limit coupling.
+	**Use When**
	+	Abstractions and implementations should not be bound at compile time.
	+	Abstractions and implementations should be independently extensible.
	+	Changes in the implementation of an abstraction should have no impact on clients.
	+	Implementation details should be hidden from the client.


object (change object relationships at runtime)

**Composite**
is a structural design pattern that lets you compose objects into tree structures and allow clients to work with these structures as if they were individual objects.

(Structure and composition of an object can vary)
+	**Purpose**
Facilitates the creation of object hierarchies where each object can be treated independently or as a set of nested objects through the same interface.
+	**Use When**
	+	Hierarchical representations of objects are needed.
	+	Objects and compositions of objects should be treated uniformly.

object (change object relationships at runtime)

**Decorator (Wrapper)**
is a structural design pattern that lets you attach new behaviors to objects by placing them inside wrapper objects that contain these behaviors.

(Responsibilities of an object without subclassing can vary)
+	**Purpose**
Allows for the dynamic wrapping of objects in order to modify their existing responsibilities and behaviors.
+	**Use When**
	+	Object responsibilities and behaviors should be dynamically modifiable.
	+	Concrete implementations should be decoupled from responsibilities and behaviors.
	+	Subclassing to achieve modification is impractical or impossible.
	+	Specific functionality should not reside high in the object hierarchy.
	+	A lot of little objects surrounding a concrete implementation is acceptable.

object (change object relationships at runtime)

**Facade**
is a structural design pattern that lets you provide a simplified interface to a complex system of classes, library or framework.

(Interface to a subsystem can vary)
+	**Purpose**
Supplies a single interface to a set of interfaces within a system.
+	**Use When**
	+	A simple interface is needed to provide access to a complex system.
	+	There are many dependencies between system implementations and clients.
	+	Systems and subsystems should be layered.

object (change object relationships at runtime)

**Flyweight**
is a structural design pattern that lets you fit more objects into the available amount of RAM by sharing common parts of object state among multiple objects, instead of keeping it in each object.
+	**Purpose**
Facilitates the reuse of many fine grained objects, making the utilization of large numbers of objects more efficient.
+	**Use When**
	+	Many like objects are used and storage cost is high.
	+	The majority of each object’s state can be made extrinsic.
	+	A few shared objects can replace many unshared ones.
	+	The identity of each object does not matter.
	+	Divide fields of a class that should become a flyweight into two parts:
	+	intrinsic state: fields that contain unchanging data, duplicate across many objects;
	+	extrinsic state: fields that contain contextual data, unique for all objects

object (change object relationships at runtime)

**Proxy (Surrogate)**
is a structural design pattern that lets you provide a substitute or placeholder for another object to control access to it.

(How an object is accessed can vary; its location can vary)
+	**Purpose**
Allows for object level access control by acting as a pass through entity or a placeholder object.
+	**Use When**
	+	The object being represented is external to the system.
	+	Objects need to be created on demand.
	+	Access control for the original object is required.
	+	Added functionality is required when an object is accessed.
	+	Behavioral (divide responsibilities)
	+	Responsible for the efficient and safe distribution of behaviors among the program's objects.


Class (change class relationships at compile time)

**Iterator**
is a behavioral design pattern that lets you access the elements of an aggregate object sequentially without exposing its underlying representation.
+	**Purpose**
Allows for access to the elements of an aggregate object without allowing access to its underlying representation.
+	**Use When**
	+	Access to elements is needed without access to the entire representation.
	+	Multiple or concurrent traversals of the elements are needed.
	+	A uniform interface for traversal is needed.
	+	Subtle differences exist between the implementation details of various iterators.

Class (change class relationships at compile time)

**Template Method**
is a behavioral design pattern that lets you define the skeleton of an algorithm and allow subclasses to redefine certain steps of the algorithm without changing its structure.
+	**Purpose**
Identifies the framework of an algorithm, allowing implementing classes to define the actual behavior.
+	**Use When**
A single abstract implementation of an algorithm is needed.
Common behavior among subclasses should be localized to a common class.
Parent classes should be able to uniformly invoke behavior in their subclasses.
Most or all subclasses need to implement the behavior.


object (change object relationships at runtime)

**Chain of Responsibility**
is a behavioral design pattern that lets you avoid coupling the sender of a request to its receiver by giving more than one object a chance to handle the request. Chain the receiving objects and pass the request along the chain until an object handles it.
+	**Purpose**
Gives more than one object an opportunity to handle a request by linking receiving objects together.
+	**Use When**
	+	Multiple objects may handle a request and the handler doesn’t have to be a specific object.
	+	A set of objects should be able to handle a request with the handler determined at runtime.
	+	A request not being handled is an acceptable potential outcome.

object (change object relationships at runtime)

**Command**
is a behavioral design pattern that lets you turn a request into stand-alone object, which can be used to parametrize objects with different requests, queue or log requests, and support undoable operations.
+	**Purpose**
Encapsulates a request allowing it to be treated as an object. This allows the request to be handled in traditionally object based relationships such as queuing and callbacks.
+	**Use When**
	+	You need callback functionality.
	+	Requests need to be handled at variant times or in variant orders.
	+	A history of requests is needed.
	+	The invoker should be decoupled from the object handling the invocation.

object (change object relationships at runtime)

**Mediator**
is a behavioral design pattern that lets you define an object that encapsulates relations between a set of objects to make them independent of each other.

(encapsulates relations between a set of objects)
+	**Purpose**
Allows loose coupling by encapsulating the way disparate sets of objects interact and communicate with each other. Allows for the actions of each object set to vary independently of one another.
+	**Use When**
	+	Communication between sets of objects is well defined and complex.
	+	Too many relationships exist and common point of control or communication is needed.

object (change object relationships at runtime)

**Memento**
is a behavioral design pattern that lets you capture the object's internal state without exposing its internal structure, so that the object can be returned to this state later.

(capture the object's internal state)
+	**Purpose**
Allows for capturing and externalizing an object’s internal state so that it can be restored later, all without violating encapsulation.
+	**Use When**
	+	The internal state of an object must be saved and restored at a later time.
	+	Internal state cannot be exposed by interfaces without exposing implementation.
	+	Encapsulation boundaries must be preserved.

object (change object relationships at runtime)

**Observer**
is a behavioral design pattern that lets you define a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.

(one-to-many dependency)
+	**Purpose**
Lets one or more objects be notified of state changes in other objects within the system.
+	**Use When**
	+	State changes in one or more objects should trigger behavior in other objects
	+	Broadcasting capabilities are required.
	+	An understanding exists that objects will be blind to the expense of notification.

object (change object relationships at runtime)

**State**
is a behavioral design pattern that allows an object to alter its behavior when its internal state changes. The object will appear to change its class.

(alter its behavior when its internal state changes)
+	**Purpose**
Ties object circumstances to its behavior, allowing the object to behave in different ways based upon its internal state.
+	**Use When**
	+	The behavior of an object should be influenced by its state.
	+	Complex conditions tie object behavior to its state.
	+	Transitions between states need to be explicit.

object (change object relationships at runtime)

**Strategy**
is a behavioral design pattern that lets you define a family of algorithms, encapsulate each one, and make them interchangeable. Strategy lets the algorithm vary independently from the clients that use it.

(vary independently from the clients)
+	**Purpose**
Defines a set of encapsulated algorithms that can be swapped to carry out a specific behavior.
+	**Use When**
	+	The only difference between many related classes is their behavior.
	+	Multiple versions or variations of an algorithm are required.
	+	Algorithms access or utilize data that calling code shouldn’t be exposed to.
	+	The behavior of a class should be defined at runtime.
	+	Conditional statements are complex and hard to maintain.

object (change object relationships at runtime)

**Visitor**
is a behavioral design pattern that lets you define a new operation without changing the classes of the objects on which it operates.
+	**Purpose**
Allows for one or more operations to be applied to a set of objects at runtime, decoupling the operations from the object structure.
+	**Use When**
	+	An object structure must have many unrelated operations performed upon it.
	+	The object structure can’t change but operations performed on it can.
	+	Operations must be performed on the concrete classes of an object structure.
	+	Exposing internal state or operations of the object structure is acceptable.
	+	Operations should be able to operate on multiple object structures that implement the same interface sets.
