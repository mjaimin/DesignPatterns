README

## Purpose ##

	Supplies a single interface to a set of interfaces within a system.
	Acts as an entry point into the application.

## Intent ##

	Provides a simple interface and controls access to a series of complicated interfaces(subsystems).

##
![alt text](./Images/Facade-1.md "Facade")
![alt text](./Images/Facade-2.md "Facade")


## Participants ##

The **client** uses the simple API of the Facade to perform a task. The client remains unaware of what is really needed to achieve the transaction.
The **Facade** hides the complexities of the system behind its simple API. The Facade knows which subsystem classes are responsible for a request and then delegates to the subsystems and collates the responses.
	Delegates client requests to appropriate subsystem objects.
SubSystemA and SubSystemB perform the work for the client.

## Motivation ##
+	Structuring a system into subsystems helps reduce complexity
+	Subsystems are groups of classes, or groups of classes and other subsystems
+	The interface exposed by the classes in a subsystem or set of subsystems can become quite complex
+	One way to reduce this complexity is to introduce a facade object that provides a single, simplified interface to the more general facilities of a subsystem

A subsystem could consist of a large number of classes. Clients of a subsystem may need to interact with a number of subsystem classes for their needs. This leads to a high degree of coupling between the client objects and the subsystem. The Façade pattern provides a higher level, simplified interface for a subsystem resulting in reduced complexity and dependency. Clients interact with the Façade object to deal with the subsystem instead of interacting directly with subsystem classes. Even though clients interact with the Façade, when needed, a client will be able to access subsystem components directly through the lower level interfaces of the subsystem.

## Use Facade When ##
+	A simple interface is needed to provide access to a complex system.
+	There are many dependencies between system implementations and clients.
+	Systems and subsystems should be layered.

## Consequences ##

**Benefits**
+	It hides the implementation of the subsystem from clients, making the subsystem easier to use
+	It promotes weak coupling between the subsystem and its clients. This allows you to change the classes the comprise the subsystem without affecting the clients.
+	It reduces compilation dependencies in large software systems
+	It simplifies porting systems to other platforms, because it's less likely that building one subsystem requires building all others
+	It does not prevent sophisticated clients from accessing the underlying classes
+	Note that Facade does not add any functionality, it just simplifies interfaces

**Potential Drawbacks**
+	It does not prevent clients from accessing the underlying classes!
