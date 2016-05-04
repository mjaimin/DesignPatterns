##Encapsulation##

**Data encapsulation** is a mechanism of bundling the data and the functions in program.
When we fully encapsulate code, we actually build an impenetrable wall to protect the contained code from accidental corruption due to the silly little errors that we are all prone to make.
We also tend to isolate errors to small sections of code to make them easier to find and fix. 

**Encapsulate**
+	Hide sensitive or unnecessary info.

**Want controlled access**
+	Module has interface that everything else uses to access it.
+	In code: hide internal workings, privatize variables, getter/setter methods.
+	Example: electrical outlet. Always takes the same kind of plug, no matter what. Never see the wires or worry about polarity, etc. – the stuff in the wall is encapsulated. (The interface is the outlet.)
**Why?**
+	So no one can mess up the internal workings of your module.
+	In “modular computer” example, imagine if the power supply’s output voltage wasn’t encapsulated. A new fan module could decide to change the voltage from 5 volts to 12 volts. But poof! Now your processor blows up.