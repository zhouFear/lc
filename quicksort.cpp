#include <iostream>
void quickSort(int *p, int start, int end) {
    int high = end;
    int low = start;
    int temp = p[low];
    while (high > low)
    {
        while (high > low && p[high] >= temp) high--;
        p[low] = p[high];
        while (high > low && p[low] <= temp) low++;
        p[high] = p[low];
    }
    quickSort(p, start, low);
    quickSort(p, low+1, end);
}


int main() {
    int a[20] = {2,3,1,2,3,1,5,6,7,4,2,6,90,6,7,39};
    quickSort(a, 0, 19);
    int i = 0;
    for (size_t i = 0; i < 20; i++)
    {
        std::cout << a[i] << std::endl;
    }
    
}