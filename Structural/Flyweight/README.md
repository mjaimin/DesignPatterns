##Definition
	Use sharing to support large numbers of fine-grained objects efficiently. 

##Purpose
	Facilitates the reuse of many fine grained objects, making the utilization of large numbers of objects more efficient. 

##Intent
	Use sharing to support large numbers of fine-grained objects efficiently.

##
![alt text](./Images/FlyWeight.md.png "FlyWeight")
##

##Participants
+	Flyweight
		Declares an interface through which ﬂyweights can receive and act on extrinsic state
+	ConcreteFlyweight
		Implements Flyweight interface and adds storage for intrinsic state
+	UnsharedConcreteFlyweight
		Not all ﬂyweights need to be shared, unshared ﬂyweights typically have children which are ﬂyweights
+	FlyweightFactory
		Generates and manages ﬂyweight objects
+	Client
		Maintains extrinsic state and stores references to ﬂyweights

##Use Composite when
Apply flyweight when ALL of the following are true:
+	An application uses a large number of objects
+	Storage cost is high because of the quantity of objects
+	Most objects can be made extrinsic
+	Many groups of objects can be replaced by relatively few shared 
+	objects once extrinsic state is removed
+	The application does not depend on object identity

##CONSEQUENCES


**Potential Drawbacks**
+	Flyweights may introduce run-time costs associated with transferring, finding, and/or computing extrinsic state

**Benefits**
+ The increase in run-time cost are offset by storage savings which increase
	-	as more flyweights are shared
	–	as the amount of intrinsic state is considerable
	–	as the amount of extrinsic state is considerable but can be computed



##Collaborations

+	Data that a ﬂyweight needs to process must be classiﬁed as intrinsic or extrinsic
		Intrinsic is stored with ﬂyweight; Extrinsic is stored with client
+	Clients should not instantiate ConcreteFlyweights directly















Positives
	Space saving by using shared objects
	Adds functionality to the application
Negatives
	Adding processing time of computing extrinsic state
		Time can be reduced








Purpose

Use When
n	 Many like objects are used and storage cost is high.
n	 The majority of each object’s state can be made extrinsic. 
n	 A few shared objects can replace many unshared ones.
n	 The identity of each object does not matter.






It can be confusing at first to understand how the flyweight pattern works. Let’s first takea high-level look at the structure. We will then explain each individual part in more detail. **The flyweight pattern is used to reduce the number of objects you need in your application. This is accomplished by dividing an object’s internal state into two categories, intrinsic data and extrinsic data. Intrinsic data is the information that is required by the internal methods of a class; the class cannot function properly without this data. Extrinsic data is information that can be removed from a class and stored externally.** **We can take all of the objects that have the same intrinsic state and replace them with a single shared object, thus reducing the number of objects down to the number of unique intrinsic states you have.** **Instead of using a normal constructor, a factory is used to create these shared objects. That way, you can track the objects that have already been instantiated and only create a new copy if the needed intrinsic state is different from an object you already have.** **A manager object is used to store the object’s extrinsic state. When invoking any of the objects’ methods, the manager will pass in these extrinsic states as argument**


##Intrinsic and Extrinsic State
Categorizing an object’s data as intrinsic or extrinsic can be a bit arbitrary. You want to make as much of the data as possible extrinsic while still maintaining the modularity of each object. This distinction can be somewhat arbitrary. In this example, the physical car data (make, model, year) is intrinsic, and the owner data (owner name, tag number, last registration date) is extrinsic. This means that only one car object is needed for each combination of make, model, and year. This is still a lot of objects, but it is several orders of magnitude fewer than before. The single instance of each make-model-year combination will be shared among all the owners of that type of car. Here is what the new Car class looks like. We explain later in the “Extrinsic State Encapsulated in a Manager” section where the extrinsic data goes.


##Instantiation Using a Factory
The factory is fairly simple. It checks to see whether a car of this particular make-model-year combination has been created before. If so, it returns it. If not, it creates a new car and stores it for later use. This ensures that only a single copy of each unique intrinsic state is created

