#include <iostream>
using namespace std;

template <typename T>
class Clist{
    private:
        class Node{
            private:
                Node* next;
                T data;

            public:
                Node(T elem): data(elem), next(nullptr){}
                T getData(){ return data;}
                Node* getNext() { return next; }
                void setNext( Node *newNext ) { next=newNext; }
        };

        Node *head; 
        Node *tail;
        unsigned int size; 
        
    public:
        Clist() : head(nullptr), tail(nullptr), size(0) {}

        bool empty() { return head == nullptr; }

        
        void push_front(T elem){
            Node *newNode = new Node(elem);
            
            if(empty()){
                head = newNode;
                tail = newNode;
                newNode -> setNext(head);
            } else {
                newNode ->setNext(head);
                head = newNode; 
                tail->setNext(head);
            }

            size++;
        }

        void insert(T elem, unsigned int pos){
            if(pos > size){
                return; 
            }

            if(pos == 0){
                push_front(elem);
            } else if (pos == size) {
                pushback(elem);
            } else {
                Node *newNode = new Node(elem);
                Node *node = head; 

                for(unsigned int i=0; i < pos-1; i++){
                    node = node->getNext();
                }
                
                newNode->setNext(node->getNext());
                node->setNext(newNode);
                size++;
            }
        }

        void pushback(T elem){
            Node* newElement = new Node(elem); 
            if(empty()){
                head= newElement;
                tail= newElement;
                tail->setNext(head);
            }else{
                tail->setNext(newElement);
                tail= newElement;
                tail->setNext(head);
            }
            size++;
        }

        void Print(){
            if ( empty()){
                cout << "{ }";
                return;
            }
            Node* i = head;
            do{
                cout << i->getData() << " ";
                i=i->getNext();
            }while( i!= head);
        }

        void remove(unsigned int pos){
            Node* toDelete=nullptr;
            if (pos ==0){
                toDelete=head;
                tail->setNext(toDelete->getNext());
                head=toDelete->getNext();
            }else{
                Node* temp=head;
                for ( int i =0; i < pos-1;i++){
                    temp=temp->getNext();
                }
                toDelete = temp->getNext();
                if ( pos == size-1){
                    temp->setNext(toDelete->getNext());
                    tail= temp;
                }else{
                    temp->setNext(toDelete->getNext());
                }
            }
            delete toDelete;
            size--;
        }
};
