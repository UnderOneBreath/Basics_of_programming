#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));

    //RAMDOM
    srand(time(0));
    cout << "XZ chto eto: " << time(0) << endl;
    
    int min = 1, max = 100; //min and max numbers. Can say what this is range numbers

    int randomNumbers = min + (rand() % (max - min + 1));
    cout << "random range(1, 100): " << randomNumbers << endl;

    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a.size(); j++){
            randomNumbers = min + (rand() % (max - min + 1));
            a[i][j] = randomNumbers;
    }
    // for (int i = 0; i < a.size(); i++)
    //     for (int j = 0; j < a.size(); j++)        
    //         a[i][j] = j*2;

    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < a.size(); j++)        
            cout << a[i][j] << ' ';
    cout << endl;
    }

    return 0;
}