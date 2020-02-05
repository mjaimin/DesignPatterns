Also Known as **Virtual Constructor**
Factory pattern allows user to create an object without exposing the creation logic to the client and refer to newly created object using a common interface.

## Intent

+	Define an interface for creating an object, but let subclasses decide which class to instantiate. Factory Methode lets a class defer instantiation to subclasses.

## Purpose
Enables a class to delegate the responsibility of creating a valid object.

##
![alt text](./Images/Factory-1.md.png "Factory")
##

## Participants

+	IProduct: The interface for products
+	Concrete product: implements the object interface
+	ICreator: Provides the FactoryMethod
+	Concrete creator: Decides which class to instantiate

## Use Factory when

+	A class can’t anticipate the class of objects it must create
+	A class wants its subclasses to specify the objects it creates.
+	A client delegates responsibilities to subclasses in parallel hierarchies.


## Collaborations
+	The creator relies on its subclasses to define the factory method so that it returns an instance of the appropriate subclass

## CONSEQUENCES

**Benefits**

+	The use of factories gives the programmer the opportunity to abstract the specific attributes of an Object into specific subclasses which create them.

+	The Factory Pattern promotes loose coupling by eliminating the need to bind application-specific classes into the code.


**Potential Drawbacks**

+	Clients might have to subclass the creator class just to create a particular concreteProduct object.


