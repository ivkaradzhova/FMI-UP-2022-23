#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
public:
    long long start;
    long long duration;
    long long end;

    bool operator<= (const Node& other)
    {
        return this->end <= other.end;
    }
};

void Merge(Node* arr, long long start, long long middle, long long end);

void MergeSort(Node* arr, long long start, long long end)
{
    if (start < end)
    {
        long long middle = (start + end) / 2;
        MergeSort(arr, start, middle);
        MergeSort(arr, middle + 1, end);
        Merge(arr, start, middle, end);
    }
    return;
}

void Merge(Node* arr, long long start, long long middle, long long end)
{
    long long i = start;
    long long j = middle + 1;
    long long k = 0;
    Node* tempArr = new Node[end - start + 1];
    while (i <= middle && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            tempArr[k] = arr[i];
            i++;
        }
        else
        {
            tempArr[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= middle)
    {
        tempArr[k] = arr[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        tempArr[k] = arr[j];
        j++;
        k++;
    }
    for (long long index = 0; index < k; index++)
    {
        arr[start + index] = tempArr[index];
    }
    delete[] tempArr;
    return;
}

int main() {
    long long number = 0;
    cin >> number;

    if (number == 0)
    {
        cout << 0;
        return 0;
    }

    long long counter = 1;
    if (number == 1)
    {
        cin >> number;
        cin >> number;
        cout << counter;
        return 0;
    }

    Node* nodes = new Node[number];
    for (long long i = 0; i < number; i++)
    {
        cin >> nodes[i].start;
        cin >> nodes[i].duration;
        nodes[i].end = nodes[i].start + nodes[i].duration;
    }

    MergeSort(nodes, 0, number-1);

    long long index = 0;
    for(long long i=1; i<number; i++)
    {
        if(nodes[i].start>=nodes[index].end)
        {
            index=i;
            counter++;
        }
    }

    cout << counter;
    delete[] nodes;
    return 0;
}
