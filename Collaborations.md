## Abstract Factory (Kit) ##
+	Normally a single instance of a ConcreteFactory class is created at run-time. This concrete factory creates product objects having a particular implementation. To create different product objects, clients should use a different concrete factory.
+	AbstractFactory defers creation of product objects to its ConcreteFactory subclass.

## Builder ##
+	The client creates the Director object and configures it with the desired Builder object.
+	Director notifies the builder whenever a part of the product should be built.
+	Builder handles requests from the director and adds parts to the product.
+	The client retrieves the product from the builder.

## Factory Method (Virtual Constructor) ##
+	Creator relies on its subclasses to define the factory method so that it returns an instance of the appropriate ConcreteProduct.

## Singleton ##
+	Clients access a Singleton instance solely through Singleton's Instance operation.

## Prototype ##
+	A client asks a prototype to clone itself.

## Adapter (Wrapper) ##
+	Clients call operations on an Adapter instance. In turn, the adapter calls Adaptee operations that carry out the request.

## Bridge (Handle/Body) ##
+	Abstraction forwards client requests to its Implementor object.

## Composite (Handle/Body) ##
+	Clients use the Component class interface to interact with objects in the composite structure. If the recipient is a Leaf, then the request is handled directly. If the recipient is a Composite, then it usually forwards requests to its child components, possibly performing additional operations before and/or after forwarding.

## Decorator (Wrapper) ##
+	Decorator forwards requests to its Component object. It may optionally perform additional operations before and after forwarding the request.

## Façade ##
+	Clients communicate with the subsystem by sending requests to Facade, which forwards them to the appropriate subsystem object(s). Although the subsystem objects perform the actual work, the facade may have to do work of its own to translate its interface to subsystem interfaces.
+	Clients that use the facade don't have to access its subsystem objects directly.

## Flyweight ##
+	State that a flyweight needs to function must be characterized as either intrinsic or extrinsic. Intrinsic state is stored in the ConcreteFlyweight object; extrinsic state is stored or computed by Client objects. Clients pass this state to the flyweight when they invoke its operations.
+	Clients should not instantiate ConcreteFlyweights directly. Clients must obtain ConcreteFlyweight objects exclusively from the FlyweightFactory object to ensure they are shared properly.

## Proxy (Surrogate) ##
+	Proxy forwards requests to RealSubject when appropriate, depending on the kind of proxy.

## Chain of Responsibility (Handle/Body) ##
+	When a client issues a request, the request propagates along the chain until a ConcreteHandler object takes responsibility for handling it.

## Command (Action / Transaction) ##
+	The client creates a ConcreteCommand object and specifies its receiver.
+	An Invoker object stores the ConcreteCommand object.
+	The invoker issues a request by calling Execute on the command. When commands are undoable, ConcreteCommand stores state for undoing the command prior to invoking Execute.
+	The ConcreteCommand object invokes operations on its receiver to carry out the request.

## Interpreter ##
+	The client builds (or is given) the sentence as an abstract syntax tree of NonterminalExpression and TerminalExpression instances. Then the client initializes the context and invokes the Interpret operation.
+	Each NonterminalExpression node defines Interpret in terms of Interpret on each subexpression. The Interpret operation of each TerminalExpression defines the base case in the recursion.
+	The Interpret operations at each node use the context to store and access the state of the interpreter.

## Iterator (Cursor) ##
+	A ConcreteIterator keeps track of the current object in the aggregate and can compute the succeeding object in the traversal.

## Mediator ##
+	Colleagues send and receive requests from a Mediator object. The mediator implements the cooperative behavior by routing requests between the appropriate colleague(s).

## Memento (Token) ##
+	A caretaker requests a memento from an originator, holds it for a time, and passes it back to the originator, but sometimes the caretaker won't pass the memento back to the originator, because the originator might never need to revert to an earlier state.
+	Mementos are passive. Only the originator that created a memento will assign or retrieve its state.

## Observer (Dependents, Publish-Subscribe) ##
+	ConcreteSubject notifies its observers whenever a change occurs that could make its observers' state inconsistent with its own.
+	After being informed of a change in the concrete subject, a ConcreteObserver object may query the subject for information. ConcreteObserver uses this information to reconcile its state with that of the subject.

## State ##
+	Context delegates state-specific requests to the current ConcreteState object.
+	A context may pass itself as an argument to the State object handling the request. This lets the State object access the context if necessary.
+	Context is the primary interface for clients. Clients can configure a context with State objects. Once a context is configured, its clients don't have to deal with the State objects directly.
+	Either Context or the ConcreteState subclasses can decide which state succeeds another and under what circumstances.

## Strategy (Policy) ##
+	Strategy and Context interact to implement the chosen algorithm. A context may pass all data required by the algorithm to the strategy when the algorithm is called. Alternatively, the context can pass itself as an argument to Strategy operations. That lets the strategy call back on the context as required.
+	A context forwards requests from its clients to its strategy. Clients usually create and pass a ConcreteStrategy object to the context; thereafter, clients interact with the context exclusively. There is often a family of ConcreteStrategy classes for a client to choose from.

## Template Method ##
+	ConcreteClass relies on AbstractClass to implement the invariant steps of the algorithm.

## Visitor (Agent) ##
+	A client that uses the Visitor pattern must create a ConcreteVisitor object and then traverse the object structure, visiting each element with the visitor.
+	When an element is visited, it calls the Visitor operation that corresponds to its class. The element supplies itself as an argument to this operation to let the visitor access its state, if necessary.
