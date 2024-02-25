#include <iostream>

void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    // Kopiowanie danych do podtablic L i R
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[middle + 1 + j];

    // Scalanie tablic L i R z powrotem do arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Kopiowanie pozostałych elementów L jeśli są jakieś
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    // Kopiowanie pozostałych elementów R jeśli są jakieś
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right)
        return;
    int middle = left + (right - left) / 2;
    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);
    merge(arr, left, middle, right);
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Tablica przed sortowaniem:\n";
    for (int i = 0; i < arr_size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    mergeSort(arr, 0, arr_size - 1);

    std::cout << "Tablica po sortowaniu:\n";
    for (int i = 0; i < arr_size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
