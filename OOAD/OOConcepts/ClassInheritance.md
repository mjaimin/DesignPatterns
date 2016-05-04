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