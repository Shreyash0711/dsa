#include<iostream>
using namespace std;

class btnode {
public:
    btnode *left, *right;
    char data[20];
};

class book {
public:
    btnode *root, *temp;
    char data[20];
    book() {
        temp = root = NULL;
    }

    void create();
    void insert(btnode *root, btnode *temp);
    void display();
    int height(btnode *node);
    void printLevel(btnode *root, int level);
    void printLevelOrder(btnode *root);
    void rec_inorder(btnode *root);
};

void book::create() {
    temp = new btnode;
    cout << "Enter the data : ";
    cin >> temp->data;
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL) {
        root = temp;
    }
    else {
        insert(root, temp);
    }
}

void book::insert(btnode *root, btnode *temp) {
    char ch;
    cout << "\nWhere to insert left/right?" << root->data << ":";
    cin >> ch;
    if (ch == 'r' || ch == 'R') {
        if (root->right == NULL) {
            root->right = temp;
        }
        else {
            insert(root->right, temp);
        }
    }
    else {
        if (root->left == NULL) {
            root->left = temp;
        }
        else {
            insert(root->left, temp);
        }
    }
}

void book::printLevel(btnode *root, int level) {
    if (root == NULL)
        return;
    if (level == 1) {
        cout << " " << root->data;
    }
    else if (level > 1) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

int book::height(btnode *node) {
    if (node == NULL)
        return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void book::printLevelOrder(btnode *root) {
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++) {
        cout << "\n";
        printLevel(root, i);
    }
}

void book::rec_inorder(btnode *root) {
    if (root != NULL) {
        rec_inorder(root->left);
        cout << root->data;
        rec_inorder(root->right);
    }
}

void book::display() {
    rec_inorder(root);
}

int main() {
    book b1;
    int flag = 1;
    do {
        int n;
        cout << "___Menu___" << endl;
        cout << "1)Create Details" << endl;
        cout << "2)Display Tree" << endl;
        cout << "3)Print level" << endl;
        cout << "4)Exit" << endl;
        cin >> n;
        if (n == 1) {
            b1.create();
        }
        else if (n == 2) {
            b1.display();
        }
        else if (n == 3) {
            b1.printLevelOrder(b1.root);
        }
        else if (n == 4) {
            cout << "Exiting the program" << endl;
            return 0;
        }
        else {
            cout << "wrong input" << endl;
        }
    } while (flag == 1);

    return 0;
}