#include <iostream>

using namespace std;

template <typename T>
class Vector{
    private:
        unsigned int size;
        unsigned int capacity;
        T *storage; 

        void resize(){
            unsigned int newCapacity = 1 + (capacity*1.5);
            T* newStorage = new T[newCapacity];

            for(unsigned int i=0; i < size; i++){
                newStorage[i] = storage[i];
            }

            delete[] storage;
            storage = newStorage;
            capacity = newCapacity;
        }

        void resize(unsigned int newCapacity){

            T* newStorage = new T[newCapacity];

            for(unsigned int i=0; i < size; i++){
                newStorage[i] = storage[i];
            }

            delete[] storage;
            storage = newStorage;
            capacity = newCapacity;
        }

    public:

        unsigned int getSize(){ return size; }
        unsigned int getCapacity(){ return capacity; }
        
        Vector() : size(0), capacity(1), storage(new T[capacity]) {}
        
        ~Vector(){
            delete []storage;
        }

        Vector(Vector<T>* vec){
            size = vec->getSize();
            capacity = vec->getCapacity();
            storage = new T[capacity];     
                   
            for(unsigned int i=0; i<size; i++){
                storage[i] = vec->at(i);
            }
        }

        void push_back(T elem){
            if( size == capacity){ resize(); }
            storage[size]= elem;
            size++;
        }

        void push_front(T elem){
            push_back(elem);

            for(unsigned int i=size; i>0; i--){
                storage[i] = storage[i-1];
            }

            storage[0] = elem; 
        }

        T at(unsigned int elem){
            if(elem < size){
                return storage[elem];
            }else{
                return -1;
            }
        }

        void pop_back(){
            delete storage[size-1];
            size--;
        }

        void insert(T elem, unsigned int pos){
            push_back(elem);

            for(unsigned int i=size-1; i>pos; i--){
                storage[i] = storage[i-1];
            }

            storage[pos] = elem; 
        }
        
        // [ from, to ) 
        void remove(unsigned int from, unsigned int to){
            unsigned int range = to - from;

            for(unsigned int i=from; i<size-range; i++){
                storage[i] = storage[i+range];
            }

            size = size - range; 
        }

        void Print(){
            if(size == 0){
                cout << "{ }" ;
            }
            else{
                cout << "{ ";
                for(unsigned int i=0; i < size-1; i++){
                    cout << storage[i] << ", ";
                } 
                cout << storage[size-1] << " }";
            }
        }

        void pop_front(){
            for (unsigned int i; i < size-1; i++){
                storage[i]= storage[i+1];
            }
            pop_back();
        }
        
        void remove(unsigned int target){
            for(unsigned int i =target; i<size-1;i++){
                storage[i]= storage[i+1];
            }
            pop_back();
        }

        void insert( Vector<T>* other , unsigned int pos){
            for ( unsigned int i = 0 ;  i < other->getSize(); i++){
                insert(other->at(i),pos+i);
            }
        }
};