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
            Node<T>* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = newNode;
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
            return;
        }
        else {
            do {
            cout << current->data << '\t';
            current = current->next;
            } while (current != head);
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
// Print, Clear & Size funcations End

// Boolean Functions Start 
    bool isExist(T element) {
        if(this->isEmpty()) {
            cout << "List Is Empty!" << endl;
        }
        Node<T>* current = head;
        do {
            if(current->data == element) {
                return true;
            }
            current = current->next; 
        } while (current != head);      
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

    void swap (int firstIndex, int secondIndex) {
        if(firstIndex < 0 || firstIndex >= size || secondIndex < 0 || secondIndex >= size) {
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

        Node<T>* temp = secondNode->next;
        secondNode->next = firstNode->next;
        firstNode->next = temp;

    }
// Retrieve, Replace & Swap Funcations End
};

int main() {

circularLinkedList<int> cll;

    cll.insertAtHead(12);
    cll.insertAtHead(13);
    cll.insertAtTail(15);
    cll.insertAt(14, 2);
    cll.print();

    cout << '\n';

    // cll.removeAt(2);
    // cll.removeAtHead();
    // cll.removeAtTail();
    // cll.print();

    cout << '\n';

    cout << cll.linkedListSize() << '\t';
    cout << cll.isEmpty() << '\t';
    cout << cll.isExist(12) << '\t';
    cout << cll.isExist(50) << '\t';
    cout << cll.isItemAtEqual(14, 2) << '\t';  

    cout << '\n';

    cout << cll.retrieveAt(3) << '\n';
    cll.replaceAt(16, 2);
    cll.swap(0, 1);
    cll.print();

return 0;
}

