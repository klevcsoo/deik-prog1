#include <iostream>
#include <vector>
#include <fstream>
#include <list>

struct Item {
    std::string name;
    int iid;
    double value;
};

std::ostream& operator<<(std::ostream& os, const Item& item) {
    return os << item.name << '\t' << item.iid << '\t' << item.value;
}

std::istream& operator>>(std::istream& is, Item& item) {
    std::string n; int id; double val;
    is >> n >> id >> val;
    item = Item {n, id, val};
    return is;
}

int main() {
    std::ifstream dataIn("/Users/klevcsoo/GitHub/deik-prog1/src/drillek/chapter21/data.txt");
    if (!dataIn) throw std::invalid_argument("Invalid data file path");

    std::vector<Item> originalVi;
    for (Item item; dataIn >> item;) {
        originalVi.push_back(item);
    }

    std::cout << "original: " << originalVi.size() << std::endl;
    for (const auto& item : originalVi) std::cout << item << std::endl;
    std::cout << std::endl;

    std::vector<Item> vi(originalVi);

    std::sort(vi.begin(), vi.end(), [](const Item&a, const Item&b) {
        return a.name < b.name;
    });

    std::sort(vi.begin(), vi.end(), [](const Item& a, const Item& b) {
        return a.iid < b.iid;
    });

    std::sort(vi.begin(), vi.end(), [](const Item& a, const Item& b) {
        return a.value > b.value;
    });

    vi.push_back(Item{"horse shoe", 99, 12.34});
    vi.push_back(Item{"Canon S400", 9988, 499.95});

    vi.erase(std::find_if(vi.begin(), vi.end(), [](const Item& x) {
        return x.name == "cup";
    }));
    vi.erase(std::find_if(vi.begin(), vi.end(), [](const Item& x) {
        return x.name == "phone";
    }));

    vi.erase(std::find_if(vi.begin(), vi.end(), [](const Item& x) {
        return x.iid == 14;
    }));
    vi.erase(std::find_if(vi.begin(), vi.end(), [](const Item& x) {
        return x.iid == 83;
    }));

    std::cout << "vector: " << vi.size() << std::endl;
    for (const auto& item : vi) std::cout << item << std::endl;
    std::cout << std::endl;

    std::list<Item> li(originalVi.size());
    std::copy(originalVi.begin(), originalVi.end(), li.begin());

    li.sort([](const Item&a, const Item&b) {
        return a.name < b.name;
    });

    li.sort([](const Item& a, const Item& b) {
        return a.iid < b.iid;
    });

    li.sort([](const Item& a, const Item& b) {
        return a.value > b.value;
    });

    li.push_back(Item{"horse shoe", 99, 12.34});
    li.push_back(Item{"Canon S400", 9988, 499.95});

    li.erase(std::find_if(li.begin(), li.end(), [](const Item& x) {
        return x.name == "cup";
    }));
    li.erase(std::find_if(li.begin(), li.end(), [](const Item& x) {
        return x.name == "phone";
    }));

    li.erase(std::find_if(li.begin(), li.end(), [](const Item& x) {
        return x.iid == 14;
    }));
    li.erase(std::find_if(li.begin(), li.end(), [](const Item& x) {
        return x.iid == 83;
    }));

    std::cout << "list: " << li.size() << std::endl;
    for (const auto& item : li) std::cout << item << std::endl;

    return 0;
}
