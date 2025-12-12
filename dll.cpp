#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        this->data = data1;
        this->next = next1;
        this->back = back1;

    }
    public:
    Node(int data1){
        this->data = data1;
        this->next = nullptr;
        this->back = nullptr;
    }
};

Node* convertArr(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node* deleteHead(Node*  head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* prev = head;
    head = head->next;
    prev->next = nullptr;
    head->back = nullptr;
    free(prev);
    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL || head->next== NULL){
        return NULL;
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }

    Node* prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;
    free(tail);
    return head;
}

void printLL(Node* head){
    while(head != NULL){
        cout << head->data << "<->" ;
        head = head->next;
    }
    cout<<"NULL"<< endl;
}
int main(){
    vector<int> arr = { 1,2,3,4,5};
    Node* head = convertArr(arr);
    head = deleteTail(head);
    printLL(head);



    return 0;
};