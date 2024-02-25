#include <iostream>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Wybieramy ostatni element jako pivot
    int i = (low - 1);     // Indeks elementu mniejszego od pivota

    for (int j = low; j <= high - 1; ++j) {
        // Jeśli bieżący element jest mniejszy lub równy pivotowi
        if (arr[j] <= pivot) {
            ++i; // Inkrementujemy indeks mniejszych elementów
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);  // Sortowanie elementów przed pivotem
        quickSort(arr, pi + 1, high); // Sortowanie elementów po pivotem
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Tablica przed sortowaniem:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    quickSort(arr, 0, n - 1);

    std::cout << "Tablica po sortowaniu:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
