#include <iostream>
#include <cstring>
#include <algorithm>

class StringBuffer {
private:
    char* data; // Raw pointer to heap memory
    size_t size;

public:
    // --- 1. CONSTRUCTOR ---
    StringBuffer(const char* str = "") {
        size = std::strlen(str);
        data = new char[size + 1];
        std::strcpy(data, str);
        std::cout << "[CONSTRUCTED] " << (data ? data : "null") << "\n";
    }

    // --- 2. DESTRUCTOR ---
    ~StringBuffer() {
        std::cout << "[DESTRUCTED] " << (data ? data : "already null") << "\n";
        delete[] data; 
    }

    // --- 3. COPY CONSTRUCTOR ---
    StringBuffer(const StringBuffer& other) : size(other.size) {
        data = new char[size + 1];
        std::strcpy(data, other.data);
        std::cout << "[COPY CONSTRUCTED] " << data << "\n";
    }

    // --- 4. COPY ASSIGNMENT ---
    StringBuffer& operator=(const StringBuffer& other) {
        if (this != &other) {
            delete[] data; // Free old memory
            size = other.size;
            data = new char[size + 1];
            std::strcpy(data, other.data);
            std::cout << "[COPY ASSIGNED] " << data << "\n";
        }
        return *this;
    }

    // --- 5. MOVE CONSTRUCTOR ---
    StringBuffer(StringBuffer&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr; // Pointer theft: leave other empty
        other.size = 0;
        std::cout << "[MOVE CONSTRUCTED]\n";
    }

    // --- 6. MOVE ASSIGNMENT ---
    StringBuffer& operator=(StringBuffer&& other) noexcept {
        if (this != &other) {
            delete[] data;      // Clean up self
            data = other.data;  // Take other's pointer
            size = other.size;
            other.data = nullptr;
            other.size = 0;
            std::cout << "[MOVE ASSIGNED]\n";
        }
        return *this;
    }

    // --- GETTERS ---
    // Returns a pointer to the string (safe as long as the object lives)
    const char* getData() const { 
        return data ? data : "null"; 
    }

    size_t getSize() const { 
        return size; 
    }
};

int main() {
    // A. Trigger CONSTRUCTOR
    // s1 owns "Hello"
    StringBuffer s1("Hello"); 

    // B. Trigger COPY CONSTRUCTOR
    // s2 makes a brand new "Hello" copy in a new memory address
    StringBuffer s2 = s1; 

    // C. Trigger COPY ASSIGNMENT
    // s3 was "World", now it deletes "World" and makes a copy of "Hello"
    StringBuffer s3("World");
    s3 = s1; 

    // D. Trigger MOVE CONSTRUCTOR
    // s4 "steals" the pointer from s1. s1 is now empty/null.
    // Extremely fast because no new memory is allocated.
    StringBuffer s4 = std::move(s1); 
   
    // To access .data and .size, they must be public in your class!
    std::cout << "s4 contents: " << s4.getData() << " (Size: " << s4.getSize() << ")\n";

    // E. Trigger MOVE ASSIGNMENT
    // s2 steals the pointer from s3. s3 becomes null.
    s2 = std::move(s3);
    
    std::cout << "s2 contents: " << s2.getData() << " (Size: " << s2.getSize() << ")\n";

    return 0; 
    // F. Trigger DESTRUCTOR (for s1, s2, s3, s4)
    // Automatically cleans up all remaining memory.
}