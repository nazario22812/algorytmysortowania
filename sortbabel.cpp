#include <iostream>

int* sortowanie(int size, int array[]){
    int b = size;
    while(b>1){
        int i = 0;
        while(i<b-1){
            if(array[i] > array[i+1]){
                int pomoc = array[i];
                array[i] = array[i+1];
                array[i+1] = pomoc;
            }
            i++;
        }
        b--;
    }
    return array;
}   


int main(){
    int n;
    
    std::cout << "podaj ilosc liczb: ";
    std::cin >> n;

    int array[n];

    std::cout << "wpisz liczby do tablicy" << std::endl;
    
    for(int i = 0; i<n;i++){
        std::cin >> array[i];    
    }

    std::cout << "\n";

    int* ptr;
    ptr = sortowanie(n, array);

    for (int i = 0; i<n;i++){
        std::cout << ptr[i] << std::endl; 
    }




    return 0;
}