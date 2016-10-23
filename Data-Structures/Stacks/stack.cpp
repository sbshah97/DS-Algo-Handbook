//Implementation of stack
#include<iostream>

using namespace std;
const int MAX=10;

class stack {

    private:
        int arr[MAX];
        int top;

    public:
        stack() {
            top = -1;
        }

        void push(int item) {
            if(top == MAX -1) {
            cout << endl << "Array is full" ;
            return;
            }

            top ++;
            arr[top] = item;
        }

        int pop() {
            if(top == -1) {
                cout << endl << "Array is empty";
                return 0;
            }

            int data =arr[top];
            top--;

            return data;
        }

};

int main() {

    stack s;
    int n = 3;
    cout << "Enter three elements to enter into ";
    cout << "the stack" << endl;
    while(n) {
        int i;
        cin >> i;
        s.push(i);
        n--;
        }

    int i = s.pop();
    cout << "Item removed is " << i;

    return 0;
}
