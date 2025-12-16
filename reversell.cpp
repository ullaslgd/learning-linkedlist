#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

Node* reverseDLL(Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node* current = head;
    Node* newHead = NULL;

    while (current != NULL) {
        Node* nextNode = current->next;

        current->next = current->prev;
        current->prev = nextNode;

        newHead = current;
        current = nextNode;
    }

    return newHead;
}

void printDLL(Node* head)
{
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    if (n == 0) return 0;

    int x;
    cin >> x;
    Node* head = new Node(x);
    Node* tail = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        Node* newNode = new Node(x);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    head = reverseDLL(head);
    printDLL(head);

    return 0;
}
