#pragma once
#include <string.h>
template <size_t LEN>
struct count_sort {
    void operator()(int array[LEN]) {
        int max_v = array[0];
        int min_v = array[0];
        for (int i = 1;i < LEN;i++) {
            if (array[i] > max_v) {
                max_v = array[i];
            }
            else if (array[i] < min_v) {
                min_v = array[i];
            }
        }
        if (max_v == min_v) {
            return;
        }
        int len = max_v - min_v + 1;
        int *count = new int[len];
        if (!count) {
            return;
        }
        memset(count, 0, sizeof(int) * len);
        for (int i = 0;i < len;i++) {
            ++count[array[i] - min_v];
        }
        for (int i = 1;i < len;i++) {
            count[i] += count[i - 1];
        }
        int *psort = new int[LEN];
        if (!psort) {
            delete []count;
            return;
        }
        int index = 0;
        for (int i = LEN - 1;i >= 0;i--) {
            index = array[i] - min_v;
            --count[index];
            psort[count[index]] = array[i];
        }
        for (int i = 0;i < LEN;i++) {
            array[i] = psort[i];
        }
        delete []count;
        delete []psort;
    }
};