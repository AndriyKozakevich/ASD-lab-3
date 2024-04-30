#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}


int arithmeticProgressionSum(int a1, int d, int n) {
    return (n * (2 * a1 + (n - 1) * d)) / 2;
}


void abstractMerge(vector<int>& arr, int l, int m, int r) {
    vector<int> L(arr.begin() + l, arr.begin() + m + 1);
    vector<int> R(arr.begin() + m + 1, arr.begin() + r + 1);

    int i = 0, j = 0, k = l;
    while (i < L.size() && j < R.size()) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    while (i < L.size()) {
        arr[k++] = L[i++];
    }

    while (j < R.size()) {
        arr[k++] = R[j++];
    }
}


void abstractMergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    abstractMergeSort(arr, l, m);
    abstractMergeSort(arr, m + 1, r);
    abstractMerge(arr, l, m, r);
}


void twoWayMerge(vector<int>& arr, int l, int m, int r) {
    vector<int> L(arr.begin() + l, arr.begin() + m + 1);
    vector<int> R(arr.begin() + m + 1, arr.begin() + r + 1);

    int i = 0, j = 0, k = l;
    while (i < L.size() && j < R.size()) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    while (i < L.size()) {
        arr[k++] = L[i++];
    }

    while (j < R.size()) {
        arr[k++] = R[j++];
    }
}


void twoWayMergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    twoWayMergeSort(arr, l, m);
    twoWayMergeSort(arr, m + 1, r);
    twoWayMerge(arr, l, m, r);
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    int N, firstTerm, difference;
    cout << "Введіть розмір масиву (100 < N < 1000): ";
    cin >> N;
    cout << "Введіть перший член прогресії: ";
    cin >> firstTerm;
    cout << "Введіть різницю прогресії: ";
    cin >> difference;

    vector<int> progression(N);

    
    for (int i = 0; i < N; ++i) {
        progression[i] = firstTerm + i * difference;
    }

    cout << "Масив до сортування:" << endl;
    printArray(progression);

    
    abstractMergeSort(progression, 0, N - 1);
    cout << "Масив після сортування абстрактним злиттям:" << endl;
    printArray(progression);

    
    twoWayMergeSort(progression, 0, N - 1);
    cout << "Масив після сортування двошляховим злиттям:" << endl;
    printArray(progression);

    
    int sum = arithmeticProgressionSum(firstTerm, difference, N);
    cout << "Сума прогресії: " << sum << endl;

    return 0;
}
