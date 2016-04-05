#Single Responsibility Principle

A class should have only one reason to change.

In this context a responsibility is considered to be one reason to change. This principle states that if we have two reasons to change for a class, we have to split the functionality in two classes. Each class will handle only one responsibility and on future if we need to make one change we are going to make it in the class which handle it. When we need to make a change in a class having more responsibilities the change might affect the other functionality of the classes.

####Wrong interpretation of the Principle
Most developers interpret to mean that a class should perform only one task. But it's not only classes, functions you implement in code during development should also perform only one task. 