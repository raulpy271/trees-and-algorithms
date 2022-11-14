
#include "freq.h"

template <typename T> Freq<T>::Freq() {
    this->value = '\0';
    this->freq = 0;
}

template <typename T> Freq<T>::Freq(T value) {
    this->value = value;
    this->freq = 1;
}

template <typename T> Freq<T>::Freq(T value, int freq) {
    this->value = value;
    this->freq = freq;
}

template <typename T> void Freq<T>::inc() {
    this->freq += 1;
}

template class Freq<char>;