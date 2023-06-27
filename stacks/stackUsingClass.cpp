#include <iostream>
#include <stack>
using namespace std;

// LIFO -> Last In First Out
class Stack {
    int size, top;
    int *arr;

public:
    Stack(int size) {  
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) {
        if(size - top > 1) {
            top++;
            arr[top] = element;
        }
    }

    void pop() {
        if(top >= 0) top--;
    }

    int peek() {
        if(top >= 0 && top < size) return arr[top];
        else return -1;
    }

    bool isEmpty() {
        if(top == -1) return true;
        return false;
    }
};

class TwoStacks {
    int size;
    int *arr;
    int top1, top2;

public:
    TwoStacks(int s) {
        this->size = s;
        int top1 = -1;
        int top2 = s;
        arr = new int[s];
    }

    void push1(int num) {
        // atleast 1 empty space present
        if(top2 - top1 > 1) {
            top1++;
            arr[top1] = num;
        }
    }

    void push2(int num) {
        if(top2 - top1 > 1) {
            top2--;
            arr[top2] = num;
        }
    }

    int pop1() {
        if(top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        
        return -1;
    }

    int pop2() {
        if(top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        
        return -1;
    }
};

int main() {
    Stack st(5);
    st.push(22);
    st.push(43);
    st.push(44);
    
    st.pop();
    cout << st.peek() << endl;
    return 0;
}