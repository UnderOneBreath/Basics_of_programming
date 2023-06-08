#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
using namespace std;

class SortingChampion
{
public:
    static void selectionSort(vector<int> &v)
    {
        int n = v.size();
        for (int i = 0; i < n - 1; ++i)
        {
            int minIndex = i;
            for (int j = i + 1; j < n; ++j)
            {
                if (v[j] < v[minIndex])
                {
                    minIndex = j;
                }
            }
            swap(v[i], v[minIndex]);
        }
    }

    static void bubbleSort(vector<int> &v)
    {
        int n = v.size();
        for (int i = 0; i < n - 1; ++i)
        {
            bool is_sorted = true;
            for (int j = 0; j < n - i - 1; ++j)
            {
                if (v[j] > v[j + 1])
                {
                    swap(v[j], v[j + 1]);
                    is_sorted = false;
                }
            }
            if (is_sorted)
                break;
        }
    }

    static void insertionSort(vector<int> &v)
    {
        int n = v.size();
        for (int i = 1; i < n; ++i)
        {
            int nxt = v[i];
            int j = i - 1;
            while (j >= 0 && v[j] > nxt)
            {
                v[j + 1] = v[j];
                --j;
            }
            v[j + 1] = nxt;
        }
    }

    static void merge(vector<int> &v, vector<int> &v1, vector<int> &v2)
    {
        int n1 = v1.size(), n2 = v2.size();
        int i1 = 0, i2 = 0;
        while (i1 < n1 && i2 < n2)
        {
            if (v1[i1] <= v2[i2])
                v.push_back(v1[i1++]);
            else
                v.push_back(v2[i2++]);
        }
        while (i1 < n1)
            v.push_back(v1[i1++]);
        while (i2 < n2)
            v.push_back(v2[i2++]);
    }

    static void mergeSort(vector<int> &v)
    {
        int n = v.size();
        if (n <= 1)
            return;
        vector<int> v1(v.begin(), v.begin() + n / 2);
        vector<int> v2(v.begin() + n / 2, v.end());
        mergeSort(v1);
        mergeSort(v2);
        v.clear();
        merge(v, v1, v2);
    }

    static void quickSort(vector<int> &v, int l, int r)
    {
        if (r <= l)
            return;
        int i = l, j = r;
        int x = v[(l + r) / 2];
        while (i <= j)
        {
            while (v[i] < x)
                ++i;
            while (v[j] > x)
                --j;
            if (i <= j)
            {
                swap(v[i], v[j]);
                ++i;
                --j;
            }
        }
        quickSort(v, l, j);
        quickSort(v, i, r);
    }
};
int main()
{
    ifstream file("B2file.txt");
    if (!file)
    {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    vector<int> v;
    int num;
    while (file >> num)
    {
        v.push_back(num);
    }
    file.close();
    cout << v.size() << endl;

    vector<int> temp = v;
    auto start = chrono::high_resolution_clock::now();
    SortingChampion::selectionSort(temp);
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Selection Sort: " << elapsed.count() << " nanoseconds" << endl;

    temp = v;
    start = chrono::high_resolution_clock::now();
    SortingChampion::bubbleSort(temp);
    end = chrono::high_resolution_clock::now();
    elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Bubble Sort: " << elapsed.count() << " nanoseconds" << endl;

    temp = v;
    start = chrono::high_resolution_clock::now();
    SortingChampion::insertionSort(temp);
    end = chrono::high_resolution_clock::now();
    elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Insertion Sort: " << elapsed.count() << " nanoseconds" << endl;

    temp = v;
    start = chrono::high_resolution_clock::now();
    SortingChampion::mergeSort(temp);
    end = chrono::high_resolution_clock::now();
    elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Merge Sort: " << elapsed.count() << " nanoseconds" << endl;

    temp = v;
    start = chrono::high_resolution_clock::now();
    SortingChampion::quickSort(temp, 0, temp.size() - 1);
    end = chrono::high_resolution_clock::now();
    elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Quick Sort: " << elapsed.count() << " nanoseconds" << endl;
}