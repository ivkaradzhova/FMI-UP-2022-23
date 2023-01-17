#include <iostream>
using namespace std;

void Merge(long long* arrStart, long long* arrDuration, long long* arrEnd, long long start, long long middle, long long end);

void MergeSort(long long* arrStart, long long* arrDuration, long long* arrEnd, long long start, long long end)
{
    if (start < end)
    {
        long long middle = (start + end) / 2;
        MergeSort(arrStart, arrDuration, arrEnd, start, middle);
        MergeSort(arrStart, arrDuration, arrEnd, middle + 1, end);
        Merge(arrStart, arrDuration, arrEnd, start, middle, end);
    }
}

void Merge(long long* arrStart, long long* arrDuration, long long* arrEnd, long long start, long long middle, long long end)
{
    long long i = start;
    long long j = middle + 1;
    long long k = 0;
    long long* tempArrStart = new long long[end - start + 1];
    long long* tempArrDuration = new long long[end - start + 1];
    long long* tempArrEnd = new long long[end - start + 1];
    while (i <= middle && j <= end)
    {
        if (arrEnd[i] <= arrEnd[j])
        {
            tempArrStart[k] = arrStart[i];
            tempArrDuration[k] = arrDuration[i];
            tempArrEnd[k] = arrEnd[i];
            i++;
        }
        else
        {
            tempArrStart[k] = arrStart[j];
            tempArrDuration[k] = arrDuration[j];
            tempArrEnd[k] = arrEnd[j];
            j++;
        }
        k++;
    }
    while (i <= middle)
    {
        tempArrStart[k] = arrStart[i];
        tempArrDuration[k] = arrDuration[i];
        tempArrEnd[k] = arrEnd[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        tempArrStart[k] = arrStart[j];
        tempArrDuration[k] = arrDuration[j];
        tempArrEnd[k] = arrEnd[j];
        j++;
        k++;
    }
    for (long long index = 0; index < k; index++)
    {
        arrStart[start + index] = tempArrStart[index];
        arrDuration[start + index] = tempArrDuration[index];
        arrEnd[start + index] = tempArrEnd[index];
    }
    delete[] tempArrStart;
    delete[] tempArrDuration;
    delete[] tempArrEnd;
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

    long long* eventsStart = new long long[number];
    long long* eventsDuration = new long long[number];
    long long* eventsEnd = new long long[number];
    for (long long i = 0; i < number; i++)
    {
        cin >> eventsStart[i];
        cin >> eventsDuration[i];
        eventsEnd[i] = eventsStart[i] + eventsDuration[i];
    }

    MergeSort(eventsStart, eventsDuration, eventsEnd, 0, number - 1);

    long long index = 0;
    for (long long i = 1; i < number; i++)
    {
        if (eventsStart[i] >= eventsEnd[index])
        {
            index = i;
            counter++;
        }
    }

    cout << counter;
    delete[] eventsStart;
    delete[] eventsDuration;
    delete[] eventsEnd;
    return 0;
}
