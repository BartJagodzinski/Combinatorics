#include <iostream>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <map> 
#include <array>

template<typename T1, size_t SIZE1, typename T2, size_t SIZE2>
std::multimap<T1, T2> combine(std::array<T1, SIZE1> const &collection1, std::array<T2, SIZE2> const &collection2) {

	std::multimap<T1, T2> combined;	

	for (size_t i = 0; i < collection1.size(); i++) {
		for (size_t j = 0; j < collection1.size(); j++) { combined.insert(std::pair<T1, T1>(collection1[i], collection1[j])); }
	}

	for (T1 el1 : collection1) {
		for (T2 el2 : collection2) {
			combined.insert(std::pair<T1, T2>(el1, el2));
			combined.insert(std::pair<T2, T1>(el2, el1));
		}
	}

	for (size_t i = 0; i < collection2.size(); i++) {
		for (size_t j = 0; j < collection2.size(); j++) { combined.insert(std::pair<T2, T2>(collection2[i], collection2[j])); }
	}

	return combined;
}

int main() {
	std::array<int, 3> col1 = {1,2,3};
	std::array<int, 3> col2 = {4,5,6};

	std::multimap<int, int> combination = combine(col1, col2);

	int i = 1;
	for (auto elem : combination) { std::cout << i <<" "<< elem.first << " " << elem.second << "\n"; i++; }

	return EXIT_SUCCESS;
}
