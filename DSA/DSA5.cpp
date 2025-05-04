#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node {
    char data;
    node *left;
    node *right;
};

class stack1 {
    node *data[30];
    int top;
public:
    stack1() {
        top = -1;
    }

    bool empty() {
        return top == -1;
    }

    void push(node *p) {
        if (top < 29) {
            data[++top] = p;
        } else {
            cout << "Stack overflow!\n";
        }
    }

    node* pop() {
        if (!empty()) {
            return data[top--];
        } else {
            cout << "Stack underflow!\n";
            return nullptr;
        }
    }

    node* peek() {
        if (!empty()) {
            return data[top];
        }
        return nullptr;
    }
};

class tree {
public:
    node *top;

    tree() {
        top = nullptr;
    }

    void expression(const char expr[]) {
        stack1 s;
        int len = strlen(expr);

        for (int i = len - 1; i >= 0; i--) {
            if (isalpha(expr[i])) {
                node *newNode = new node{expr[i], nullptr, nullptr};
                s.push(newNode);
            } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
                node *t1 = s.pop();
                node *t2 = s.pop();
                node *newNode = new node{expr[i], t1, t2};
                s.push(newNode);
            }
        }

        top = s.pop();
    }

    void display(node *root) {
        if (root != nullptr) {
            cout << root->data << " ";
            display(root->left);
            display(root->right);
        }
    }

    void non_rec_postorder(node *top) {
        if (top == nullptr) return;

        stack1 s1, s2;
        s1.push(top);

        while (!s1.empty()) {
            node *curr = s1.pop();
            s2.push(curr);

            if (curr->left) s1.push(curr->left);
            if (curr->right) s1.push(curr->right);
        }

        while (!s2.empty()) {
            node *n = s2.pop();
            cout << n->data << " ";
        }
        cout << "\n";
    }

    void del(node *n) {
        if (n == nullptr) return;

        del(n->left);
        del(n->right);

        delete n;
    }
};

int main() {
    char expr[30];
    tree t;

    cout << "Enter prefix expression: ";
    cin >> expr;

    t.expression(expr);

    cout << "\nPrefix expression (Preorder Traversal): ";
    t.display(t.top);
    cout << "\n";

    cout << "Non-Recursive Postorder Traversal: ";
    t.non_rec_postorder(t.top);

    cout << "Deleting tree...\n";
    t.del(t.top);
    t.top = nullptr;

    cout << "Tree deleted successfully.\n";

    return 0;
}
