#include <iostream>
#include <algorithm>
#include "count_sort.hpp"
int main() {
    static const int LEN = 10;
    int loop = 10000000;
    for (int i = 0;i < loop;i++) {
        int array[LEN] = { 1, 0, 1, 2, 4, 10, 11, 13, 2, 5 };
        count_sort<LEN>cs;  
        cs(array);      // 0.047s
        //std::sort(array, array + LEN);  // 4.999s
    }

    return 0;
}