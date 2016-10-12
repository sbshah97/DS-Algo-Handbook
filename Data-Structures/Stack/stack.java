package xyz;

public class StackImpl {

    private int stackSize;
    private int[] stackArr;
    private int top;

    public StackImpl(int size) {
        this.stackSize = size;
        this.stackArr = new int[stackSize];
        this.top = -1;
    }


    public void push(int entry) throws Exception {
        if(this.isStackFull()){
            throw new Exception("Stack is already full.");
        }
        System.out.println("Adding: "+entry);
        this.stackArr[++top] = entry;
    }


    public int pop() throws Exception {
        if(this.isStackEmpty()){
            throw new Exception("Can not remove element.");
        }
        int entry = this.stackArr[top--];
        System.out.println("Removed entry: "+entry);
        return entry;
    }


    public int peek() {
        return stackArr[top];
    }


    public boolean isStackEmpty() {
        return (top == -1);
    }

    public boolean isStackFull() {
        return (top == stackSize - 1);
    }

    public static void main(String[] args) {
        StackImpl stack = new StackImpl(5);
        try {
            stack.push(1);
            stack.push(2);
            stack.push(3);
            stack.push(4);
            stack.pop();
            stack.push(5);
            stack.push(6);
            stack.push(7);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        try {
            stack.pop();
            stack.pop();
            stack.pop();
            stack.pop();
            stack.pop();
            stack.pop();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
