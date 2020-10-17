# Reuse/Release Equivalency Principle #

"The granularity of reuse is the same as the granularity of release. Only components that are released through a tracking system can be effectively reused."

**Release**

+ A class generally collaborates with other classes
+ For a class to be reused, you need also the classes that this class depends on
+ All related classes must be released together

**Tracking**

+ A class being reused must not change in an uncontrolled manner
+ Code copying is a poor form of reuse

+ Only components that are released through a tracking system can be effectively reused.
+ Software must be released in small chunks -components
+ Each chunk must have a version number
+ Reusers may decide on an appropriate time to use a newer version of a component release

## Common Closure Principle ##

"Classes within a released component should share common closure. If one need to be changed, they all are likely to need to be changed. What affects one, affect all."

+ The classes in a package should be closed together against the same kinds of changes. A change that affects a package affects all the classes in it
+ A change must not cause modification to all released components
+ Change must affect smallest possible number of released components
+ Classes within a component must be cohesive Given a particular kind of change, either all
+ classes in a component must be modified or no class needs to be modified
+ Reduces frequency of re-release of component

## Common Reuse Principle ##

"Classes within a released component should be reused together. That is, it must be impossible to separate the component in order to reuse less than the total."

+ The classes in a package are reused together. If you reuse one of the classes in a package, you reuse them all.
+ Components must be focused
+ Component must not contain classes that an user is not likely to reuse
  + user may be forced to accept a new release due to changes to unused classes
+ Component must be narrow

## Acyclic Dependence Principle ##

"The dependency structure for released component must be a Directed Acyclic Graph. There can be no cycles"

+ There must be no cycles in the dependency structure between packages.
+ If there are cycles, it becomes hard to maintain
+ Change ripples through
+ Can’t release components in small increments

## Stable Dependency Principle ##

"Dependencies between released components must run in the direction of stability. The dependee must be more stable than the depender."

+ A package should only depend upon packages that are more stable that it is
+ A component can never be more stable than the one it depends upon.

+ Instability I = Ce / (Ca + Ce),
+ where
  + Ca - # of classes outside that depend upon this class
  + Ce - # of classes outside that this class depends upon
  + 0 <= I <= 1
  + 0 - ultimately stable; 1 - ultimately unstable

+ Components should be arranged such that components with a high I metrics should depend upon component with low I metrics

## Stable Abstraction Principle ##

"The more stable a component is, the more it must consist of abstract classes. A completely stable category should consist of nothing but abstract classes"

+ The abstraction of a package should be in proportion to its stability
+ Implementation of methods change more often than the interface
+ Interfaces have more intrinsic stability than executable code
