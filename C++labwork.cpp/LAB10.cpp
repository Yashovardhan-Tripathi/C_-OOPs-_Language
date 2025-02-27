#include <iostream>
using namespace std;

class Stack
{
private:
    int *arr;
    int top;
    int maxSize;

public:
    Stack(int size)
    {
        maxSize = size;
        arr = new int[maxSize];
        top = -1;
        cout << "Stack created with size " << maxSize << endl;
    }

    ~Stack()
    {
        delete[] arr;
        cout << "Stack destroyed." << endl;
    }

    void push(int element)
    {
        if (isFull())
        {
            cout << "Stack overflow! Cannot push " << element << endl;
        }
        else
        {
            arr[++top] = element;
            cout << element << " pushed to stack." << endl;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow! Cannot pop." << endl;
            return -1;
        }
        else
        {
            cout << arr[top] << " popped from stack." << endl;
            return arr[top--];
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == maxSize - 1;
    }
};

int main()
{
    cout << "Name:Yashovardhan Tripathi" << endl;
    cout << "PRN No.:230105231360" << endl;
    cout << "Division: D" << endl;
    cout << "Roll No.:14" << endl;
    cout << "Experiment No:10" << endl << endl;
    int stackSize;
    cout << "Enter the size of the stack: ";
    cin >> stackSize;
    Stack myStack(stackSize);
    int choice, element;
    do
    {
        cout << "\nChoose an operation to perform on the stack:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek (Top Element)" << endl;
        cout << "4. Check if Stack is Empty" << endl;
        cout << "5. Check if Stack is Full" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << "Enter the element to push: ";
            cin >> element;
            myStack.push(element);
            break;
        case 2:

            myStack.pop();
            break;
        case 3:

            element = myStack.peek();
            if (element != -1)
                cout << "Top element is: " << element << endl;
            break;
        case 4:

            if (myStack.isEmpty())
                cout << "Stack is empty." << endl;
            else
                cout << "Stack is not empty." << endl;
            break;
        case 5:

            if (myStack.isFull())
                cout << "Stack is full." << endl;
            else
                cout << "Stack is not full." << endl;
            break;
        case 6:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
