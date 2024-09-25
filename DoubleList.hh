#include <iostream>

using namespace std;

template <typename T>

class DList{
    private:
        class Node{
            private:
                T data;
                Node *prev;
                Node *next;

            public:
                Node(T elem) : prev(nullptr), next(nullptr), data(elem) {}
                Node *getPrev() { return prev; }
                Node *getNext() { return next; }
                void setNext( Node* newNext) { next = newNext; }
                void setPrev( Node* newPrev) { prev = newPrev; }
                T getData(){ return data; }

        };

        Node *first;
        Node *last;
        unsigned int size; 

    public:
        DList() : first(nullptr), last(nullptr), size(0) {}

        ~DList(){
            Node *n = first;

            while( n != nullptr ){
                first = n->getNext();
                delete n;
                n = first;
            }

            first = nullptr;
            last = nullptr;
        }

        unsigned int getSize(){ return size; }

        bool empty() { return first == nullptr; }

        void push_front(T elem){
            Node *newNode = new Node(elem);

            if( first == nullptr ){
                first = newNode;
                last = newNode;
            } else {
                newNode -> setNext(first);
                first -> setPrev(newNode);
                first = newNode;
            }

            size++;
        }

        void pushBack(T elem){
            Node* newNode = new Node(elem);
            if ( first==nullptr){
                first=newNode;
                last= newNode;
            }else{
                newNode->setPrev(last);
                last->setNext(newNode);
                last=newNode;
            }
            size++;
        }

        void Print(){
            if(empty()){
                cout << "{ }" << endl;
            } else {
                Node *n = first; 
                
                cout << "{ " ;
                while( n != nullptr ){
                    cout << n->getData() << " ";
                    n = n->getNext();
                }
                cout << "}" << endl;
            }
        }

        void PrintReverse(){
            if (empty()){ cout << "{ }"; return;}
            cout << "{ ";
            for(  Node* i = last ; i!= nullptr; i= i->getPrev()){
                cout << i->getData() <<", ";
            }
            cout << "\b\b }";
        }     


};