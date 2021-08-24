//
// Created by daraw on 20/04/2020.
//

#ifndef HW2_OOP_DYNAMICARRAY_H
#define HW2_OOP_DYNAMICARRAY_H

#include <iostream>
namespace OOP_Hw2 {
    template <class T>
    class DynamicArray{
        T** Data ;// pointer for the array
        int arraySize; // the size of the array
        int nextUse; // the next place to use in the array
    public:
        DynamicArray(int arraySize=100);// constractor
        DynamicArray(const DynamicArray<T>& other);// copy constractor
        ~DynamicArray();//Destructor
        DynamicArray& operator=(const DynamicArray<T>& other);// operator= overloading
        int size()const; // return the using size of the array
        T& operator[](int index);// return the data in the place of index in the array
        const T& operator[](int index) const;// return the data in the place of index in the array
        void operator+=(const T& Item);// operator += to add item to the array
    };
    template<class T>
    OOP_Hw2::DynamicArray<T>::DynamicArray(int arraySize) {// constractor
        this->arraySize = arraySize;
        Data = new T *[arraySize];
        for (int i = 0; i < arraySize; i++) {
            Data[i] = NULL;
        }
        this->nextUse = 0;
    }
    template<class T>
    OOP_Hw2::DynamicArray<T>::DynamicArray(const DynamicArray<T> &other) {// copy constractor
        arraySize = other.arraySize;
        nextUse = other.nextUse;
        Data = new T *[other.arraySize];
        for (int i = 0; i < arraySize; i++) {
            if (i < nextUse) {
                this->Data[i] = new T(*(other->Data[i]));
            } else {
                this->Data[i] = NULL;
            }
        }
    }
    template<class T>
    OOP_Hw2::DynamicArray<T> &DynamicArray<T>::operator=(const DynamicArray<T> &other) {// operator= overloading
        if (this == &other) {// check if the two arrays are the same
            return *this;
        }
        delete[] Data;
        Data = new T *[other.arraySize];
        for (int i = 0; i < other.arraySize; i++) {// copying the array to the new one
            if (i < other.nextUse) {
                this->Data[i] = new T(*(other.Data[i]));
            } else {
                this->Data[i] = NULL;
            }
        }
        this->arraySize = other.arraySize;
        this->nextUse = other.nextUse;
        return *this;
    }
    template<class T>
    OOP_Hw2::DynamicArray<T>::~DynamicArray() {//Destructor
        for (int i = 0; i < nextUse; i++) {
            delete (this->Data[i]);
        }
        delete[] Data;
    }

    template<class T>
    int OOP_Hw2::DynamicArray<T>::size() const {// return the used size of the array
        return this->nextUse;
    }
    template<class T>
    void OOP_Hw2::DynamicArray<T>::operator+=(const T &Item) {// operator += to add item to the array
        if (nextUse == arraySize) {// check if if array is full
            T **tmp = new T *[2 * arraySize];// if the array is full make a new one with double  size and copy the old one to it, then add the new data
            for (int i = 0; i < 2 * arraySize; i++) {
                if (i < nextUse) {
                    tmp[i] = new T(*Data[i]);
                } else {
                    tmp[i] = NULL;
                }
            }
            for (int j = 0; j < nextUse; j++) {
                delete this->Data[j];
            }
            delete[]Data;
            Data = tmp;
            this->arraySize *= 2;
        }
        Data[nextUse] = new T(Item);
        nextUse++;

    }
    template<class T>
    const T &OOP_Hw2::DynamicArray<T>::operator[](int index) const {// return the data in the place of index in the array

        return (*(Data[index]));
    }
    template<class T>
    T &OOP_Hw2::DynamicArray<T>::operator[](int index) {// return the data in the place of index in the array

        return (*(this->Data[index]));
    }

}
#endif //HW2_OOP_DYNAMICARRAY_H
