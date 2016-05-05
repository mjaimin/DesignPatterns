#Law Of Demeter#
A method of an object should invoke only the methods of the following kinds of objects:

1.	itself	
2.	its parameters	
3.	any objects it creates/instantiates
4.	its direct component objects 

Avoid global variables
Avoid objects returned from messages sent to others

##In other words:##

1.	Object can play with yourself. -> this.method()
2.	You can play with toys that were given to you. -> arg.method()
3.	And you can play with toys you have made yourself. -> A a = new A(); a.method()
4.	Object can play with it's own toys (but you can't take them apart). -> field.method(), field.getX()


