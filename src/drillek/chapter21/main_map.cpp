#include <iostream>
#include <map>
#include <numeric>

template<typename T, typename G>
std::ostream& operator<<(std::ostream& os, std::map<T, G>& map) {
    os << "map:" << std::endl;
    for (const auto& me : map) {
        os << me.first << ": " << me.second << std::endl;
    }
    os << std::endl;
    return os;
}

void readmap(std::istream& is, std::map<std::string, int>& outmap, int size) {
    std::string key;
    int val = 0;

    while (outmap.size() < size) {
        is >> key >> val;
        outmap.insert(std::make_pair(key, val));
    }
}

int main() {
    std::map<std::string, int> msi;
    msi["Robert"] = 4;
    msi["Margret"] = 34;
    msi["Irene"] = 6;
    msi["Gregory"] = 38;
    msi["Lyle"] = 64;
    msi["Anne"] = 62;
    msi["Barbara"] = 33;
    msi["Young"] = 24;
    msi["Turk"] = 13;
    msi["Chloe"] = 9;

    std::cout << msi;

    msi.erase(msi.begin(), msi.end());

    readmap(std::cin, msi, 10);
    std::cout << std::endl << msi;

    int mapValuesSum = std::accumulate(msi.begin(), msi.end(), 0, [](
        int sum, const std::pair<std::string, int>& pair
    ) { return sum += pair.second; });
    std::cout << "Sum of values in the \"msi\" map: " << mapValuesSum << std::endl;

    std::map<int, std::string> mis;
    for (const auto& me : msi) {
        mis.insert(std::make_pair(me.second, me.first));
    }
    std::cout << std::endl << mis;

    return 0;
}
