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
            head->previous = newNode;
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
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAt(T element, int index) {
        if(index < 0 || index > size) {
            cout << "Invalid Index" << endl;
            return;
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
            for(int i = 0; i < index; i++) {
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
            return;
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
            return;
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
            return;   
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
            return;
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
            return false;
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

    bool isItemAtEqual(T element, int index) {
       if(index < 0 || index >= size) {
            cout << "Invalid Range";
            return false;    
        }
        else if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
            return false;
        }
        Node<T>* current = head;
        for(int i = 0;i < index;i++)
            current = current->next;

        return current->data == element;  
    }

    bool isEmpty() {return head == NULL;}
// Boolean Functions End 

// Retrieve, Replace & Swap Funcations Start
    T retrieveAt(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Invalid Range");
        }

        if (this->isEmpty()) {
            throw runtime_error("List Is Empty!");
        }

        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            if (current == NULL) {
                throw out_of_range("Invalid Range");
            }
            current = current->next;
        }

        if (current == NULL) {
            throw out_of_range("Invalid Range");
        }

        return current->data;  
    }

    void replaceAt(T newElement, int index) {
        if(index < 0 || index >= size) {
            cout << "Invalid Range"; 
            return;   
        }
        else if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
            return;
        }
        else {
            Node<T>* current = head;
            for(int i = 0;i < index;i++)
                current = current->next;

            current->data = newElement;
        }    
    }

    void swap (int firstIndex, int secondIndex) {
        if((firstIndex < 0 || firstIndex >= size) && (secondIndex < 0 || secondIndex >= size)) {
            cout << "Invalid Range" << endl;
            return;    
        }

        if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
            return;
        }
        
        if(firstIndex == secondIndex) {
            return;
        } 

        Node<T>* prevFirstNode = NULL;
        Node<T>* firstNode = head;
        for (int i = 0; i < firstIndex; ++i) {
            prevFirstNode = firstNode;
            firstNode = firstNode->next;
        }
        
        Node<T>* prevSecondNode = NULL;
        Node<T>* secondNode = head;
        for (int i = 0; i < secondIndex; ++i) {
            prevSecondNode = secondNode;
            secondNode = secondNode->next;
        }

        if (prevFirstNode != NULL) {
        prevFirstNode->next = secondNode;
        } else {
            head = secondNode;
        }

        if (prevSecondNode != NULL) {
            prevSecondNode->next = firstNode;
        } else {
            head = firstNode;
        }

        Node<T>* tempNext = secondNode->next;
        secondNode->next = firstNode->next;
        firstNode->next = tempNext;

        Node<T>* tempPrev = secondNode->previous;
        secondNode->previous = firstNode->previous;
        firstNode->previous = tempPrev;            
    }

// Retrieve, Replace & Swap Funcations End
};

int main() {

    doubleLinkedList<int> dll;

    dll.insertAtHead(12);
    dll.insertAtHead(13);
    dll.insertAtTail(15);
    dll.insertAt(14, 2);
    dll.print();

    cout << '\n';

    dll.removeAt(2);
    dll.removeAtHead();
    dll.removeAtTail();
    dll.print();

    cout << '\n';

    cout << dll.linkedListSize() << '\t';
    cout << dll.isEmpty() << '\t';
    cout << dll.isExist(12) << '\t';
    cout << dll.isExist(50) << '\t';
    cout << dll.isItemAtEqual(14, 2) << '\t';  

    cout << '\n';

    cout << dll.retrieveAt(3) << '\n';
    dll.replaceAt(16, 2);
    dll.swap(0, 1);
    dll.print();

return 0;
}