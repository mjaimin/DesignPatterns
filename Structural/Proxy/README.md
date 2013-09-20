The Proxy pattern is used when you need to represent an object that is complex or time consuming to create, by a simpler one. If creating an object is expensive in time or computer resources, Proxy allows you to postpone this creation until you need the actual object. A Proxy usually has the same methods as the object it represents, and once the object is loaded, it passes on the method calls from the Proxy to the actual object.

There are several cases where a Proxy can be useful.
+	An object, such as a large image, takes a long time to load.
+	The results of a computation take a long time to complete, and you need to display intermediate results while the computation continues.
+	The object is on a remote machine, and loading it over the network may be slow, especially during peak network load periods.
+	The object has limited access rights, and the proxy can validate the access permissions for that user.

