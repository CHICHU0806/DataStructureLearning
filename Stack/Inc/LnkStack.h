//
// Created by 20852 on 2025/12/4.
//

#ifndef DATASTRUCTANDALGORITHMLEARING_LNKSTACK_H
#define DATASTRUCTANDALGORITHMLEARING_LNKSTACK_H

class LnkStack {
public:
    LnkStack();   // constructor
    ~LnkStack();  // destructor

    bool isEmpty() const;    // check empty
    bool push(int x);        // push
    bool pop();              // pop
    bool topValue(int &x) const;   // get top value
    void clear();            // clear stack
    void print() const;      // print stack

private:
    struct Node {            // inner node type
        int data;
        Node* next;
        Node(int d, Node* n = nullptr) : data(d), next(n) {}
    };

    Node* top;               // pointer to the top node
};

#endif //DATASTRUCTANDALGORITHMLEARING_LNKSTACK_H