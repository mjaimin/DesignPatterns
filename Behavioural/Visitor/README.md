##Purpose
	Allows for one or more operations to be applied to a set of objects at runtime, decoupling the operations from the object structure.
	
##Intent
	Deﬁne an operation to be performed over a complex object structure without changing the elements on which it operates.
##Intent
	To write a traversal algorithm of a set of data such that the traversal can be reused for many different operations.
##Intent
	Visitor design pattern represents an operation to be performed on the elements of an object structure. Visitor lets you define a new operation without changing classes of the elements on which it operates.

##Role
	The Visitor pattern defines and performs new operations on all the elements of an existing structure, without altering its classes.

##Visitor
	Enables new functionality to be performed on a class without affecting its structure.
	
##Use When
+	You should consider using a Visitor pattern when you want to perform an operation on the data contained in a number of objects that have different interfaces. and if you have to perform a number of unrelated operations on these classes.
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


##Participant

Client
	A class that creates and maintains the object structure; instantiates and calls the Visitors
ObjectStructure
	A composite structure of several related element types
Element
	The root element type for the object structure
ElementA and ElementB
	Subclasses of Element
IVisitor
	An interface for all the Visitor classes
Visitor1 and Visitor2
	Classes that contain methods that iterate through the object structure and apply operations to its elements

#Participants

Visitor
+	declare a visit operation for each class of ConcreteElement in the object structure. The operation’s name/signature identiﬁes the class that sends the Visit request to the visitor. That lets the visitor determine the concrete class of the element being visited.The element can then be accessed directly through its particular interface.

ConcreteVisitor
+	implements each operation declared by Visitor. Each operation implements a fragment of the algorithm deﬁned for the corresponding class of objects in the structure. ConcreteVisitor provides the context for the algorithm and stores its local state.
Element
+	deﬁnes an accept operation that takes a visitor as an argument

ConcreteElement
+	implements an accept operation that thakes a visitor as an argument
ObjectStructure
+	can enumerate its element; may provide a high level ifc to visit elements;either a composite or a collection