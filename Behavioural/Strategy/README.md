#Purpose
	Defines a set of encapsulated algorithms that can be swapped to carry out a specific behavior.
#Intent
	Define a family of algorithms, encapsulate each one, and make them interchangeable. Lets the algorithm vary independently from clients that use it.
	Also
	The Strategy pattern encapsulates a set of algorithms uniformly (sibling subclasses that inherit a common interface) to achieve interchangeability among them.
	
	
	

• Save ﬁles in different formats
• Compress ﬁles using different algorithms
• Capture video data using different compression schemes
• Use different line-breaking strategies to display text data
• Plot the same data in different formats: line graph, bar chart, or pie chart	
• related classes differ only in their behavior.
• There are different algorithms for a given purpose, and the selection criteria can be codified.
• The algorithm uses data to which the client should not have access.
	
	
	
#Participant	
Context
A class that maintains contextual information for an IStrategy object’s algorithm to work on
IStrategy
Defines an interface common to all the strategies
StrategyA, StrategyB
Classes that include algorithms that implement the IStrategy interface
	
	
	
#Context - The Context class is the trafﬁc cop that decides which strategy is to be called.
	
	
	
#The Strategy pattern involves removing an algorithm from its host class and putting it in a separate class.
	
#The pattern’s benefits are as follows:
•Algorithms can be used among varying systems
• Algorithms can be more easily maintained
• Algorithms can be interchanged both during development and at runtime
And it has these drawbacks:
• Clients must be aware of the strategies.
• Strategies are more objects to manage.

#Key Features
• Define and encapsulate a family of algorithms.
• Make encapsulated algorithms interchangeable.
• Allow algorithms to change independently from the clients that use it.
