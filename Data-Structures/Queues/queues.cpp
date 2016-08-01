#include<iostream>
using namespace std;
const int MAX = 10;

class queue {
    private:
        int arr[MAX];
        int front, rear;

    public:
        queue() {
            front = -1;
            rear = -1;
            return;
        }

        void addq(int item) {
            if(rear == MAX - 1) {
                cout << "Queue is full" << endl;
                return;
            }

            rear++;
            arr[rear] = item;

            if(front == -1)
                front = 0;

        }

        int delq() {
            if(front == -1) {
                cout << "Queue is empty" << endl;
                return 0;
            }

            int data = arr[front];
            if(front == rear)
                front = rear = -1;

            else
                front ++;

            return data;
        }
};

int main() {
    queue a;

    a.addq(10);
    a.addq(11);
    a.addq(12);

    int i = a.delq();
    cout << endl << "Item deleted = " << i;
    return 0;

}
