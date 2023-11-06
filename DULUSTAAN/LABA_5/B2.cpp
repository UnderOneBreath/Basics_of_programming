#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <ctime>

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

    static void Bubble_Sort(vector<int> &a, int b)
    {
        if (b == 200)
            return;
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
        Bubble_Sort(a, b + 1);
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

    static void merge(vector<int> &a, int left, int middle, int right)
    {
        int i = left;
        int j = middle + 1;
        vector<int> temp;
        while (i <= middle && j <= right)
        {
            if (a[i] < a[j])
            {
                temp.push_back(a[i]);
                i++;
            }
            else
            {
                temp.push_back(a[j]);
                j++;
            }
        }
        while (i <= middle)
        {
            temp.push_back(a[i]);
            i++;
        }
        while (j <= right)
        {
            temp.push_back(a[j]);
            j++;
        }
        for (int i = left; i <= right; i++)
        {
            a[i] = temp[i - left];
        }
    }

    static void Merge_Sort(vector<int> &a, int left, int right)
    {
        if (left >= right)
        {
            return;
        }
        int middle = (left + right) / 2;
        merge(a, left, middle, right);
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
    }
};
int main()
{
    ifstream Ifile("RandomNumbers[10000].txt");

    vector<int> a;
    int nums;

    while (Ifile >> nums)
        a.push_back(nums);

    cout << a.size() << endl;

    vector<int> temp = a;
    auto start_selection = chrono::high_resolution_clock::now();
    SortingChampion::Selection_Sort(temp);
    auto end_selection = chrono::high_resolution_clock::now();
    auto elapsed_selection = chrono::duration_cast<chrono::microseconds>(end_selection - start_selection);
    cout << "Selection Sort: " << elapsed_selection.count() << " microseconds" << endl;

    auto start_bubble = chrono::high_resolution_clock::now();
    SortingChampion::Bubble_Sort(temp, 0);
    auto end_bubble = chrono::high_resolution_clock::now();
    auto elapsed_bubble = chrono::duration_cast<chrono::microseconds>(end_bubble - start_bubble);
    cout << "Bubble Sort: " << elapsed_bubble.count() << " microseconds" << endl;

    auto start_insertion = chrono::high_resolution_clock::now();
    SortingChampion::Insertion_Sort(temp);
    auto end_insertion = chrono::high_resolution_clock::now();
    auto elapsed_insertion = chrono::duration_cast<chrono::microseconds>(end_insertion - start_insertion);
    cout << "Insertion Sort: " << elapsed_insertion.count() << " microseconds" << endl;

    auto start_merge = chrono::high_resolution_clock::now();
    SortingChampion::Merge_Sort(temp, 0, temp.size() - 1);
    auto end_merge = chrono::high_resolution_clock::now();
    auto elapsed_merge = chrono::duration_cast<chrono::microseconds>(end_merge - start_merge);
    cout << "Merge Sort: " << elapsed_merge.count() << " microseconds" << endl;

    auto start_quick = chrono::high_resolution_clock::now();
    SortingChampion::Quick_Sort(temp, 0, temp.size() - 1);
    auto end_quick = chrono::high_resolution_clock::now();
    auto elapsed_quick = chrono::duration_cast<chrono::microseconds>(end_quick - start_quick);
    cout << "Quick Sort: " << elapsed_quick.count() << " microseconds" << endl;
}