
#ifndef FREQ_H_
#define FREQ_H_

template <typename T> class Freq {
public:
    T value;
    int freq;

    Freq();
    Freq(T value);

    void inc();
};

#endif // FREQ_H_