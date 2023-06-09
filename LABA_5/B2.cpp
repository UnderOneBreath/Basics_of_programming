#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
using namespace std;

class SortingChampion
{
public:
    static void Selection_Sort(vector<int> &a)
    {
        int n = a.size();
        for (int i = 0; i < n - 1; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < n; j++)
                if (a[j] < a[minIndex])
                    minIndex = j;
            swap(a[i], a[minIndex]);
        }
    }

    static void Bubble_Sort(vector<int> &a)
    {
        int n = a.size();
        for (int i = 0; i < n - 1; i++)
        {
            bool is_sorted = true;
            for (int j = 0; j < n - i - 1; j++)
                if (a[j] > a[j + 1])
                {
                    swap(a[j], a[j + 1]);
                    is_sorted = false;
                }
            if (is_sorted)
                break;
        }
    }

    static void Insertion_Sort(vector<int> &a)
    {
        int n = a.size();
        for (int i = 1; i < n; i++)
        {
            int nxt = a[i];
            int j = i - 1;
            while (j >= 0 && a[j] > nxt)
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = nxt;
        }
    }

    static void merge(vector<int> &a, vector<int> &a1, vector<int> &a2)
    {
        int n1 = a1.size(), n2 = a2.size();
        int i1 = 0, i2 = 0;
        while (i1 < n1 && i2 < n2)
        {
            if (a1[i1] <= a2[i2])
                a.push_back(a1[i1++]);
            else
                a.push_back(a2[i2++]);
        }
        while (i1 < n1)
            a.push_back(a1[i1++]);
        while (i2 < n2)
            a.push_back(a2[i2++]);
    }

    static void Merge_Sort(vector<int> &a)
    {
        int n = a.size();
        if (n <= 1)
            return;
        vector<int> a1(a.begin(), a.begin() + n / 2);
        vector<int> a2(a.begin() + n / 2, a.end());
        Merge_Sort(a1);
        Merge_Sort(a2);
        a.clear();
        merge(a, a1, a2);
    }

    static void Quick_Sort(vector<int> &a, int l, int r)
    {
        if (r <= l)
            return;
        int i = l, j = r;
        int x = a[(l + r) / 2];
        while (i <= j)
        {
            while (a[i] < x)
                i++;
            while (a[j] > x)
                j--;
            if (i <= j)
            {
                swap(a[i], a[j]);
                i++;
                j--;
            }
        }
        Quick_Sort(a, l, j);
        Quick_Sort(a, i, r);
    }
};
int main()
{
    ifstream file("RandomNumbers[10000].txt");

    vector<int> a;
    int nums;

    while (file >> nums)
        a.push_back(nums);

    file.close();
    cout << a.size() << endl;

    vector<int> temp = a;
    auto start = chrono::high_resolution_clock::now();
    SortingChampion::Selection_Sort(temp);
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Selection Sort: " << elapsed.count() << " microsec" << endl;

    start = chrono::high_resolution_clock::now();
    SortingChampion::Bubble_Sort(temp);
    end = chrono::high_resolution_clock::now();
    elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Bubble Sort: " << elapsed.count() << " microsec" << endl;

    start = chrono::high_resolution_clock::now();
    SortingChampion::Insertion_Sort(temp);
    end = chrono::high_resolution_clock::now();
    elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Insertion Sort: " << elapsed.count() << " microsec" << endl;

    start = chrono::high_resolution_clock::now();
    SortingChampion::Merge_Sort(temp);
    end = chrono::high_resolution_clock::now();
    elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Merge Sort: " << elapsed.count() << " microsec" << endl;

    start = chrono::high_resolution_clock::now();
    SortingChampion::Quick_Sort(temp, 0, temp.size() - 1);
    end = chrono::high_resolution_clock::now();
    elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Quick Sort: " << elapsed.count() << " microsec" << endl;
}