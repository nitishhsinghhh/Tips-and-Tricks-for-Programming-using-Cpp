using System;

class Program
{
    // Function to modify a variable passed by value
    static void ModifyByValue(int num)     {
        num = 42;
    }

    // Function to modify a variable passed by reference
    static void ModifyByReference(ref int num)     {
        num = 42;
    }

    static void Main(string[] args)     {
        int number = 7;

        // Pass 'number' by value
        ModifyByValue(number);
        Console.WriteLine("Value after ModifyByValue: " + number); // Output: 7

        // Pass 'number' by reference
        ModifyByReference(ref number);
        Console.WriteLine("Value after ModifyByReference: " + number); // Output: 42

        Console.ReadLine();
    }
}
