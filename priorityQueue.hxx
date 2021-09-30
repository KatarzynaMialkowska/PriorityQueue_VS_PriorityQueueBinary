#include <iostream>


template <class T>
class priorityQueue
{
    struct Node {
        Node *next;
        int priority;
        T x;
    };
    Node *head;
    Node *tail;

  public:
    priorityQueue() : head(nullptr), tail(nullptr) {}
    ~priorityQueue() { while(head) pop(); }
    
    T front() {
        if(head) return head->x;
        else throw std::out_of_range("Error");
    }

    int front_priority() { 
        if(!head) throw std::out_of_range("Error");
        else return head->priority;
    }

    void push(int priority, T v) {
        Node *interator;
        Node *new_node = new Node();
        new_node->priority = priority;
        new_node->x = v;

        if(empty()) {
            new_node->next = nullptr;
            head = new_node;
            tail = new_node;
        }else if(head->priority < priority) {
            new_node->next = head;
            head = new_node;
        }else {
            interator = head;
            while(interator->next!=nullptr && interator->next->priority >= priority) {
                interator = interator->next;
            }
            if(interator->next==nullptr){}
            new_node->next = interator->next;
            interator->next = new_node;
            if(!new_node->next) tail = new_node;
        }
    }

    void pop(void) {
        if(head) {
            Node * p = head;
            head = head->next;
            if( !head ) tail = NULL;
            delete p;
        }
    }

    bool empty() { return !head; }
};
