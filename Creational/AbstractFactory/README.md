#Abstract Factory#
Instantiating related objects

**What’s It For?**

+	Sometimes need to instantiate more than one object to get the task done.
+	But what if the thing you need to instantiate changes depending on some variable?


##Intent

+	Provide an interface for creating families of related or dependent objects without specifying their concrete classes

##Purpose
Enables a class to delegate the responsibility of creating a valid object.

##
![alt text](./Images/AbstractFactory-1.md.png "AbstractFactory")
##

##Participants

+	AbstractFactory: Declares an interface for operations that create abstract product objects
+	ConcreteFactory: Implements the operations to create concrete product objects
+	AbstractProduct: Declares an interface for a type of product object
+	ConcreteProduct: Defines a product object to be created by the corresponding +	Concrete factory: Implements the AbstractProduct interface
+	Client: Uses only interfaces declared by AbstractFactory and AbstractProduct classes

##Use Abstract Factory when

+	Need to abstract from details of implementation of products.
+	Need to have multiple families of products.
+	Need to enforce families of products that must be used together.
+	Need to hide product implementations and just present interfaces.



##Collaborations
+	The creator relies on its subclasses to define the factory method so that it 
returns an instance of the appropriate subclass

##CONSEQUENCES

**Benefits**

+	Increases cohesion (by moving unrelated instantiation out of client)
+	Decreases coupling (decouples instantiations from the client)

**Potential Drawbacks**

+	Supporting new Products Means a New Interface 
+	Subclass Specific Operations May Require Runtime Dependent Casting 



