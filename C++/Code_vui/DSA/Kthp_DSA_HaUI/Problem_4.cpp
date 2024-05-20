#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
using namespace std;
ll MOD = 1e9 + 7;

void bubbleSort (int x[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = n - 1; j > i;j--)
        {
            if (x[j]< x[j-1])
            {
                int temp = x[j];
                x[j] = x[j - 1];
                x[j - 1] = temp;
            }
        }
    }
}

void selectionSort (int x[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int m = i;
        for (int j = i + 1; j < n;j++)
        {
            if (x[j]<x[m])
            {
                m = j;
            }
        }
        int temp = x[m];
        x[m] = x[i];
        x[i] = temp;
    }
}

void insertionSort(int x[], int n)
{
    for (int i = 1; i < n;i++)
    {
        int temp = x[i];
        int j = i - 1;
        while (j>-1 && x[j]> temp)
        {
            x[j + 1] = x[j];
            j--;
        }
        x[j + 1] = temp;
    }
}

int main()
{
    //ios_base::sync_with_stdio(NULL);
    //cin.tie(0);
    //cout.tie(0);
    int x[] = {3, 5, 7, 2, 7, 8, 3, 1, 4};
    insertionSort(x, 9);
    for (auto i : x)
    {
        cout << i << " ";
    }
    return 0;
}