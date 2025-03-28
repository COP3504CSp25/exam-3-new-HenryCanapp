#pragma once
struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    void addHead(const int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    int* getStats() const{
        //write your function here!
        int* result = new int[3];
        Node* current = head;
        int numNodes = 0;
        while (current != nullptr) {
            result[2] += current->data;
            numNodes++;
            if (current->data < result[0]) {
              result[0] = current->data;
            } else if (current->data > result[1]) {
              result[1] = current->data;
            }
            current = current->next;
        }
        result[2] /= numNodes;
        return result;
    }
    

private:
    Node* head = nullptr;
};
