#include <iostream>
using namespace std;

int arr1[5111111];
int arr2[5111111];
long long num;

void merge_sort(int *arr, int length, int oSet) {
    if (length > 1) {
        int *firstHalf = arr1 + oSet;
        if (firstHalf == arr) {
            firstHalf = arr2 + oSet;
        }
        for (int i = 0; i < length; ++i) {
            firstHalf[i] = arr[i];
        }

        int len = length / 2;
        int secondHalfStart = len;
        int len2 = length - secondHalfStart;
        int *secondHalf = firstHalf + secondHalfStart;

        // Recursion
        merge_sort(firstHalf, len, oSet);

        merge_sort(secondHalf, len2, oSet + secondHalfStart);
        //***********

        int pos1 = 0;
        int pos2 = 0;
        int index = 0;

        // Begin splitting
        while (pos2 < len2 && pos1 < len) {
            if (firstHalf[pos1] < secondHalf[pos2]) {
                arr[index++] = firstHalf[pos1++];
            } else {
                arr[index++] = secondHalf[pos2++];
                num += len - pos1;
            }
        }
        for (; pos1 < len; ++pos1, ++index) {
            arr[index] = firstHalf[pos1];
        }

        for (; pos2 < len2; ++pos2, ++index) {
            arr[index] = secondHalf[pos2];
        }
        
    }
}

int main() {
    int numInts;
    while (cin >> numInts, numInts) {
        for (int i = 0; i < numInts; ++i) {
            cin >> arr1[i];
        }
        merge_sort(arr1, numInts, 0);
        cout << (num % 2 ? "Marcelo\n" : "Carlos\n");
        num = 0;
    }
    return 0;
}