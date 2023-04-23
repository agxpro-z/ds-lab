#pragma once

namespace custom {

template<typename T>
T max_element(T array[], int start, int end) {
    T max = array[start];
    for (int i = start; i < end; i++) {
        if (max < array[i]) {
            max = array[i];
        }
    }
    return max;
}

template<typename T>
void swap(T& a, T& b) {
    T x = a;
    a = b;
    b = x;
}

} // namespace custom
