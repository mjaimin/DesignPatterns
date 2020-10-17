# Law Of Demeter #

A method of an object should invoke only the methods of the following kinds of objects:

* itself
* its parameters
* any objects it creates/instantiates
* its direct component objects

Avoid global variables
Avoid objects returned from messages sent to others

## In other words ##

* Object can play with yourself. -> this.method()
* You can play with toys that were given to you. -> arg.method()
* And you can play with toys you have made yourself. -> A a = new A(); a.method()
* Object can play with it's own toys (but you can't take them apart). -> field.method(), field.getX()
