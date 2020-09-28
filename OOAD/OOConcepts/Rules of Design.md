Rules of Design

# Rules of Design #
**Make sure that the problem is well-defined**

- All design criteria, requirements, and constraints, should be enumerated before a design is started.
- This may require a “spiral model” approach.

**What comes before how**

- i.e., define the service to be performed at every level of abstraction before deciding which structures should be used to realize the services.

**Separate orthogonal concerns**

- Do not connect what is independent.
- Important at many levels and phases...

**Design external functionality before internal functionality.**

- First consider the solution as a black-box and decide how it should interact with its environment.
- Then decide how the black-box can be internally organized. Likely it consists of smaller black-boxes that can be refined in a similar fashion.

**Keep it simple**

- Fancy designs are buggier than simple ones; they are harder to implement, harder to verify, and often less efficient.
- Problems that appear complex are often just simple problems huddled together.
- Our job as designers is to identify the simpler problems, separate them, and then solve them individually.

**Work at multiple levels of abstraction**

- Good designers must be able to move between various levels of abstraction quickly and easily

**Design for extensibility**

- A good design is “open-ended,” i.e., easily extendible.
- A good design solves a class of problems rather than a single instance.
- Do not introduce what is immaterial.
- Do not restrict what is irrelevant.

**Use rapid prototyping when applicable**

- Before implementing a design, build a high-level prototype and verify that the design criteria are met.

**Details should depend upon abstractions**

- Abstractions should not depend upon details
- Principle of Dependency Inversion

**When crossing between two different paradigms, build an interface layer that separates the two**

- Don’t pollute one side with the paradigm of the other

**Software entities (classes, modules, etc) should be open for extension, but closed for modification**

- The Open/Closed principle – Bertrand Meyer

**Derived classes must usable through the base class interface without the need for the user to know the difference**

- The Liskov Substitution Principle

