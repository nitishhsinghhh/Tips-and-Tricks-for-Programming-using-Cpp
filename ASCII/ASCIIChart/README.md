# ASCII Chart

The following chart contains all 128 ASCII decimal (dec), octal (oct), hexadecimal (hex) and character (ch) codes.

![image](https://github.com/nitishhsinghhh/Tips-and-Tricks-for-Programming-using-Cpp/assets/93253740/f257abee-7cc9-4038-b2ab-61c59c202745)

```CPP
#include <iostream>
// GCC 13.1: C++ 23
int main() {
	std::cout << "Printable ASCII [32..126]:\n";
	for (char c{ ' ' }; c <= '~'; ++c)
		std::cout << c << ((c + 1) % 32 ? ' ' : '\n');
	std::cout << '\n';
}
```
```
Output: 
Printable ASCII [32..126]:
  ! " # $ % & ' ( ) * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ?
@ A B C D E F G H I J K L M N O P Q R S T U V W X Y Z [ \ ] ^ _
` a b c d e f g h i j k l m n o p q r s t u v w x y z { | } ~
```

## Table of Contents:
1. [C++ program that prints the printable ASCII characters in the range of 32 to 126](https://github.com/nitishhsinghhh/Tips-and-Tricks-for-Programming-using-Cpp/blob/main/ASCII/ASCIIChart/code.cpp)
