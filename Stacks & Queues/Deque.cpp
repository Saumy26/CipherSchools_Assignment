#include <iostream>
using namespace std;
#define MAX 10

class Deque {
  int arr[MAX];
  int front;
  int rear;
  int size;

  public:
  Deque(int size) {
    front = -1;
    rear = 0;
    this->size = size;
  }
  void insertfront(int key);
  void insertrear(int key);
  void deletefront();
  void deleterear();
  bool isFull();
  bool isEmpty();
  int getFront();
  int getRear();
};

bool Deque::isFull() {
  return ((front == 0 && rear == size - 1) || front == rear + 1);
}

bool Deque::isEmpty() {
  return (front == -1);
}

void Deque::insertfront(int key) {
  if (isFull()) {
    cout << "Overflow\n"
       << endl;
    return;
  }
  if (front == -1) {
    front = 0;
    rear = 0;
  }
  else if (front == 0) {
    front = size - 1;
  }
  else {
    front = front - 1;
  }
  arr[front] = key;
}

void Deque ::insertrear(int key) {
  if (isFull()) {
    cout << " Queue Overflow" << endl;
    return;
  }
  if (front == -1) {
    front = 0;
    rear = 0;
  }
  else if (rear == size - 1) {
    rear = 0;
  }
  else {
    rear = rear + 1;
  }
  arr[rear] = key;
}

void Deque ::deletefront() {
  if (isEmpty()) {
    cout << "Queue Underflow" << endl;
    return;
  }

  if (front == rear) {
    front = -1;
    rear = -1;
  } 
  else if (front == size - 1)
    front = 0;
  else
    front = front + 1;
}

void Deque::deleterear() {
  if (isEmpty()) {
    cout << " Underflow" << endl;
    return;
  }

  if (front == rear) {
    front = -1;
    rear = -1;
  } 
  else if (rear == 0)
    rear = size - 1;
  else
    rear = rear - 1;
}

int Deque::getFront() {
  if (isEmpty()) {
    cout << " Underflow "<< endl;
    return -1;
  }
  return arr[front];
}

int Deque::getRear() {
  if (isEmpty() || rear < 0) {
    cout << " Underflow"<< endl;
    return -1;
  }
  return arr[rear];
}

int main() {
  Deque dq(4);
  dq.insertrear(5);
  dq.insertrear(11);
  cout << "Element at Rear : " <<dq.getRear() <<endl;
  dq.deleterear();
  cout << "New element at Rear after deletion : " <<dq.getRear() <<endl;
  dq.insertfront(8);
  cout << "Element at Front : " <<dq.getFront() <<endl;
  dq.deletefront();
  cout << "New element at Front after deletion : " <<dq.getFront() <<endl;
}
