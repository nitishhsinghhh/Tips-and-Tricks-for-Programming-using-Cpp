# What Is a Class Diagram?
A class diagram is a type of Unified Modeling Language (UML) diagram that shows the static structure of a system. It includes:

Classes
- Attributes and methods
- Relationships (inheritance, association, dependency, etc.)
- It helps developers visualize how different parts of a system interact and how responsibilities are distributed.

## How to Design a Class Diagram (Step-by-Step)
### Step 1: Identify the Classes
Start by listing all the classes involved in your system. For [our example](https://blog.devgenius.io/factory-method-in-c-design-patterns-85214330cc25):

- StringConversion (abstract base class)
- UpperCaseConversion, LowerCaseConversion, CapitalizeConversion, SentenceCase, ToggleCase (concrete classes)
- StringConversionFactory (factory class)
- Client (user class)
- ConversionType (enum)


### Step 2: Define Attributes and Methods
For each class, list its attributes (variables) and methods (functions).

Example:

Class: StringConversion
-----------------------
+ convertString(input: string): string


### Step 3: Determine Relationships
Use arrows to show how classes relate:

- Inheritance: Solid line with a hollow triangle
- Association/Usage: Dashed line with open arrowhead
- Composition/Aggregation: Solid line with diamond

### Step 4: Layout the Diagram
Arrange classes logically:

- Abstract classes at the top
- Concrete classes below them
- Factory and client classes to the side

## Best Practices for Class Diagrams
- Keep it clean: Avoid clutter; only show relevant details.
- Use correct arrow types: Inheritance vs. usage.
- Group related classes: Helps readability.
- Label methods clearly: Include parameters and return types.
- Use access modifiers: + for public, - for private, # for protected.

## Breakdown of our UML Class Diagram for String Conversion Factory Pattern

This outlines the entities (classes) and their relationships, which together form a UML Class Diagram for the String Conversion Factory Pattern described in the provided article.

---

## Entities (Classes)

Here's a breakdown of the key classes involved in the design pattern:

* **StringConversion** (Abstract Base Class/Interface)
    * **Attributes:** None, as it's an interface defining behavior.
    * **Methods:**
        * convertString(): A pure virtual (abstract) method that concrete subclasses must implement.

* **UppercaseConversion** (Concrete Class)
    * **Attributes:** None.
    * **Methods:**
        * convertString(): Implements the conversion logic to make a string uppercase.

* **LowercaseConversion** (Concrete Class)
    * **Attributes:** None.
    * **Methods:**
        * convertString(): Implements the conversion logic to make a string lowercase.

* **CapitalizeConversion** (Concrete Class)
    * **Attributes:** None.
    * **Methods:**
        * convertString(): Implements the conversion logic to capitalize the first letter of each word in a string.
     
* **SentenceCase** (Concrete Class)
    * **Attributes:** None.
    * **Methods:**
        * convertString(): Implements the conversion logic to capitalize the first letter of each sentence and make the rest lowercase.

  * **ToggleCase** (Concrete Class)
    * **Attributes:** None.
    * **Methods:**
        * convertString(): Implements the conversion logic to Convert uppercase letters to lowercase and vice versa..

* **StringConversionFactory** (Factory Class)
    * **Attributes:** None.
    * **Methods:**
        * createStringConversion(ConversionType type): A static method responsible for creating and returning the appropriate StringConversion object based on the given ConversionType.

* **Client** (Client Class)
    * **Attributes:**
        * conversionType: Stores the desired ConversionType.
        * stringConversion: A pointer or smart pointer to a StringConversion object, allowing the client to interact with various conversion types through a common interface.
    * **Methods:**
        * BuildStringConversion(ConversionType type): Sets the desired conversion type and obtains the corresponding StringConversion object from the factory.
        * convertAndPrint(const std::string& text): (Implied usage) Utilizes the obtained StringConversion object to perform and print the conversion.
---

## Relationships

These relationships define how the classes interact within the pattern:

* **Inheritance/Generalization** (between StringConversion and its concrete implementations):
    * UppercaseConversion **inherits from** StringConversion.
    * LowercaseConversion **inherits from** StringConversion.
    * CapitalizeConversion **inherits from** StringConversion.
    * **UML Notation:** Represented by a solid line with a hollow triangle arrowhead pointing from the subclass (UppercaseConversion, LowercaseConversion, CapitalizeConversion) to the superclass (StringConversion).

* **Association/Dependency** (between StringConversionFactory and StringConversion, including its concrete implementations):
    * StringConversionFactory **creates** objects that conform to the StringConversion interface. This implies a dependency on StringConversion and an implicit understanding of its concrete subclasses for creation. The createStringConversion method returns a StringConversion*.
    * **UML Notation:** Often shown as a dashed arrow (dependency) from StringConversionFactory to StringConversion, indicating that the factory's operation depends on the StringConversion interface.

* **Association/Dependency** (between Client and StringConversionFactory):
    * The Client **uses** StringConversionFactory to obtain StringConversion objects, decoupling the client from the concrete creation logic.
    * **UML Notation:** Represented by a dashed arrow (dependency) pointing from Client to StringConversionFactory.

* **Association** (between Client and StringConversion):
    * The Client **has a** StringConversion object, meaning it holds a reference to an instance of the StringConversion interface to perform conversions. This is a "uses-a" relationship where the client interacts with the abstract interface.
    * **UML Notation:** Depicted as a solid line from Client to StringConversion.

---

## Enum

* **ConversionType**: This is an enumeration, not a class, used to specify the type of string conversion desired when interacting with the StringConversionFactory. It defines the discrete options (e.g., UP, DOWN, CAPITALIZE).

