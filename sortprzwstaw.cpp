#include <iostream>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        /* Przesuwanie elementów większych od key o jedną pozycję do przodu */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6,54,12,57,42,12,665,2,13};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Tablica przed sortowaniem:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    insertionSort(arr, n);

    std::cout << "Tablica po sortowaniu:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
