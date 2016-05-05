# Reuse/Release Equivalency Principle #

"The granularity of reuse is the same as the granularity of release. Only components that are released through a tracking system can be effectively reused."


**Release**

+	A class generally collaborates with other classes
+	For a class to be reused, you need also the classes that this class depends on
+	All related classes must be released together

**Tracking**

+	A class being reused must not change in an uncontrolled manner
+	Code copying is a poor form of reuse

-	Only components that are released through a tracking system can be effectively reused.
-	Software must be released in small chunks -components
-	Each chunk must have a version number
-	Reusers may decide on an appropriate time to use a newer version of a component release
