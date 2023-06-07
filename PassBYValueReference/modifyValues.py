class MyClass:
    def __init__(self, value):
        self.value = value

# Function to modify a variable passed by value
def modify_by_value(num):
    num = 42

# Function to modify an object passed by reference
def modify_by_reference(obj):
    obj.value = 42

number = 7

# Pass 'number' by value
modify_by_value(number)
print("Value after modify_by_value:", number)  # Output: 7

my_obj = MyClass(7)

# Pass 'my_obj' by reference
modify_by_reference(my_obj)
print("Value after modify_by_reference:", my_obj.value)  # Output: 42
