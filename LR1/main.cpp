#include <iostream>
#include <vector>

void firstTaskA(){
    int n = 10;
    std::vector<int> arr(n); // сам управляет памятью (нет утечки данных)
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    std::cout << "Элементы массива: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Адресс i0 элемента массива: " << &arr[0] << std::endl;

    std::cout << "Расстояние in элемента от i0: ";
    for (int i = 0; i < n; i++) {
        std::cout << &arr[i] - &arr[0] << " "; 
    }
    
    std::cout << std::endl;
    
    // Вывод - каждый элемент массива находится рядом с предыдущим 
    // аналогично можно получить доступ к элементу массива через *(arr + index)
}

int main() {
    firstTaskA();
    
    return 0;
}
