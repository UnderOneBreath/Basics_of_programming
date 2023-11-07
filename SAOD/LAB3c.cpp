#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int N, M, t;
    input >> N >> M;
    // vector<int> thirst(N);
    multiset<int> ms;

    // int total_thirst = 0;
    
    // while (M > 0 && !ms.empty()) {

	for (int i = 0; i < N; i++) {
		input >> t;
		ms.insert(t);
	}

	while (M != 0) {
		multiset <int> :: reverse_iterator rit = ms.rbegin();
		ms.insert((*rit) / 10);
		ms.erase(--ms.end());
		M--;
	}

	int p = 0;
	multiset <int> :: iterator it = ms.begin();
	for (int i = 1; it != ms.end(); i++, it++)
		p = p + (*(it));

	output << p;

	input.close();
	output.close();

}
