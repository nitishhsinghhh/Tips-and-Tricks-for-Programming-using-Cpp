# What Is a Class Diagram?
A class diagram is a type of UML (Unified Modeling Language) diagram that shows the static structure of a system. It includes:

Classes
- Attributes and methods
- Relationships (inheritance, association, dependency, etc.)
- It helps developers visualize how different parts of a system interact and how responsibilities are distributed.

## How to Design a Class Diagram (Step-by-Step)
### Step 1: Identify the Classes
Start by listing all the classes involved in your system. For [our example](https://blog.devgenius.io/factory-method-in-c-design-patterns-85214330cc25):

- StringConversion (abstract base class)
- UpperCaseConversion, LowerCaseConversion, CapitalizeConversion (concrete classes)
- StringConversionFactory (factory class)
- Client (user class)
- ConversionType (enum)


### Step 2: Define Attributes and Methods
For each class, list its attributes (variables) and methods (functions).

Example:
```Class: StringConversion
-----------------------
+ convertString(input: string): string
```

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

## Breakdown of our Diagram

https://gist.github.com/nitishhsinghhh/ada68f8aec93fa93b44ac99580ef6070

- ConversionType (Enum)
  - Used to select the conversion type.
  - Not a class, but shown for completeness.

- StringConversion (Abstract Class)
  - Defines the interface: convertString()
  - Parent of all conversion classes

- Concrete Classes
  - UpperCaseConversion, LowerCaseConversion, CapitalizeConversion
  - Inherit from StringConversion
  - Implement convertString() differently
- StringConversionFactory
  - Static method: createStringConversion(type)
  - Returns an object of a subclass based on ConversionType

- Client
  - Uses the factory to get a conversion object
  - Calls convertString() on the object
