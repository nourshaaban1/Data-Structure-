#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node() {
        next = NULL;
    }
};

template<typename T>
class LinkedList {
private:

    Node<T>* head = NULL;
    int size = 0;

public:

// Insertion Functions Start 
    void insertAtHead(T element) {
        Node<T>* node = new Node<T>;
        node->data = element;
        size++;
        if(isEmpty()) {
            head = node;
            node->next = NULL;
        }
        else {
            node->next = head;
            head = node;
        }
    }

    void insertAtTail(T element) {
        Node<T>* node = new Node<T>;
        node->data = element;
        size++;
        if(isEmpty()) {
            head = node;
            node->next = NULL;

        }
        else {
            Node<T>* Last = head;
            while (Last->next != NULL)
            {
                Last = Last->next;
            }
            Last->next = node;
            node->next = NULL;
        }
    }

    void insertAt(T element, int index) {
        if(index < 0 || index > size) {
            cout << "Invalid Index" << endl;
        }
        else if(index == 0) {
            insertAtHead(element);
        }
        else if(index == size) {
            insertAtTail(element);
        
        }
        else {
            Node<T>* newNode = new Node<T>;
            newNode->data = element;
            
            Node<T>* current = head;
            for(int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            size++;
        }
    }
// Insertion Functions End 

// Remove Functions Start 
    void removeAtHead(){
        if(isEmpty()) {
            cout << "Stack Is Empty!" << endl;
        }
        else {
            Node<T>* del = head;
            head = head->next;
            size--;
        }
    }

    void removeAtTail() {
        if(isEmpty()) {
            cout << "Stack Is Empty!" << endl;
        }
        else {
            Node<T>* prev = head;
            Node<T>* del = head;
            while (del->next != NULL) 
            {
                prev = del;
                del = del->next;
            }
            prev->next = NULL;
            delete del;
            size--;
        }
    }

    void removeAt(int index) {
        if(index < 0 || index >= size) {
            cout << "Invalid Range";    
        }
        else if(index == 0) {removeAtHead();}
        else if(index == size - 1) {removeAtHead();}
        else {
            Node<T>* prev = head;
            Node<T>* current = head;
            for(int i = 0;i < index;i++) {
                prev = current;
                current = current->next;
            }
            prev->next = current->next;
            delete current;
            size--;
        }
    }
// Remove Functions End 

    void print() {
        Node<T>* current = head;
        if(isEmpty()) {
            cout << "Stack Is Empty!" << endl;
        }
        else {
            while (current != NULL)
            {
                cout << current->data << "\t";
                current = current->next;
            }
            cout << endl;
        }
    }

    void clear() {
        Node<T>* current = head;
        
        while (current != NULL)
        {
            Node<T>* prev = current;
            current = current->next;
            delete prev;
        }
        head = NULL;
        size = 0;
    }

    int linkedListSize() {return size;}

// Boolean Functions Start 
    bool isExist(T element) {
        Node<T>* current = head;
        while (current != NULL)
        {
            if(current->data == element) {
                return true;
            }
            current = current->next; 
        }
        
        return false;
        
        }

    bool isEmpty() {return head == NULL;}
// Boolean Functions End 



};



int main() {

    LinkedList<int> ll; 
    ll.insertAtHead(20);
    ll.insertAtHead(10);
    ll.print();
    
    ll.insertAtTail(50);
    ll.insertAtTail(70);
    ll.print();

    ll.insertAtHead(5);
    ll.print();

    ll.insertAt(25,3);
    ll.print();

    ll.removeAtHead();
    ll.print();

    ll.removeAtTail();
    ll.print();

    ll.removeAt(1);
    ll.print();

    cout << ll.isExist(20);
}
