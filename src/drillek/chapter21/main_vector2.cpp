#include <iostream>
#include <numeric>
#include <fstream>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vd) {
    for (const auto& e : vd) {
        os << e << ' ';
    }
    return os;
}

int main() {
    std::ifstream dataIfs("/Users/klevcsoo/GitHub/deik-prog1/src/drillek/chapter21/data2.txt");
    if (!dataIfs) std::invalid_argument("Invalid data file path");

    std::vector<double> vd;
    for (double d; dataIfs >> d;) vd.push_back(d);
    std::cout << "\"vd\" vector:" << std::endl << vd << std::endl;

    std::vector<int> vi(vd.size());
    std::copy(vd.begin(), vd.end(), vi.begin());

    std::cout << std::endl << "(vd[i], vi[i]):" << std::endl;
    for (int i = 0; i < vd.size(); i++) {
        std::cout << '(' << vd[i] << ',' << vi[i] << ')' << std::endl;
    }
    std::cout << std::endl;

    double sumVd = std::accumulate(vd.begin(), vd.end(), 0.0);
    // Érthetetlen számomra, miért kerekíti a double-t
    // mikor ki akarom írni a terminálba a következő sorban
    std::cout << "Sum of \"vd\" vector: " << (double)sumVd << std::endl;
    int sumVi = std::accumulate(vi.begin(), vi.end(), 0);
    // Értelemszerűen ott a tizedespont utáni adat a "sumVd"-ben,
    // mert amikor a különbséget kiírom, akkor már double formában
    // jelenik meg, és a "sumVd" és a "sumVi" közül csak a "sumVd"
    // tartalmazhat ilyen adatot, mert ha meg már a kerekített összeg
    // lenne tárolva a "sumVd"-ben akkor az azt jelentené, hogy két
    // egész szám különbsége egy tört. Ami hát.. nem.
    std::cout << "Difference between the sum of \"vd\" and the sum of \"vi\": " <<
        abs(sumVd - (double)sumVi) << std::endl
    ;

    std::reverse(vd.begin(), vd.end());
    std::cout << std::endl << "Reversed \"vd\":" << std::endl << vd << std::endl;

    double meanVd = sumVd / vd.size();
    std::cout << std::endl << "Mean of \"vd\": " << meanVd << std::endl;

    std::vector<double> vd2;
    for (const auto& e : vd) if (e < meanVd) vd2.push_back(e);

    std::sort(vd.begin(), vd.end());
    std::cout << std::endl << "Sorted \"vd\": " << std::endl << vd << std::endl;

    return 0;
}
