## Purpose
Allows for one or more operations to be applied to a set of objects at runtime, decoupling the operations from the object structure.
	
## Intent
Deﬁne an operation to be performed over a complex object structure without changing the elements on which it operates.	Enables new functionality to be performed on a class without affecting its structure.

# Description
The visitor pattern consists of two parts:
a method called Visit() which is implemented by the visitor and is called for every element in the data structure
visitable classes providing Accept() methods that accept a visitor

# Motivation
+	Desire to keep the logic together; as opposed to distributing the code over all classes that can be in the object structure
+	Support frequent addition of new operations

##
![alt text](./Images/Visitor-1.md.png "Visitor")
![alt text](./Images/Visitor-2.md.png "Visitor")
##

## Participant

+	Client
		A class that creates and maintains the object structure; instantiates and calls the Visitors
+	IVisitor
		This is an interface or an abstract class used to declare the visit operations for all the types of visitable classes.
+	Visitor
                For each type of visitor, all the visit methods declared in abstract visitor must be implemented. Each Visitor will be responsible for different operations.
+	Visitable(Element)
		This is an interface which declares the accept operation. This is the entry point which enables an object to be “visited” by the visitor object.
+	ConcreteVisitable (concreteElement)
		These classes implement the Visitable interface or class and defines the accept operation. The visitor object is passed to this object using the accept operation.implements an accept operation that thakes a visitor as an argument
		
# Use Visitor When

+       when you need to perform an operation on a group of similar kind of Objects.
+       With the help of visitor pattern, we can move the operational logic from the objects to another class.
+	When you want to perform an operation on the data contained in a number of objects that have different interfaces. and if you have to perform a number of unrelated operations on these classes.
+	Visitors are a useful way to add function to class libraries or frameworks for which you either do not have the source or cannot change the source for other technical (or political) reasons. In these latter cases, you simply subclass the classes of the framework and add the accept method to each subclass.
+	You have a class hierarchy that is effectively sealed.
+	There are many distinct operations to perform on it.
+	The operations are orthogonal to the core purpose of the types in the hierarchy.
+	You need the flexibility to define new operations over time.
+	An object structure must have many unrelated operations performed upon it.
+	The object structure can’t change but operations performed on it can.
+	Operations must be performed on the concrete classes of an object structure.
+	Exposing internal state or operations of the object structure is acceptable.
+	Operations should be able to operate on multiple object structures that implement the same interface sets.


# CONSEQUENCES

## Benifit
+	Single visitor object is used to visit all elements of the Item classes.
+	If the logic of operation changes, then we need to make change only in the visitor implementation rather than doing it in all the item classes.
+	Adding a new item to the system is easy, it will require change only in visitor interface and implementation. The existing item classes will not be affected.

##Potential Drawbacks
