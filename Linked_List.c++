#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* previous;
    Node() {
        next = NULL;
        previous = NULL;
    }
};

template<typename T>
class SingleLinkedList {
private:

    Node<T>* head = NULL;
    int size = 0;

public:

// Insertion Functions Start 
    void insertAtHead(T element) {
        Node<T>* newNode = new Node<T>;
        newNode->data = element;
        newNode->previous = NULL;
        size++;
        if(this->isEmpty()) {
            head = newNode;
            newNode->next = NULL;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtTail(T element) {
        Node<T>* newNode = new Node<T>;
        newNode->data = element;
        newNode->previous = NULL;
        size++;
        if(this->isEmpty()) {
            head = newNode;
            newNode->next = NULL;
        }
        else {
            Node<T>* last = head;
            while (last->next != NULL)
            {
                last = last->next;
            }
            last->next = newNode;
            newNode->next = NULL;
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
        if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
        }
        else {
            Node<T>* del = head;
            head = head->next;
            delete del;
            size--;
        }
    }

    void removeAtTail() {
        if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
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
        else if(index == size - 1) {removeAtTail();}
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
        if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
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
        if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
        }
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

// Retrieve, Replace & Swap Funcations Start
    T retrieveAt(int index) {
        if(index < 0 || index >= size) {
            cout << "Invalid Range";    
        }
        else if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
        }
        else {
            Node<T>* current = head;
            for(int i = 0;i < index;i++)
                current = current->next;
            
            return current->data;
        }  
    }

    void replaceAt(T newElement, int index) {
        if(index < 0 || index >= size) {
            cout << "Invalid Range";    
        }
        else if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
        }
        else {
            Node<T>* current = head;
            for(int i = 0;i < index;i++)
                current = current->next;

            current->data = newElement;
        }    
    }

    bool isItemAtEqual(T element, int index) {
       if(index < 0 || index >= size) {
            cout << "Invalid Range";    
        }
        else if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
        }
        else {
            Node<T>* current = head;
            for(int i = 0;i < index;i++)
                current = current->next;

            return current->data == element;
        }  
    }

    void swap (int firstIndex, int secondIndex) {
        if((firstIndex < 0 || firstIndex >= size) && (secondIndex < 0 || secondIndex >= size)) {
            cout << "Invalid Range";    
        }
        else if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
        }
        else {
            Node<T>* firstNode = head; 
            Node<T>* secondNode = head;
            Node<T>* temp = NULL;
            for(int i = 0;i < firstIndex;i++) 
                firstNode = firstNode->next;
            for(int i = 0;i < secondIndex;i++) 
                secondNode = secondNode->next;

            temp = firstNode->next;
            firstNode->next = secondNode->next;
            secondNode->next = temp;
        }          
    }

// Retrieve, Replace & Swap Funcations End
};


template<typename T>
class doubleLinkedList {
private:

    Node<T>* head = NULL;
    Node<T>* tail = NULL;
    int size = 0;

public:
// Insertion Functions Start 
    void insertAtHead(T element) {
        Node<T>* newNode = new Node<T>;
        newNode->data = element;
        newNode->previous = NULL;
        size++;
        if(this->isEmpty()) {
            head = newNode;
            tail = newNode;
            newNode->next = NULL;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtTail(T element) {
        Node<T>* newNode = new Node<T>;
        newNode->data = element;
        newNode->next = NULL;
        size++;
        if(this->isEmpty()) {
            head = newNode;
            tail = newNode;
            newNode->previous = NULL;
        }
        else {
            newNode->previous = tail;
            tail = newNode;
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
            Node<T>* prev = head;
            for(int i = 0; i < index - 1; i++) {
                prev = current;
                current = current->next;
            }
            current->previous = newNode;
            prev->next = newNode;
            newNode->next = current;
            newNode->previous = prev;
            size++;
        }
    }
// Insertion Functions End

// Remove Functions Start 
    void removeAtHead(){
        if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
        }
        else {
            Node<T>* del = head;
            Node<T>* newFirst = del->next;
            head = newFirst;
            newFirst->previous = NULL;
            delete del;
            size--;
        }
    }

    void removeAtTail() {
        if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
        }
        else {
            Node<T>* del = tail;
            Node<T>* newLast = tail->previous;
            tail = newLast;
            newLast->next = NULL; 
            delete del;
            size--;
        }
    }

    void removeAt(int index) {
        if(index < 0 || index >= size) {
            cout << "Invalid Range";    
        }
        else if(index == 0) {removeAtHead();}
        else if(index == size - 1) {removeAtTail();}
        else {
            Node<T>* current = head;
            for(int i = 0;i < index;i++) {
                current = current->next;
            }
            current->previous->next = current->next;
            current->next->previous = current->previous;
            delete current;
            size--;
        }
    }
// Remove Functions End 

// Print, Clear & Size funcations Start
    void print() {
        Node<T>* current = head;
        if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
        }
        else {
            while (current != NULL)
            {
                cout << current->data << '\t';
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
        tail = NULL;
        size = 0;
    }

    int linkedListSize() {return size;}
// Print, Clear & Size funcations End

// Boolean Functions Start 
    bool isExist(T element) {
        if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
        }
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

// Retrieve, Replace & Swap Funcations Start
    T retrieveAt(int index) {
        if(index < 0 || index >= size) {
            cout << "Invalid Range";    
        }
        else if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
        }
        else {
            Node<T>* current = head;
            for(int i = 0;i < index;i++)
                current = current->next;
            
            return current->data;
        }  
    }

