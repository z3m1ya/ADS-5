// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
 private:
    T arr[size] = { '0' };
    int top;

 public:
    TStack() :top(-1) { }
    bool isEmpty() const {
        return top == -1;
    }
    bool isFull() const {
        return top == size - 1;
    }
    void pop() {
        if (!isEmpty())
            top--;
        else
            throw "Empty!";
    }
    void push(T value) {
        if (!isFull())
            arr[++top] = value;
        else
            throw "Full!";
    }
    T get() const {
        return arr[top];
    }
};

#endif  // INCLUDE_TSTACK_H_
