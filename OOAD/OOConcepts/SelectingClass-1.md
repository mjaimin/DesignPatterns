# Selecting Classes #
...play **music** for **rock bands**, **folk bands**, **school bands**, **orchestras**, etc. Each band should have some instruments such as a **bass**, **drums**, **violin**, **fiddle**, **vocals** (like **soprano**, **tenor**, etc.).

+	Pick nouns and noun phrases out of the description.
+	Ignore synonyms (like violin and fiddle… just use one or the other).
+	Look for inheritance opportunities (RockBand, FolkBand, etc. should probably inherit from Band.).

**Class**
+	Music //will play music for a given band
+	Band //abstract parent class of bands
	+	RockBand //concrete child. Will contain Instruments!
	+	Orchestra
	+	FolkBand
	+	SchoolBand
+	Instrument //abstract
	+	Bass //concrete
	+	Drums
	+	Violin
+	Vocal //abstract
	+	Soprano //concrete
	+	Tenor