// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

std::string infx2pstfx(std::string infx) {
    TStack<char, 20> stack;
    std::map<char, int> ops;
    ops['('] = 0;
    ops[')'] = 1;
    ops['+'] = 2;
    ops['-'] = 2;
    ops['*'] = 3;
    ops['/'] = 3;
    std::string pstfx;
    for (char a : infx) {
        if (ops.find(a) == ops.end()) {
            pstfx = pstfx + a + ' ';
        } else {
            if (a == ')') {
                while (stack.get() != '(') {
                    pstfx = pstfx + stack.get() + ' ';
                    stack.pop();
                }
                stack.pop();
            } else {
                if (ops[a] > ops[stack.get()]) {
                    stack.push(a);
                } else {
                    if (a == '(' || stack.isEmpty()) {
                        stack.push(a);
                    } else {
                        while (ops[stack.get()] >= ops[a] && !stack.isEmpty()) {
                            pstfx = pstfx + stack.get() + ' ';
                            stack.pop();
                        }
                        stack.push(a);
                    }
                }
                }
            }
        }
    while (!stack.isEmpty()) {
        pstfx = pstfx + stack.get() + ' ';
        stack.pop();
    }
    pstfx.pop_back();
    return pstfx;
}

int eval(std::string pstfx) {
    TStack<int, 20> stack;
    for (char a : pstfx) {
        if (a == ' ')
            continue;
        if (a != '-' && a != '+' && a != '*' && a != '/') {
            stack.push(a - '0');
        } else {
            int arg2 = stack.get();
            stack.pop();
            int arg1 = stack.get();
            stack.pop();
            switch (a) {
            case '+':
                stack.push(arg1 + arg2);
                break;
            case '-':
                stack.push(arg1 - arg2 );
                break;
            case '*':
                stack.push(arg1 * arg2 );
                break;
            case '/':
                stack.push(arg1 / arg2 );
                break;
            }
        }
    }
    return stack.get();
}
