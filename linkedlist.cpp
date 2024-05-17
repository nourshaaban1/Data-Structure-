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
class singleLinkedList {
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
            return;
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
            return;
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
            return;    
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
            return;
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
        
        Node<T>* prevSecondNode = nullptr;
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

        Node<T>* temp = secondNode->next;
        secondNode->next = firstNode->next;
        firstNode->next = temp;                
    }

// Retrieve, Replace & Swap Funcations End
};

int main() {

    // singleLinkedList<int> sll; 
    // sll.insertAtHead(12);
    // sll.insertAtHead(13);
    // sll.insertAtTail(15);
    // sll.insertAt(14, 2);
    // sll.print();

    // cout << '\n';

    // sll.removeAt(2);
    // sll.removeAtHead();
    // sll.removeAtTail();
    // sll.print();

    // cout << '\n';

    // cout << sll.linkedListSize() << '\n';
    // cout << sll.isEmpty() << '\n';
    // cout << sll.isExist(12) << '\n';
    // cout << sll.isExist(50) << '\n';
    // cout << sll.isItemAtEqual(14, 0) << '\n';  

    // cout << '\n';

    // cout << sll.retrieveAt(3) << '\n';
    // sll.replaceAt(16, 2);
    // sll.swap(0, 1);
    // sll.print();

    // cout << '\n';

return 0;
}