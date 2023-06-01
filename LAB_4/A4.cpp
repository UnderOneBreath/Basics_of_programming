
// #include <iostream>
// #include <fstream>
// #include <vector>
// using namespace std;
//
// bool is_sudoku(vector<vector<int>> &a)
// {
//     // Check rows
//     for (int i = 0; i < 9; ++i)
//     {
//         vector<bool> used(10);
//         for (int j = 0; j < 9; ++j)
//         {
//             if (a[i][j] != 0 && used[a[i][j]])
//             {
//                 return false;
//             }
//             used[a[i][j]] = true;
//         }
//     }
//
//     // Check columns
//     for (int j = 0; j < 9; ++j)
//     {
//         vector<bool> used(10);
//         for (int i = 0; i < 9; ++i)
//         {
//             if (a[i][j] != 0 && used[a[i][j]])
//             {
//                 return false;
//             }
//             used[a[i][j]] = true;
//         }
//     }
//
//     // Check squares
//     for (int si = 0; si < 3; ++si)
//     {
//         for (int sj = 0; sj < 3; ++sj)
//         {
//             vector<bool> used(10);
//             for (int i = si * 3; i < si * 3 + 3; ++i)
//             {
//                 for (int j = sj * 3; j < sj * 3 + 3; ++j)
//                 {
//                     if (a[i][j] != 0 && used[a[i][j]])
//                     {
//                         return false;
//                     }
//                     used[a[i][j]] = true;
//                 }
//             }
//         }
//     }
//
//     return true;
// }
//
// int main()
// {
        for(int i=1;i<5;++i){
            string name="sudoku"+to_string(i)+".txt";
            ifstream fin(name);
            vector<vector<int>> a(9, vector<int>(9));
            bool valid;
            for (int i = 0; i < 9; ++i){
              for (int j = 0; j < 9; ++j)
        {fin >> a[i][j];}
    }
    valid = is_sudoku(a);
    cout << "Sudoku"<<i<<" is ";
    if (valid)
    {cout << "valid"<<endl;}
    else
    {cout << "invalid"<<endl;}
}
}