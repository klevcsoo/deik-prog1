#include <iostream>
#include <vector>

// ---------- S STRUCT ----------
template<typename T>
struct S {
    S(T t): value(t) {}

    T& get();
    const T& get() const;

    S<T>& operator=(const T& newValue);

    private:
        T value;
};

template<typename T>
T& S<T>::get() {
    return value;
}

template<typename T>
const T& S<T>::get() const {
    return value;
}

template<typename T>
S<T>& S<T>::operator=(const T& newValue) {
    value = newValue;
    return *this;
}
// ---------- S STRUCT ----------

// ---------- OPERATOR OVERLOADING ----------
template<typename G>
std::ostream& operator<<(std::ostream& out, std::vector<G>& v) {
    out << "{ ";
    for (const auto& e : v) out << e << " ";
    out << "}";
    return out;
}

template<typename G>
std::istream& operator>>(std::istream& is, std::vector<G>& v) {
    char c; is >> c;
    if (c != '{') { is.unget(); return is; }

    for (G value; is >> value; ) {
        v.push_back(value);
    }

    return is;
}

template<typename T>
void readVal(T& value) {
    std::cin >> value;
}
// ---------- OPERATOR OVERLOADING ----------

int main() {
    // S<int> sInt(14);
    // S<char> sChar('f');
    // S<double> sDouble(83.5642);
    // S<std::string> sString("Hello, World!");
    // S<std::vector<int>> sVector(std::vector<int>{ 2, 4, 6, 8 });

    std::cout << "Input an integer...\t\t";
    int readInt; readVal(readInt);
    S<int> sReadInt(readInt);

    std::cout << "Input a character...\t\t";
    char readChar; readVal(readChar);
    S<char> sReadChar(readChar);

    std::cout << "Input a double...\t\t";
    double readDouble; readVal(readDouble);
    S<double> sReadDouble(readDouble);

    std::cout << "Input a string...\t\t";
    std::string readString; readVal(readString);
    S<std::string> sReadString(readString);

    std::cout << "Input a vector of ints... (format: { int int int })\t";
    std::vector<int> readVector; readVal(readVector);
    S<std::vector<int>> sReadVector(readVector);

    std::cout <<
        "int: " << sReadInt.get() << std::endl <<
        "char: " << sReadChar.get() << std::endl <<
        "double: " << sReadDouble.get() << std::endl <<
        "string: " << sReadString.get() << std::endl <<
        "vector: " << sReadVector.get() << std::endl
    ;

    return 0;
}
