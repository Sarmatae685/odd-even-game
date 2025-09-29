#ifndef ARRAY2D_H
#define ARRAY2D_H

class Array2D {
private:
    int ** m_arr = nullptr;
    int N = 4;
    int steps = 0;

public:
    friend void printInFile(Array2D& arr);
    friend class MyGame; // needed to access private fields

    void set_N(int N);
    void allocateMemory();
    int** do_Memory(int N);
    void fillMatrix();
    void printMatrix();
    ~Array2D();
};



#endif // ARRAY2D_H
