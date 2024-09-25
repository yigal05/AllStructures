#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class List{
    private:
        class Node{
            private:
                T data;
                Node* next;
            public:
                Node(T elem) : data(elem), next(nullptr) {}
                Node* getNext(){ return next;}
                void setNext(Node* newNext){ next= newNext ;}
                T getData(){ return data;}
            
        };
        
        Node *first; 
        Node *last;
        unsigned int size; 

    public:
        List() : first(nullptr), last(nullptr), size(0) {}
        
        ~List() {
            Node* n = first; 

            while(n != nullptr){
                first  = n->getNext();
                delete n;
                n = first; 
            }

            first = nullptr;
            last = nullptr; 
        }

        unsigned int getSize(){ return size; }
        
        bool empty(){ return first == nullptr; }

        void pop_front(){
            
            Node *node = first;
            Node *newNode = node -> getNext(); 
            first = newNode; 
            delete node; 
            size--;
            
        }

        void remove(unsigned int pos){

            Node* node = first;

            unsigned int i = 0; 
            while(node != nullptr && i<pos-1){
                node = node->getNext();
                i++;     
            }

            Node *newNode = node -> getNext();
            
            node -> setNext(newNode -> getNext());

            if(newNode == last){
                last = node;
            }

            delete newNode;
            size--;     
        }

        void pop_back(){ remove(size-1); }

        T at(unsigned int pos){
            assert( pos >= 0 && pos < size );

            Node *n = first; 
            unsigned int i = 0;
            while(n != nullptr && i < pos){
                n = n->getNext();
                i++;
            }

            return n->getData();
        }

        void Print(){
            if(empty()){
                cout << "{ ";
            } else {
                Node *n = first;
                cout << "{ ";
                while(n != nullptr){
                    cout << n->getData() << " " ;
                    n = n->getNext(); 
                }
            };
            cout << "}" << endl; 
        }

        void pushBack(T elem){
            Node* newNodo = new Node(elem);
            
            if (first == nullptr){
                first=newNodo;
            }else{
                last->setNext(newNodo);
            }
            
            last = newNodo;
            size++;
        }
        
        void pushFront(T elem){
            if (first == nullptr){
                pushBack(elem);
            }else{
                Node* newNodo = new Node(elem);
                newNodo->setNext(first);
                first=newNodo;
                size++;
            }
        }

        void Remove(unsigned int pos) {
            if (pos >= size) {
                return;
            }

            if (pos == 0) {  
                Node* temp = first->getNext();
                delete first;
                first = temp;
                if (first == nullptr) {
                    last = nullptr;
                }
            } else {
                Node* a = first;
                for (unsigned int i = 0; i < pos - 1; i++) {
                    a = a->getNext(); 
                }

                Node* toDelete = a->getNext();
                a->setNext(toDelete->getNext());
                delete toDelete;

                if (pos == size - 1) {  
                    last = a;
                }
            }

            size--;  
        }

        void insert(T elem, unsigned int pos){
            Node* newNodo = new Node(elem);
            Node* i=first;
            for (unsigned int a=0 ; a < pos;i= i->getNext(),a++){} 
            Node* aux = i->getNext();
            i->setNext(newNodo);
            newNodo->setNext(aux);
        }
};