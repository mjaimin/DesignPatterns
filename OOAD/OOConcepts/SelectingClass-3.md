# Selecting Classes #

![alt text](./Images/ControllerAlarm-1.PNG "ControllerAlarm")

+ Controller needs an alarm
+ Clock has it, so why not use it?
+ Concrete Controller depends on concrete Clock
+ Changes to Clock affect Controller
+ Hard to make Controller use different alarm (fails OCP)
+ Clock has multiple responsibilities (fails SRP)

![alt text](./Images/ControllerAlarm-2.PNG "ControllerAlarm Revised")

+ Dependency has been inverted
+ Both Controller and Clock depend on
+ Abstraction (IAlarm)
+ Changes to Clock does not affect Controller
+ Better reuse results as well
