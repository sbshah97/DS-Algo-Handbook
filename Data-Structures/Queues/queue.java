package xyz;

public class QueueImplementation {

    private int capacity;
    int queueArr[];
    int front = 0;
    int rear = -1;
    int currentSize = 0;

    public QueueImplementation(int queueSize){
        this.capacity = queueSize;
        queueArr = new int[this.capacity];
    }

    public void enqueue(int item) {
        if (isQueueFull()) {
            System.out.println("Unable to add element: "+item);
        } else {
            rear++;
            if(rear == capacity-1){
                rear = 0;
            }
            queueArr[rear] = item;
            currentSize++;
            System.out.println("Element " + item+ " is pushed to Queue !");
        }
    }


    public void dequeue() {
        if (isQueueEmpty()) {
            System.out.println("Unable to remove element from Queue");
        } else {
            front++;
            if(front == capacity-1){
                System.out.println("Pop operation done ! removed: "+queueArr[front-1]);
                front = 0;
            } else {
                System.out.println("Pop operation done ! removed: "+queueArr[front-1]);
            }
            currentSize--;
        }
    }


    public boolean isQueueFull(){
        boolean status = false;
        if (currentSize == capacity){
            status = true;
        }
        return status;
    }


    public boolean isQueueEmpty(){
        boolean status = false;
        if (currentSize == 0){
            status = true;
        }
        return status;
    }

    public static void main(String a[]){

        QueueImplementation queue = new QueueImplementation(4);
        queue.enqueue(1);
        queue.dequeue();
        queue.enqueue(2);
        queue.enqueue(3);
        queue.enqueue(4);
        queue.dequeue();
        queue.dequeue();
        queue.enqueue(5);
        queue.dequeue();
        queue.enqueue(6);
        queue.enqueue(7);
        queue.enqueue(8);
        queue.enqueue(9);
    }
}
