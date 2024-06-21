// Queue implementation in C++

#include <iostream>
#define SIZE 5
// we are making the queue using an array , so we have defined the size before hand

using namespace std;

class Queue {
   private:
  int items[SIZE], front, rear;

   public:
   //ye ek constructor hai taaki jab bhi apan naya queue banaye , uska value already set ho jo constructor me diya hua hai
  Queue() {
    front = -1;
    rear = -1;
    //as queue staring me empty hota hai so humne front and rear ko -1 point karvaya hai mtlb they are pointing to null

  }

  bool isFull() {
    if (front == 0 && rear == SIZE - 1) {
      cout<<"Queue is full";
      return true;
    }
    return false;
    //queue full hai kya check karne wala function, isme agar front 0th index pe ho array ke , and rear = size -1 matlab last element pe ho , to apan true return karenge yani queue full hai or else false return karenge.
  }

  bool isEmpty() {
    if (front == -1)
      return true;
    else
      return false;
      //ye function check karega if queue empty hai, agar queue me ek bhi element ho to front -1 pe point nahi karta , if front -1 pe point kar raha then wo queue empty hai.
  }

  void enQueue(int element) {
    if (isFull()) {  //check karenge is the queue is full
      cout << "Queue is full"; //agar hua to print karenge full
    } else {
      if (front == -1) front = 0; 
      rear++;
      items[rear] = element;
      cout << endl
         << "Inserted " << element << endl;
         //hum check karenge if front -1 ko point kar rha then hum usko 0 pe layenge and fir rear ko ek index badhayenge, and then items[rear] = element; statement use karke value assgn karenge
    }
  }

  int deQueue() {
    int element;
    if (isEmpty()) {
      cout << "Queue is empty" << endl;
      return (-1);
    } else {
      element = items[front];//hum ye value ek element variable me store karenge taki hume pata chale ki kya delete kia hai
      if (front >= rear) {
        //ye condition check karega if front and rear same hue , to wo ek empty queue hai , to hum usko null point kardenge
        front = -1;
        rear = -1;
      }
      else {
        front++;
        //ye operation se tera deque hota hai,front++ karenge to element ka value apne aap delete hojata hai , inshort reference chala jata hai
      }
      cout << endl
         << "Deleted -> " << element << endl;
      return (element);
    }
  }

  void display() {

    int i;
    if (isEmpty()) {
      cout << endl
         << "Empty Queue" << endl;
    } else {
      cout << endl
         << "Front index-> " << front;
      cout << endl
         << "Items -> ";
      for (i = front; i <= rear; i++)
        cout << items[i] << "  ";
      cout << endl
         << "Rear index-> " << rear << endl;
    }
  }
};

int main() {
  Queue q;


  q.deQueue();


  q.enQueue(1);
  q.enQueue(2);
  q.enQueue(3);
  q.enQueue(4);
  q.enQueue(5);


  q.enQueue(6);

  q.display();


  q.deQueue();


  q.display();

  return 0;
}