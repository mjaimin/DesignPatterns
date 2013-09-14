##Intent
Avoid coupling sender of request to its receiver by giving more than one object chance to handle request.  Chain receiving objects and pass request along until an object handles it.
##Description
+ Decouple senders and receivers by giving multiple objects (in a set order) a chance to handle a request. Request passed until an object handles it. 
+	1st object in chain receives request - either handles it or forwards to next object in chain. 
+ Object that makes request has no explicit knowledge of who will handle it - request has an implicit receiver.  
##Participants


**Handler** – defines interface for handling requests. Can also implement successor link

**ConcreteHandler** – handles requests it is responsible for; otherwise forwards requests to successor.

**Client** – initiates request to a ConcreteHandler in the chain.

##Use Chain of Responsibility when
+ More than 1 object may handle a request, and handle isn’t known beforehand.
+ Want to issue request to one of several objects without specifying receiver explicitly.
+ Set of objects that can handle a request should be specified dynamically

##CONSEQUENCES

**Benefits**

+ Decoupling of senders and receivers
+ Added flexibility
+ Sender doesn’t need to know specifically who the handlers are

**Potential Drawbacks**

+ Client can’t explicity specify who handles a request
+ No guarantee of request being handled (request falls off end of chain)