##Extrinsic State Encapsulated in a Manager
One more object is needed to finish this optimization. All of the data that was removed from the Car objects has to be stored somewhere; you use a singleton as a manager to encapsulate that data. Each of the old-style Car objects is now split into the extrinsic data and the reference to the shared car object that the data belongs to. The combination of a Carobject and the owner data will be referred to as a car record. The manager stores both of those pieces. It also contains the methods removed from the old Car class:

##Managing Extrinsic State
There are many different ways to manage a flyweight object’s extrinsic state. One common
way is to use a manager object, which contains a centralized database of the extrinsic states
and the flyweight object they belong to. This is the approach used in the Car example; it has
the advantage of being simple and easy to maintain. It’s also a fairly lightweight approach,
since you are only using a single array or object literal to store the extrinsic data. We use this
approach again later in the tooltip objects example.
Another way to manage extrinsic state is to use a composite. With the composite pattern,
covered in Chapter 9, you can use the hierarchy of the object itself to store information, without the need for a centralized database. The leaf nodes can all be flyweight objects, allowing
them to be shared among many locations in the composite’s hierarchy. This can be extremely
useful for large hierarchies, as the same data can be represented with far fewer unique objects.

##When Should the Flyweight Pattern Be Used?
There are a few conditions that should be met before attempting to convert your objects to
flyweights. Your page must use a large number of resource-intensive objects. This is the most
important condition; it isn’t worth performing this optimization if you only expect to use a few
copies of the object in question. How many is a “large number”? Browser memory and CPU
usage can both potentially limit the number of resources you can create. If you are instantiating enough objects to cause problems in those areas, it is certainly enough to qualify.
The next condition is that at least some of the data stored within each of these objects
must be able to be made extrinsic. This means you must be able to move some internally
stored data outside of the object and pass it into the methods as an argument. It should also
be less resource-intensive to store this data externally, or you won’t actually be improving
performance. If an object contains a lot of infrastructure code and HTML, it will probably
make a good candidate for this optimization. If it is nothing more than a container for data
and methods for accessing that data, the results won’t be quite so good.
The last condition is that once the extrinsic data is removed, you must be left with a relatively small number of unique objects. The best-case scenario is that you are left with a single
unique object, as in the calendar and tooltip examples. It isn’t always possible to reduce the
number of instances down to one, but you should try to end up with as few unique instances
of your object as possible. This is especially true if you need multiple copies of each of these
unique objects, as in the dialog box example. 

##General Steps for Implementing the Flyweight
Pattern
If all of these three conditions are met, your program is a good candidate for optimization
using the flyweight pattern. Almost all implementations of flyweight use the same general
steps:
1. Strip all extrinsic data from the target class. This is done by removing as many of the
attributes from the class as possible; these should be the attributes that change from
instance to instance. The same goes for arguments to the constructor. These arguments
should instead be added to the class’s methods. Instead of being stored within the class,
this data will be passed in by the manager. The class should still be able to perform that
same function as before. The only difference is that the data comes from a different
place.
2. Create a factory to control how the class is instantiated. This factory needs to keep
track of all the unique instances of the class that have been created. One way to do
this is to keep a reference to each object in an object literal, indexed by the unique
set of arguments used to create it. That way, when a request is made for an object,
the factory can first check the object literal to see whether this particular request
has been made before. If so, it can simply return the reference to the already existing object. If not, it will create a new instance, store a reference to it in the object
literal, and return it.
Another technique, pooling, uses an array to keep references to the instantiated objects.
This is useful if the number of available objects is what is important, not the uniquely
configured instances. Pooling can be used to keep the number of instantiated objects
down to a minimum. The factory handles all aspects of creating the objects, based on the
intrinsic data.
3. Create a manager to store the extrinsic data. The manager object controls all aspects
dealing with the extrinsic data. Before implementing the optimization, you created
new instances of the target class each time you needed it, passing in all data. Now, any
time you need an instance, you will call a method of the manager and pass all the data
to it instead. This method determines what is intrinsic data and what is extrinsic. The
intrinsic data is passed on to the factory object so that an object can be created (or reused,
if one already exists). The extrinsic data gets stored in a data structure within the manager. The manager then passes this data, as needed, to the methods of the shared objects,
thus achieving the same result as if the class had many instances.


