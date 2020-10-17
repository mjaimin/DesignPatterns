# Selecting Classes #

Draw a class diagram for a **barn** that contains some **animals** such as **chickens**, **horses**, **cows**, and **calfs**. A **farmer** milks any **cows** in the **barn**, and the **animals** eat **hay bales** that are stored in the **barn**. The **barn** is made of **wood planks**.

**Potential classes**

+ Barn, Animal, Chicken, Horse, Cow, Calf, HayBale, WoodPlanks, Farmer
  + Calf and Cow same class? Calf extends Cow (implies has additional behaviour)? Just set youth attribute in class Cow? (Depends on intent of the customer that ordered the barn yard product.)
  + Chicken, Horse, Cow extend Animal

**Potential methods**

+ milks, eats

Go through softwareengpart3.pdf page 26 to 37
