#include <iostream>
using namespace std;

template <typename T>
class MyNode {
public:
    T data;
    MyNode* next;
    MyNode() {
        next = nullptr;
    }
};

template <typename T>
class MyQueue {
private:
    MyNode<T>* front;
    MyNode<T>* end;
public:
    MyQueue() {
        front = end = nullptr;
    }
    bool isEmpty() {
        return (front == nullptr);
    }
    void Enqueue(T item) {
        auto* newnode = new MyNode<T>();
        newnode->data = item;
        if (isEmpty()) {
            front = end = newnode;
        }
        else {
            end->next = newnode;
            end = newnode;
        }
    }
    void print() {
        if (isEmpty()) {
            cout << "The queue is empty!\n";
        } else {
            MyNode<T>* temp = front;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    T Dequeue(){
        T delValue;
        if(isEmpty()){
            cout<<"the Queue is empty";
            delValue = T(); // Return a default-constructed value if the queue is empty
        }
        else if(front==end){
            delValue = front->data;
            delete front;
            front=end=nullptr;
        }
        else{
            MyNode<T>* delptr=front;
            delValue = front->data;
            front=front->next;
            delete delptr;
        }
        return delValue;
    }
    T First(){
        return front->data;
    }
    T Tail(){
        return end->data;

    }
    int QueueSize(){
        int counter=0;
        MyNode<T>*temp=front;
        while(temp!= nullptr){
            counter++;
            temp=temp->next;
        }
        return counter;
    }
    bool isFound(T item){///extra function to search in queue
        MyNode<T>* temp = front;
        bool found= false;
        while (temp != nullptr) {
            if(temp->data==item){
                found= true;


            }
            temp=temp->next;

        }
        return found;
    }
    void clear(){
        while(!isEmpty()){
            Dequeue();
        }
        front=end=nullptr;
    }

};

int main() {
    MyQueue<int> q; // Example of using queue with integers
    int size;
    cout<<"Enter size of Queue that you want: ";
    cin>>size;

    for (int i = 0; i < size; i++) {
        int a;
        cout << "Enter item to Enqueue in queue: ";
        cin >> a;
        q.Enqueue(a);
    }

    q.print();
    cout<<q.isFound(4);
    //    q.print();
//    cout<<"First element in the queue: "<<q.First()<<"\n";
//    cout<<"Last element in the queue: "<<q.Tail()<<"\n";

//    q.Dequeue();

//    cout<<"clear all elements in queue\n";
//    q.clear();
//    cout<<"queue after clear\n";
//    q.print();

//    cout<<"First element in the queue: "<<q.First()<<"\n";
//    cout<<"Last element in the queue: "<<q.Tail()<<"\n";
//    cout<<" the size of queue is: "<<q.QueueSize()<<'\n'

    return 0;
}
// enqueue done
// dequeue done
//first done
//is empty done
// queue size done
//clear done
//print done