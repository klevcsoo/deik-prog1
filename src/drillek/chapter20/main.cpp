#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <algorithm>

template<typename I>
void printElements(const I& i, std::string title = "") {
    std::stringstream ss;
    ss << title << ':' << std::endl;
    for (const auto& e : i) ss << e << ' ';
    ss << std::endl;
    std::cout << ss.str();
}

template<typename Iter1, typename Iter2>
Iter2 drillCopy(Iter1 f1, Iter1 e1, Iter2 f2) {
    for (Iter1 ptr = f1; ptr != e1; ptr++) {
        *f2++ = *ptr;
    }

    return f2;
}

int main() {
    const int nArraySize = 10;

    // ---------- EREDETI ----------
    int firstArray[nArraySize] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::vector<int> firstVector(firstArray, firstArray + nArraySize);
    std::list<int> firstList(firstArray, firstArray + nArraySize);
    // ---------- EREDETI ----------

    // ---------- MÁSOLAT ----------
    int secondArray[nArraySize];
    std::copy(firstArray, firstArray + nArraySize, secondArray);
    std::vector<int> secondVector(firstVector);
    std::list<int> secondList(firstList);

    for (int i = 0; i < nArraySize; i++) secondArray[i] += 2;
    for (auto& i : secondVector) i += 3;
    for (auto& i : secondList) i += 5;
    // ---------- MÁSOLAT ----------

    // ---------- MÁSOLAT SAJÁT METÓDUSSAL ----------
    drillCopy(secondArray, secondArray + nArraySize, secondVector.begin());
    drillCopy(secondList.begin(), secondList.end(), secondArray);
    // ---------- MÁSOLAT SAJÁT METÓDUSSAL ----------

    // ---------- TARTALMAK KIÍRÁSA ----------
    printElements(firstArray, "first array");
    printElements(firstVector, "first vector");
    printElements(firstList, "first list");
    printElements(secondArray, "second array");
    printElements(secondVector, "second vector");
    printElements(secondList, "second list");
    // ---------- TARTALMAK KIÍRÁSA ----------

    // ---------- KERESÉS A VEKTORBAN ÉS A LISTÁBAN ----------
    std::cout << std::endl;

    int vectorElemToSearch = 3, listElemToSearch = 27;
    auto vectorElemI = std::find(secondVector.begin(), secondVector.end(), vectorElemToSearch);
    auto listElemI = std::find(secondList.begin(), secondList.end(), listElemToSearch);

    if (vectorElemI == secondVector.end()) {
        std::cout << "The element " << vectorElemToSearch << " was not found in the vector.";
    } else {
        auto pos = std::distance(secondVector.begin(), vectorElemI);
        std::cout << "The index of " << vectorElemToSearch << " in the vector is " << pos << '.';
    } std::cout << std::endl;

    if (listElemI == secondList.end()) {
        std::cout << "The element " << listElemToSearch << " was not found in the list.";
    } else {
        auto pos = std::distance(secondList.begin(), listElemI);
        std::cout << "The index of " << listElemToSearch << " in the list is " << pos << '.';
    } std::cout << std::endl;
    // ---------- KERESÉS A VEKTORBAN ÉS A LISTÁBAN ----------

    return 0;
}
