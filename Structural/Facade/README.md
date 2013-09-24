The Facade pattern provides a simple interface and controls access to a series of complicated interfaces and subsystems.

The role of the service layer is to act as an entry point into the application; sometimes this is known as a facade.

Provide a unified interface to a set of interfaces in a subsystem. Facade defines a higher-level interface that makes the subsystem easier to use

Simplify the interface to a complex subsystem 
Reorganize a system with many subsystems into identifiable layers with single entry points 


participants

    The classes and/or objects participating in this pattern are:

Facade
	knows which subsystem classes are responsible for a request.
	delegates client requests to appropriate subsystem objects.
Subsystem classes
	implement subsystem functionality.
	handle work assigned by the Facade object.
	have no knowledge of the facade and keep no reference to it.