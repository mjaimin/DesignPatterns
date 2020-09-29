README

## Purpose
Allows for one or more operations to be applied to a set of objects at runtime, decoupling the operations from the object structure.

## Intent ##
Deﬁne an operation to be performed over a complex object structure without changing the elements on which it operates.	Enables new functionality to be performed on a class without affecting its structure.
OR
Represent an operation to be performed on the elements of an object structure.
Define a new operation without changing the classes of the elements on which it operates

## Description ##
The visitor pattern consists of two parts:
a method called Visit() which is implemented by the visitor and is called for every element in the data structure
visitable classes providing Accept() methods that accept a visitor

## Motivation ##
+	Desire to keep the logic together; as opposed to distributing the code over all classes that can be in the object structure
+	Support frequent addition of new operations

##
![alt text](./Images/Visitor-1.md.png "Visitor")
![alt text](./Images/Visitor-2.md.png "Visitor")
##

## Participants ##

+	**Visitor**
		This is an interface or an abstract class used to declare the visit operations for all the types of visitable classes.
+	**ConcreteVisitor**
		Implements each operation declared by Visitor. Each operation implements a fragment of the algorithm defined for the corresponding class of object in the structure. ConcreteVisitor provides the context for the algorithm and stores its local state. This state often accumulates results during the traversal of the structure.
+	**Element(Visitable)**
		This is an interface which declares the accept operation. This is the entry point which enables an object to be “visited” by the visitor object.
+	**ConcreteElement (ConcreteVisitable)**
		Implements an Accept operation that thakes a visitor as an argument. These classes implement the Visitable interface or class and defines the accept operation. The visitor object is passed to this object using the accept operation.
+	**ObjectStructure**
		Can enumerate its elements.
		May provide a high-level interface to allow the visitor to visit its elements.
		May either be a composite or a collection such as a list or a set

# Use Visitor When ##
+	An object structure contains many classes of objects with differing interfaces, and you want to perform operations on these
objects that depend on their concrete classes.
+	Classes defining the object structure rarely change, but operations performed on it can.
+	Exposing internal state or operations of the object structure is acceptable.

## Consequences ##

## Benifit
+	Saperates the algorithm from the data structure
+	Single visitor object is used to visit all elements of the Item classes.
+	If the logic of operation changes, then we need to make change only in the visitor implementation rather than doing it in all the item classes.
+	Adding a new item to the system is easy, it will require change only in visitor interface and implementation. The existing item classes will not be affected.

## Potential Drawbacks
+	Adding new Concrete Element classes is complicated
+	Allowing a Visitor to access the internal state of a Concrete Element breaks encapsulation

## Misc
+	The Visitor pattern enables the definition of a new operation on an object structure without changing the classes of the objects. The price has been that the set of classes must be fixed in advance, and they must each have a so-called accept method.
