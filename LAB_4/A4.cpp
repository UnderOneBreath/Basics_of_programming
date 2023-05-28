
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
//     ifstream fin1("sudoku1.txt");
//     ifstream fin2("sudoku2.txt");
//     ifstream fin3("sudoku3.txt");
//     ifstream fin4("sudoku4.txt");
//
//     vector<vector<int>> a(9, vector<int>(9));
//     bool valid;
//
//     // Check first sudoku
//     for (int i = 0; i < 9; ++i)
//     {
//         for (int j = 0; j < 9; ++j)
//         {
//             fin1 >> a[i][j];
//         }
//     }
//     valid = is_sudoku(a);
//     cout << "Sudoku1 is ";
//     if (valid)
//     {
//         cout << "valid\n";
//     }
//     else
//     {
//         cout << "invalid\n";
//     }
//
//     // Check second sudoku
//     for (int i = 0; i < 9; ++i)
//     {
//         for (int j = 0; j < 9; ++j)
//         {
//             fin2 >> a[i][j];
//         }
//     }
//     valid = is_sudoku(a);
//     cout << "Sudoku2 is ";
//     if (valid)
//     {
//         cout << "valid\n";
//     }
//     else
//     {
//         cout << "invalid\n";
//     }
//
//     // Check third sudoku
//     for (int i = 0; i < 9; ++i)
//     {
//         for (int j = 0; j < 9; ++j)
//         {
//             fin3 >> a[i][j];
//         }
//     }
//     valid = is_sudoku(a);
//     cout << "Sudoku3 is ";
//     if (valid)
//     {
//         cout << "valid\n";
//     }
//     else
//     {
//         cout << "invalid\n";
//     }
//
//     // Check fourth sudoku
//     for (int i = 0; i < 9; ++i)
//     {
//         for (int j = 0; j < 9; ++j)
//         {
//             fin4 >> a[i][j];
//         }
//     }
//     valid = is_sudoku(a);
//     cout << "Sudoku4 is ";
//     if (valid)
//     {
//         cout << "valid\n";
//     }
//     else
//     {
//         cout << "invalid\n";
//     }
//
//     return 0;
// }