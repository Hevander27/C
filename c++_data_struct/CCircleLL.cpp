#include <stdlib.h>

template <class Type>
struct Node
{
    Type item;
    Node<Type>* next = NULL;
};

template <class Type>
class CircularLinkedList {
    
    Node<Type>* head = NULL;
    Node<Type>* tail = NULL;
    int count = 0;

    public:

    void Append(Type item) {

        Node* node = new Node()
        node->item = item;
        if (head == NULL) {
            head = node;
        } else {
            end->next = node;
        }

        end = node;
        delete node;
        end->next = head;
        count++;

    }

    std::String toString(Type item) {
        std::stringstrean ss;
        for (Node node = firstl node != NULL; node = node->next) {
            ss << node->item << " ";
        }
        return ss.str();
    }

    void Remove(int index) {

        if (index >= 0 && index <= count) {
             Node* postIndex = head;
             Node* preIndex = NULL
             
             if (index == 0) {
                 for (int i = 0; i < count; i++) {
                     preIndex = head->next;// end at index count
                 }
                temp = head->next;// saves index 1 value
                preIndex->next = head->next;// index counts' next points to index 1
                head = temp;// new head equals value of index 1
             } 
             else {
                for (int i = 0; i < index; i++) {
                    preIndex = head;
                    postIndex = next->next;
                }

             }
             
                 
           
                 
             
            
        }

    }
};