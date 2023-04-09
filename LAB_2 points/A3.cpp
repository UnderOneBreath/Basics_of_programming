#define NDEBUG
#include <cassert>
#include <iostream>
using namespace std;

#define maxd 100

int fun(int *a, int n, int m)
{
   int sum = 0;
   for (int i = 0; i < n; i++)
   {
      sum = 0;
      for (int j = 0; j < m; j++)
      {
         sum += a[i * m + j];
      }
      if (sum % 2 == 0)
      {
         return i;
      }
   }

   return -1;
}

int main()
{
   const int n = 3;
   const int m = 3;
   int a[n][m];
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         cin >> a[i][j];
      }
   }
   cout << fun(*a, n, m);
}