#include <iostream>
#include <vector>

using namespace std;

long long num;

int arr1[500005];
int arr2[500005];

void mergesort(int *arr, int length, int oSet)
{
    if (length > 1)
    {
        int *firstHalf = arr1 + oSet;
        if (firstHalf == arr)
            firstHalf = arr2 + oSet;

        for (int i = 0; i < length; ++i)
            firstHalf[i] = arr[i];

        int len = length / 2;
        int secondHalfStart = len;
        int len2 = length - secondHalfStart;
        int *secondHalf = firstHalf + secondHalfStart;

        mergesort(firstHalf, len, oSet);
        mergesort(secondHalf, len2, oSet + secondHalfStart);

        int pos1 = 0, pos2 = 0;
        int index = 0;

        int currentCost = num;

        while (pos1 < len && pos2 < len2)
        {
            if (firstHalf[pos1] < secondHalf[pos2])
                arr[index++] = firstHalf[pos1++];
            else
            {
                arr[index++] = secondHalf[pos2++];
                num += len - pos1;
            }
        }

        for (; pos1 < len; ++pos1, ++index)
            arr[index] = firstHalf[pos1];
        for (; pos2 < len2; ++pos2, ++index)
            arr[index] = secondHalf[pos2];
    }
}

int main()
{
    int N;

    while (cin >> N, N)
    {
        for (int i = 0; i < N; ++i)
            cin >> arr1[i];

        mergesort(arr1, N, 0);

        cout << (num % 2 ? "Marcelo\n" : "Carlos\n");
        num = 0;
    }
}