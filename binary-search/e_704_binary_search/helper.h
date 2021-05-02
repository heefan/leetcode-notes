#include <vector>
#include <iostream> 
#include <ostream>
#include <algorithm>

using namespace std;

template<typename T>
void printVector(const T& t) {
    copy(t.cbegin(), t.cend(), ostream_iterator<typename T::value_type>(cout, ", "));
	cout << endl;
}
