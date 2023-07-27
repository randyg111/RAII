#include <iostream>
#include <cstring>
#include <algorithm>

class String {
    char* data;
    public:
        String(const char* p) {
            size_t size = std::strlen(p) + 1;
            data = new char[size];
            std::memcpy(data, p, size);
        }
        String(const String& that) {
            size_t size = std::strlen(that.data) + 1;
            data = new char[size];
            std::memcpy(data, that.data, size);
        }
        String(String&& that) {
            data = that.data;
            that.data = nullptr;
        }
        String& operator=(String that) {
            std::swap(data, that.data);
            return *this;
        }
        String& operator=(String&& that) {
            std::swap(data, that.data);
            return *this;
        }
        friend std::ostream& operator<<(std::ostream &os, const String &str) {
            return os << str.data;
        }
        ~String() {
            delete[] data;
        }
        friend String operator+(const String& a, const String& b) {
            size_t sizea = std::strlen(a.data);
            size_t sizeb = std::strlen(b.data);
            size_t size = sizea + sizeb + 1;
            char* c = new char[size];
            std::memcpy(c, a.data, sizea);
            std::memcpy(c + sizea, b.data, sizeb);
            return String(c);
        }
};



int main() {
    // Overload << operator
    const char* x = "cstring";
    std::cout << x << std::endl;

    // Constructor
    String a(x);
    std::cout << a << std::endl;

    // Copy constructor
    String b(a);
    std::cout << b << std::endl;

    // Move constructor
    String c("cstring");
    std::cout << c << std::endl;

    // Copy assignment operator
    String d = c;
    std::cout << d << std::endl;
    
    // Move assignment operator
    String e = "cstring";
    std::cout << e << std::endl;

    // Addition operator
    String f = a + b;
    std::cout << f << std::endl;

    return 0;
    
    // Destructor
}