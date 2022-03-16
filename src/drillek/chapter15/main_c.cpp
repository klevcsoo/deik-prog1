// CLASS DEFINITION DRILL
#include <iostream>
#include <vector>

struct Person {
    private:
        std::string f;
        std::string l;
        int a;

    public:
        Person() {}
        Person(std::string firstName, std::string lastName, int age):
            f(firstName), l(lastName), a(age) {
            if (age < 0 || age > 150) throw("Range-en kívüli életkor (0 < életkor < 150)");

            const std::string illegal_chars = ";:\"'[]*&^%$#@!";
            for (auto& fc : firstName) {
                for (auto& ic : illegal_chars) {
                    if (fc == ic) throw("Illegális karakter a személy nevében");
                }
            }
            for (auto& lc : lastName) {
                for (auto& ic : illegal_chars) {
                    if (lc == ic) throw("Illegális karakter a személy nevében");
                }
            }
        }

        std::string firstName() const { return f; }
        std::string lastName() const { return l; }
        int age() const { return a; };
};

std::ostream& operator<<(std::ostream& out, Person& p) {
    out << p.firstName() << ' '<< p.lastName() << ' ' << p.age();
    return out;
}

std::istream& operator>>(std::istream& in, Person& p) {
    std::string f, l; int a;
    in >> f >> l >> a;
    if (!in) throw("Nincsen bemeneti stream");
    if (f == "" || &f == nullptr || l == "" || &l == nullptr || !a) throw("Hibás adatok");

    p = Person(f, l, a);
    return in;
}

int main() {
    std::cout << "Mehet!\n" << std::endl;

    std::vector<Person> people;
    Person tempP;
    while (std::cin >> tempP) {
        if (tempP.firstName() == "-") break;
        people.push_back(tempP);
    }

    for (auto& p : people) {
        std::cout << p << std::endl;
    }

    return 0;
}