##Benefits of the Flyweight Pattern
The flyweight pattern can reduce your page’s resource load by several orders of magnitude. In
the example on tooltips, the number of ToolTipobjects (and the HTML elements that it creates)
was cut down to a single instance. If the page uses hundreds or thousands of tooltips, which is
typical for a large desktop-style app, the potential savings is enormous. Even if you aren’t able
to reduce the number of instances down to one, it is still possible to get very significant savings
out of the flyweight pattern. It doesn’t require huge changes to your code to get these savings. Once you have created
the manager, the factory, and the flyweight, the only change you must make to your code is to
call a method of the manager object instead of instantiating the class directly. If you are creating the flyweight for other programmers to use as an API, they need only slightly alter the way
they call it to get the benefits. This is where the pattern really shines; if you make this optimization to your API once, it will be much more efficient for everyone else who uses it. When
using this optimization for a library that is used over an entire site, your users may well notice
a huge improvement in speed. 

##Drawbacks of the Flyweight Pattern
This is only an optimization pattern. It does nothing other than improve the efficiency of your
code under a strict set of conditions. It can’t, and shouldn’t, be used everywhere; it can actually
make your code less efficient if used unnecessarily. In order to optimize your code, this pattern
adds complexity, which makes it harder to debug and maintain. 
It’s harder to debug because there are now three places where an error could occur: the
manager, the factory, and the flyweight. Before, there was only a single object to worry about.
It is also very tricky to track down data problems because it isn’t always clear where a particular piece of data is coming from. If a tooltip is displaying the wrong text, is that because the
wrong text was passed in, or because it is a shared resource and it forgot to clear out the text
from its last use? These types of errors can be costly.
Maintenance can also be more difficult because of this optimization. Instead of having
a clean architecture of objects encapsulating data, you now have a fragmented mess with data
being stored in at least two places. It is important to document why a particular piece of data
is intrinsic or extrinsic, as such a distinction may be lost on those who maintain your code
after you.
These drawbacks are not deal breakers; they simply mean that this optimization should
only be done when needed. Trade-offs must always be made between run-time efficiency and
maintainability, but such trade-offs are the essence of engineering. In this case, if you are
unsure whether a flyweight is needed, it probably isn’t. The flyweight pattern is for situations
where system resources are almost entirely utilized, and where it is obvious that some sort of
optimization must be done. It is then that the benefits outweigh the costs.


##Summary
In this chapter we discussed the structure, usage, and benefits of the flyweight pattern. It is solely
an optimization pattern, used to improve performance and make your code more efficient, especially in its use of memory. It is implemented by taking an existing class and stripping it of all data
that can be stored externally. Each unique instance of this class then becomes a resource shared
among many locations. A single flyweight object takes the place of many of the original objects. 
For the flyweight object to be shared like this, several new objects must be added. A factory
object is needed to control how the class gets instantiated and to limit the number of instances
created to the absolute minimum. It should also store previously created instances, to reuse
them if a similar object is needed later. A manager object is needed to store the extrinsic data
and pass it in to the flyweight’s methods. In this manner, the original function of the class can
be preserved while greatly reducing the number of copies needed.When used properly, the flyweight pattern can improve performance and reduce needed
resources significantly. When used improperly, however, it can make your code more complicated, harder to debug, and harder to maintain, with few performance benefits to make up for
it. Before using this pattern, ensure that your program meets the required conditions and that
the performance gains will outweigh the code complexity costs. 
This pattern is especially useful to JavaScript programmers because it can be used to
reduce the number of memory-intensive DOM elements that you need to manipulate on
a page. By using it in conjunction with organizational patterns, such as composites, it is possible to create complex, full-featured web applications that still run smoothly in any modern
JavaScript environment. 