    void replaceAt(T newElement, int index) {
        if(index < 0 || index >= size) {
            cout << "Invalid Range";    
        }
        else if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
        }
        else {
            Node<T>* current = head;
            for(int i = 0;i < index;i++)
                current = current->next;

            current->data = newElement;
        }    
    }

    bool isItemAtEqual(T element, int index) {
       if(index < 0 || index >= size) {
            cout << "Invalid Range";    
        }
        else if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
        }
        else {
            Node<T>* current = head;
            for(int i = 0;i < index;i++)
                current = current->next;

            return current->data == element;
        }  
    }

    void swap (int firstIndex, int secondIndex) {
        if((firstIndex < 0 || firstIndex >= size) && (secondIndex < 0 || secondIndex >= size)) {
            cout << "Invalid Range";    
        }
        else if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
        }
        else {
            Node<T>* firstNode = head; 
            Node<T>* secondNode = head;
            Node<T>* temp = NULL;
            for(int i = 0;i < firstIndex;i++) 
                firstNode = firstNode->next;
            for(int i = 0;i < secondIndex;i++) 
                secondNode = secondNode->next;

            temp = firstNode->next;
            firstNode->next = secondNode->next;
            secondNode->next = temp;
        }          
    }

// Retrieve, Replace & Swap Funcations End
};

template<typename T>
class circularLinkedList {
private:

    Node<T>* head = NULL;
    int size = 0;

public:
// Insertion Functions Start 
    void insertAtHead(T element) {
        Node<T>* newNode = new Node<T>;
        newNode->data = element;
        size++;
        if(this->isEmpty()) {
            head = newNode;
            newNode->next = head;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtTail(T element) {
        Node<T>* newNode = new Node<T>;
        newNode->data = element;
        size++;
        if(this->isEmpty()) {
            head = newNode;
            newNode->next = newNode;
        }
        else {
            Node<T>* last = head;
            while(last->next != head) last = last->next;
            last->next = newNode;
            newNode->next = head;
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
            Node<T>* prev = head;
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
        if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
        }
        else {
            Node<T>* del = head;
            Node<T>* newFirst = del->next;
            head = newFirst;
            delete del;
            size--;
        }
    }

    void removeAtTail() {
        if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
        }
        else {
            Node<T>* del = head;
            Node<T>* prev = NULL;
            while(del->next != head) {
                prev = del;
                del = del->next;
            }
            prev->next = head;
            delete del;
            size--
        }
    }

    void removeAt(int index) {
        if(index < 0 || index >= size) {
            cout << "Invalid Range";    
        }
        else if(index == 0) {removeAtHead();}
        else if(index == size - 1) {removeAtTail();}
        else {
            Node<T>* del = head;
            Node<T>* prev = NULL; 
            for(int i = 0;i < index;i++) {
                prev = del;
                del = del->next;
            }
            prev->next = del->next;
            delete del;
            size--;
        }
    }
// Remove Functions End 

// Print, Clear & Size funcations Start
    void print() {
        Node<T>* current = head;
        if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
        }
        else {
            while (current != NULL)
            {
                cout << current->data << '\t';
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
        tail = NULL;
        size = 0;
    }

    int linkedListSize() {return size;}
// Print, Clear & Size funcations End

// Boolean Functions Start 
    bool isExist(T element) {
        if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
        }
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

// Retrieve, Replace & Swap Funcations Start
    T retrieveAt(int index) {
        if(index < 0 || index >= size) {
            cout << "Invalid Range";    
        }
        else if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
        }
        else {
            Node<T>* current = head;
            for(int i = 0;i < index;i++)
                current = current->next;
            
            return current->data;
        }  
    }

    void replaceAt(T newElement, int index) {
        if(index < 0 || index >= size) {
            cout << "Invalid Range";    
        }
        else if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
        }
        else {
            Node<T>* current = head;
            for(int i = 0;i < index;i++)
                current = current->next;

            current->data = newElement;
        }    
    }

    bool isItemAtEqual(T element, int index) {
       if(index < 0 || index >= size) {
            cout << "Invalid Range";    
        }
        else if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
        }
        else {
            Node<T>* current = head;
            for(int i = 0;i < index;i++)
                current = current->next;

            return current->data == element;
        }  
    }

    void swap (int firstIndex, int secondIndex) {
        if((firstIndex < 0 || firstIndex >= size) && (secondIndex < 0 || secondIndex >= size)) {
            cout << "Invalid Range";    
        }
        else if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
        }
        else {
            Node<T>* firstNode = head; 
            Node<T>* secondNode = head;
            Node<T>* temp = NULL;
            for(int i = 0;i < firstIndex;i++) 
                firstNode = firstNode->next;
            for(int i = 0;i < secondIndex;i++) 
                secondNode = secondNode->next;

            temp = firstNode->next;
            firstNode->next = secondNode->next;
            secondNode->next = temp;
        }          
    }

// Retrieve, Replace & Swap Funcations End
};

int main() {

    SingleLinkedList<int> ll; 
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
