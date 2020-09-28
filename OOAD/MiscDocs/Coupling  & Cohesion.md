Coupling  & Cohesion

# Coupling (or dependency or connectivity)#
+	**Understanding** - The number of connections between modules.
+	**We want low coupling** - Each module is connected to very few others.
+	**Why?** 
	+	So module is easily replaced without messing up the other modules to which it is connected.
	+	So a change in one module effects few others.
	+	So a change in the code “here” has no effect in the code “over there”

**Coupling:**  A measure of how strongly one class is connected to, has knowledge of, or relies upon other classes

**Low coupling:** the class is not dependent on many other classes - good

**High Coupling:** class is dependent on many others - bad

Loose coupling is achieved by means of a design that promotes single-responsibility and separation of concerns.

## Types of Coupling, From high coupling to low coupling: ##

1. **Content coupling (high):** One module modifies or relies on the internal workings of another module
2. **Common coupling:** two modules share the same global data (e.g. a global variable). Changing the shared resource implies changing all the modules using it.
3. **External coupling:** two modules share an externally imposed data format, communication protocol, or device interface.
4. **Control coupling:** one module controlling the logic of another, by passing it information on what to do (e.g. passing a what-to-do flag).
5. **Stamp coupling (Data-structured coupling):** when modules share a composite data structure and use only a part of it, possibly a different part (e.g. passing a whole record to a function which only needs one field of it).
6. **Data coupling:** when modules share data through, for example, parameters. Each datum is an elementary piece, and these are the only data which are shared (e.g. passing an integer to a function which computes a square root).
7. **Message coupling (low):** Modules are not dependent on each other, instead they use a public interface to exchange parameter-less messages (or events, see Message passing).
8. **No coupling:** Modules do not communicate at all with one another.

Consider low coupling important when evaluating design

# Cohesion #

+	**Understanding** - How closely related are the internal workings of a module.
+	**Want high cohesion!**
	+	A “Car” module should have steering wheel routines.
	+	A “Car” module should not have routines that deal with gasoline prices.
	+	In modular computer example, power supply should have a transformer but not any RAM.
+	**Why?**
	+	If replace a module, then know what new version should contain.
	+	Imagine replacing the power supply module and discovering that you no longer had any RAM? Who would have known that your new power supply needed RAM?
	
**Cohesion**
Cohesion measures how a single module is related to a particular functionality in the system

**High Cohesion**
High cohesion is when parts of a module are grouped because they all contribute to a single well-defined task of the module

- Design is clearer and more easily understood
- Maintenance (bug fixes, enhancements, changing business rules) is easier
- High cohesion can help you attain lower coupling
 
## Types of cohesion, from worse to better, high cohesion is good ##
**Coincidental cohesion(low):** A module has coincidental cohesion if it performs multiple, unrelated actions.

**Logical cohesion:** A module has logical cohesion when it performs a series of related actions.

**Temporal cohesion:** A module has temporal cohesion when it performs a series of actions related in time.

**Procedural cohesion:** A module has procedural cohesion if it follows a series of actions related by the sequence of steps to be followed by the product.

**Communicational cohesion:** A module has communicational cohesion if it performs a series of actions related by the sequence of steps to be followed by the product and if all actions are performed on the same data.

**Sequential Cohesion:** operations on same data in significant order; output from one function is input to next (pipeline)

**Informational cohesion:** A module has informational cohesion if it performs a number of actions, each with its own entry point, with independent code for each action, all performed on the same data structure.

**Functional cohesion(high):** A module that performs exactly one action or achieves a single goal has functional cohesion. 