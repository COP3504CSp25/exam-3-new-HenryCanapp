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
        result[0] = 0;
        result[1] = 0;
        result[2] = 0;
        Node* current = head;
        int numNodes = 0;
        if (current != nullptr) {
            result[0] = current->data;
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
        }
        if (numNodes != 0) {
            result[2] /= numNodes;
        }
        return result;
    }
    

private:
    Node* head = nullptr;
};
