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

Node* deleteK(Node* head, int k){
    if(head == NULL) return NULL;
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k) break;
        else temp = temp->next;
    }

    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev == NULL && front == NULL){
        delete temp; return NULL;
    }else if(prev == NULL) return deleteHead(head);
    else if(front == NULL) return deleteTail(head);

    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;return head;
}

void deleteNode(Node* temp){
    Node * prev = temp->back;
    Node* front = temp->next;

    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp); return;
    }
    prev->next = front;
    front->back = prev;

    temp->next = temp ->back = nullptr;
    free(temp); return;
}

Node* insertBeforeHead(Node* head, int ele){
    Node* temp = new Node(ele, head, nullptr);
    head->back = temp; return temp;
}

Node* insertBeforeTail(Node* head, int ele){
    if(head->next==NULL) return insertBeforeHead(head,ele);
    Node* tail = head;
    while(tail->next != NULL) tail= tail->next;
    Node* prev = tail->back;
    Node* temp = new Node(ele, tail, prev);
    prev->next = temp;
    tail->back = temp;
    return head;
}

Node* insertBeforeK(Node* head, int ele, int k){
    if(k==1) return insertBeforeHead(head,ele);
    int cnt = 0;
    Node* temp = head;
    while(temp!= NULL ){
        cnt++;
        if(k == cnt){
            break;
        }
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(ele, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

Node* insertBeforeN(Node* head, int ele, int n){
    if(head->data == n) return insertBeforeHead(head, ele);
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == n) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* newNode = new Node(ele, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
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
    head = insertBeforeN(head, 0, 3);
    printLL(head);



    return 0;
};