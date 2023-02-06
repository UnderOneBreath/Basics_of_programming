#include <vector>
#include <iostream>
using namespace std;
int grow(std::vector<int> nums)
{
    return sizeof(nums);
}
int main()
{
    cout << grow(vector<int>{1, 2, 3}) << endl;
}