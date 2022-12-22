#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
using namespace std;

//a2

// vector<int> solve(vector<int> A)
// {
//     int in1 = 0; int in2 = 0;
//     int k = 0;
//     for(int i = 0; i<A.size(); i++){
//         if(A[i]<0){
//             if(k == 0){
//                 k++;
//                 in1 = i;
//             }
//             in2 = i;
//         }
//     }
//     swap(A[in1],A[in2]);
//     return A;
// }
// TEST_CASE("Dulustan's tests"){
//     CHECK(solve({-1, 5, 0, 100}) == vector<int>({-1, 5, 0, 100}));
//     CHECK(solve({3, -1, 5, -7, 10, 36, -61, 88}) 
//     == vector<int>({3, -61, 5, -7, 10, 36, -1, 88}));
//     CHECK(solve({3, 10, 22, -10, 76, -61, -123, -5, 7}) 
//     == vector<int>({3, 10, 22, -5, 76, -61, -123, -10, 7}));
//     CHECK(solve({-2022, 1039, -3039, -2023, -2024, 777, 361}) 
//     == vector<int>({-2024, 1039, -3039, -2023, -2022, 777, 361}));
// }

// TEST_CASE("Student's tests"){
//     CHECK(solve({-5, 8, 9, -7}) == vector<int>({-7, 8, 9, -5}));
//     CHECK(solve({0, -25, 0, 100,-5, 50, -80, 36, 52}) == vector<int>({0, -80, 0, 100, -5, 50, -25, 36, 52}));
//     CHECK(solve({0,0,0,0,-1,0,0,-5}) == vector<int>({0,0,0,0,-5,0,0,-1}));
//     CHECK(solve({5,5,5,-5000,5,5,5,-1,5,48,5,6}) == vector<int>({5,5,5,-1,5,5,5,-5000,5,48,5,6}));
// }

// int main()
// {

// }

//a3

// vector<int> solve(vector<int> A)
// {
//     int min = 0; int max = 0;
//     for(int i = 0; i<A.size(); i++){
//         if(A[i]>A[max]){
//             max=i;
//         }
//         if(A[i]<A[min]){
//             min=i;
//         }
//     }
//     swap(A[min],A[max]);
//     return A;
// }

// TEST_CASE("Dulustan's tests"){
//     CHECK(solve({-1, 5, 0, 100}) == vector<int>({100, 5, 0, -1}));
//     CHECK(solve({3, -1, 5, -7, 10, 36, -61, 88}) 
//     == vector<int>({3, -1, 5, -7, 10, 36, 88, -61}));
//     CHECK(solve({3, 10, 22, -10, 76, -61, -123, -5, 7}) 
//     == vector<int>({3, 10, 22, -10, -123, -61, 76, -5, 7}));
//     CHECK(solve({-2022, 1039, -3039, -2023, -2024, 777, 361}) 
//     == vector<int>({-2022, -3039, 1039, -2023, -2024, 777, 361}));
// }

// TEST_CASE("Student's tests"){
//     CHECK(solve({0,-25,50,600}) == vector<int>({0,600,50,-25}));
//     CHECK(solve({50, 6258, 99999, 0, -87854}) == vector<int>({50, 6258, -87854, 0, 99999}));
//     CHECK(solve({0,0,0,1,0,0,2022,-5000}) == vector<int>({0,0,0,1,0,0,-5000,2022}));
//     CHECK(solve({-25,-69,-250,-999,-2021,1,-65,-78,-5001}) == vector<int>({-25,-69,-250,-999,-2021,-5001,-65,-78,1}));
// }

// int main()
// {

// }

//a4

// vector<int> solve(vector<int> A)
// {
//     int k1 = 0; int k2 = 0;
//     vector <int> b;
//     for(int i = 1; i<A.size(); i++){
//         if(A[i-1] >= 0 && A[i] >= 0 || A[i-1]<0 && A[i] < 0){
//             b.push_back(A[i-1]);
//             b.push_back(A[i]);
//             break;
//         }
//     }
//     return b;
// }

// TEST_CASE("Dulustan's tests"){
//     CHECK(solve({-1, 5, 0, 100}) == vector<int>({5, 0}));
//     CHECK(solve({3, -1, 5, -7, 10, 36, -61, 88}) == vector<int>({10, 36}));
//     CHECK(solve({3, 10, 22, -10, 76, -61, -123, -5, 7}) == vector<int>({3, 10}));
//     CHECK(solve({-2022, 1039, -3039, -2023, -2024, 777, 361}) == vector<int>({-3039, -2023}));     
// }

// //минимум 4 теста
// TEST_CASE("Student's tests"){
//     CHECK(solve({5,8,-1,5,10,-8,-9}) == vector<int>({5,8}));
//     CHECK(solve({-1, -5, 5, 100,66,82}) == vector<int>({-1,-5}));
//     CHECK(solve({-1, 5, -1, 100,-50,60,-80}) == vector<int>({}));
//     CHECK(solve({-2,-7,8,6,-8,-4,5,6}) == vector<int>({-2,-7}));
// }

// // int main()
// // {
// //     cout<<solve({-1, 5, 0, 100})<<endl;
// // }

//a5

// vector<int> solve(vector<int> A)
// {
//     for(int i = 1; i<A.size(); i+=2){
//         swap(A[i-1],A[i]);
//     }
//     return A;
// }

// TEST_CASE("Dulustan's tests"){
//     CHECK(solve({-1, 5, 0, 100}) == vector<int>({5, -1, 100, 0}));
//     CHECK(solve({3, -1, 5, -7, 10, 36, -61, 88}) 
//     == vector<int>({-1, 3, -7, 5, 36, 10, 88, -61}));
//     CHECK(solve({3, 10, 22, -10, 76, -61, -123, -5, 7}) 
//     == vector<int>({10, 3, -10, 22, -61, 76, -5, -123, 7}));
//     CHECK(solve({-2022, 1039, -3039, -2023, -2024, 777, 361}) 
//     == vector<int>({1039, -2022, -2023, -3039, 777, -2024, 361}));     
// }

// //минимум 4 теста
// TEST_CASE("Student's tests"){
//     CHECK(solve({6,5,10,20}) == vector<int>({5,6,20,10}));
//     CHECK(solve({-4,50,2022,9000}) == vector<int>({50,-4,9000,2022}));
//     CHECK(solve({5,6,2,4,8,1,3,0}) == vector<int>({6,5,4,2,1,8,0,3}));
//     CHECK(solve({-5,9,-4,9,56,23,-9,50}) == vector<int>({9,-5,9,-4,23,56,50,-9}));
// }

// // main отвечает за ввод-вывод
// // int main()
// // {

// // }