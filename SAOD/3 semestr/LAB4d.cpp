#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

string input("input.txt"), output("output.txt");

int countOption(int S) {
    vector<int> coins = {1, 5, 10, 50, 100, 500};
    vector<int> opt(S + 1, 0);
    opt[0] = 1;

    for (int coin : coins) 
        for (int i = coin; i <= S; i++) 
            opt[i] += opt[i - coin];

    return opt[S];
}

int main() {
    ifstream inp(input);
    ofstream out(output);

    int S, answer;
    inp >> S;

    answer = countOption(S);

    if (answer > 0)
        out << answer << endl;
    else
        out << -1 << endl;

    inp.close();
    out.close();
}
