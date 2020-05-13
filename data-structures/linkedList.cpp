#include <iostream>

struct Node {
    Node* next;
    int val;
    Node() : next(NULL), val(0) {};
    Node(int v, Node* n) : val(v), next(n) {};
    Node(int v) : val(v),next(NULL) {};

    int getVal() { return val; }
};

struct LinkedList {
    Node* head;
    LinkedList() : head(NULL) {};
    LinkedList(Node* n) : head(n) {};


    // adds node to the end of the list
    void append(Node* n) {
        // list is empty
        if (!head) {
            head = n;
            return; 
        }
        Node* thisNode = head;

        while (true) {
            if (thisNode->next == NULL) {
                thisNode->next = n;
                break; 
            }
            thisNode = thisNode->next;
        }
    }

    // adds node after a given node
    void addAfter(Node* newNode, Node* afterNode) {
        newNode->next = afterNode->next;
        afterNode->next = newNode;
    }

    // pushes node to the front of the list
    void push(Node* n) {
        n->next = head;
        head = n;
    }

    // looks up a node at a given index
    Node* lookupByIndex(int i) {
        Node* currNode = head;
        for (int j = 0; j < i; j++) {
            currNode = currNode->next;
        }
        return currNode;
    }

    // deletes a node with a specific key
    void removeByKey(int key) {
        Node* prevNode = head;
        Node* currNode = head;

        if (currNode->getVal() == key) {
            head = currNode->next;
            return;
        }
        while (currNode != NULL && currNode->getVal() != key) {
            prevNode = currNode;
            currNode = currNode->next;
        }

        if (currNode == NULL) return; // didn't find the node
        
        prevNode->next = currNode->next;
    }


    void print() {
        Node* thisNode = head;
        std::cout << "[";
        while(thisNode) {
            std::cout << thisNode->val;
            if (thisNode->next) {
                std::cout << ",";
            }
            thisNode = thisNode->next;
        }
        std::cout << "]" << std::endl;
    }
};

LinkedList createList(int len) {
    LinkedList newLL;
    for (int i = 0; i < len; i++) {
        Node* newNode = new Node(i);
        newLL.append(newNode);
    }

    return newLL;
}

int main() {
    std::cout << "Creating list of 5" << std::endl;
    LinkedList newLL = createList(5);
    newLL.print();
    std::cout << "Adding -1 to the front" << std::endl;
    newLL.push(new Node(-1));
    newLL.print();
    std::cout << "Looking up value at index 3" << std::endl;
    std::cout << newLL.lookupByIndex(3)->getVal() << std::endl;
    std::cout << "Removing 1" << std::endl;
    newLL.removeByKey(1);
    newLL.print();

}