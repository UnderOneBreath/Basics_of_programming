#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int N, M;
    input >> N >> M;
    vector<int> thirst(N);
    multiset<int> ms;

    for (int i = 0; i < N; i++) {
        input >> thirst[i];
        ms.insert(thirst[i]);
    }

    int total_thirst = 0;
    
    while (M > 0 && !ms.empty()) {
        int max_thirst = *(--ms.end());

        ms.erase(--ms.end());
        int next_thirst = max_thirst / 10;
        total_thirst +=


    }

}
