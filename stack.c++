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

template <typename T>
class stack {

private:

    Node<T>* head = NULL;
    int size = 0;

public:

    bool isEmpty() {
        return (head == NULL);
    }
    
    void push(T element) {
        Node<T>* node = new Node<T>;
        node->data = element;
        size++;
        
        if(isEmpty()) {
            head = node;
        }
        else {
            node->next = head;
            head = node;
        }
        
    }

    T pop() {
        
        if(isEmpty()) {
            throw runtime_error("Stack Is Empty!");
        }
        else {
            size--;
            Node<T>* temp = head;
            head = head->next;
            T poppedData = temp->data;
            delete temp;
            return poppedData;
        }
    }

    void print() {
        Node<T>* current = head;
        
        if(isEmpty()){
            cout << "Stack Is Empty";
        }

        else{
            while (current != NULL)
            {
                cout << current->data << "\t";
                current = current->next;
            }
            cout << endl;
        }
    }

    int stackSize() {
        return size;
    }

    T top() {
        if (isEmpty())
        {
            throw runtime_error("Stack Is Empty!");
        }
        else {
            return head->data;
        }
    }

    void clear() {
        while (head != NULL) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0; // Reset size to 0 after clearing the stack
    }
};

int main() {
    stack<string> s;
    s.push("nour");
    s.push("ahmed");
    s.push("careem");

    s.pop();


    s.print();
    return 0;
}
