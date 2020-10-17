# BasicDesignPatternsAndSolutions #

## Inheritance ##

### Problem ###

Similar abstractions have similar members (fields and methods). Repeating these is tedious, error-prone, and a maintenance headache.

### Solution ###

Inherit default members from a superclass; select the correct implementation via run-time dispatching.

### Disadvantages ###

Code for a class is spread out, potentially reducing understandability. Run-time dispatching introduces overhead.

## Encapsulation ##

### Problem ###

Exposed fields can be directly manipulated from outside, leading to violations of the representation invariant or undesirable dependences that prevent changing the implementation.

### Solution ###

Hide some components, permitting only stylized access to the object.

### Disadvantages ###

The interface may not (efficiently) provide all desired operations. Indirection may reduce performance.

## Iteration ##

### Problem ###

Clients that wish to access all members of a collection must perform a specialized traversal for each data structure. This introduces undesirable dependences and does not extend to other collections.

### Solution ###

Implementations, which have knowledge of the representation, perform traversals and do bookkeeping. The results are communicated to clients via a standard interface.

### Disadvantages ###

Iteration order is fixed by the implementation and not under the control of the client.

## Exceptions ##

### Problem ###

Errors occurring in one part of the code should often be handled elsewhere. Code should not be cluttered with error-handling code, nor return values preempted by error codes.

### Solution ###

Introduce language structures for throwing and catching exceptions.

### Disadvantages ###

Code may still be cluttered. It can be hard to know where an exception will be handled. Programmers may be tempted to use exceptions for normal control flow, which is confusing and usually inefficient.

These particular design patterns are so important that they are built into C++.
