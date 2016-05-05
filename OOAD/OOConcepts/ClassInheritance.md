# Class Inheritance #

+	what if a graduate student needs different course requirements than an undergraduate?
+	Can they both use the same class Student?

## Example ##
+	Student contains methods
	+	getGPA(), setGPA()
	+	getNumCreditHours(), setNumCreditHours()
+	Undergrad inherits Student
	+	all Student methods (inherits them)
	+	setClass(), getClass()
+	Grad inherits Student
	+	all Student methods (inherits them)
	+	setAdvisorName(), getAdvisorName()
	+	setThesisTopic(), getThesisTopic()

## Chains of Inheritance ##
+	Can have chains of inheritance
	+	public class Student
	+	public class Undergrad extends Student
	+	public class WorkStudy extends Undergrad
	
## Stopping Inheritance Chains ##
+	Ok, declare a class as final.
	
```C++
struct A
{
};
 
struct B final : A // struct B is final
{ 
};
 
struct C : B // Error: B is final
{
};
````

## Inheritance ##
**Problem**: Similar abstractions have similar members (fields and methods). Repeating these is tedious, error-prone, and a maintenance headache.

**Solution**: Inherit default members from a superclass; select the correct implementation via run-time dispatching.

**Disadvantages**: Code for a class is spread out, potentially reducing understandability. Run-time dispatching introduces overhead.