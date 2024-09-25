#include <iostream>
#include "C:\Users\jhon.angarita\Desktop\repaso\List.hh"

using namespace std; 

template <typename T>

class Queue{
    private:
        unsigned int size;
        List<T> Storage;
    public:
        Queue(): Storage(), size(0) {}

        void push(T elem){
            Storage.pushBack(elem);
            size++;
        }

        void pop(){
            Storage.pop_back();
            size--;
        }

        T top(){
            return Storage.at(size);
        }

        unsigned int getSize(){
            return size;
        }

        unsigned int getSizeStora(){
            return Storage.getSize();
        }


        void print(){
            Storage.Print();
        }

};