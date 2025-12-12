#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        this->data= data1;
        this->next= next1;
    }

    Node(int data1){
        this->data = data1;
        this->next = nullptr;
    }
};

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

int lengthLL(Node* head){
    int len=0;
    Node* temp = head;
    while(temp!=nullptr){
        len++;
        temp = temp->next;
        
    }
    return len; 
}

int check(Node* head, int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;
}

Node* deleteHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}



Node* deleteTail(Node* head){
    if(head == NULL) return NULL;
    if(head->next == NULL){
        free(head);
        return NULL;
    }
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;
}

Node* deleteK(Node* head , int k){
    if(head == NULL) return head;
    if(k==1){
        head = deleteHead(head);
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    int count = 0;


    while(temp !=NULL){
        count++;
        if(k == count){
            prev->next = prev->next->next;
            free(temp); break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* deleteEl(Node* head , int el){
    if(head == NULL) return head;
    if(head->data == el){
        head = deleteHead(head);
        return head;
    }
    Node* prev = NULL;
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == el){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* insertHead(Node* head, int val){
    return new Node(val, head);
}

Node* insertTail(Node* head, int val){
    if(head==NULL){
        return new Node(val);
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new Node(val);
    return head;
}

Node* insertK(Node* head, int val, int k){
    if(head == NULL){
        if(k==1) return new Node(val);
        else return NULL;
    }

    if(k==1){
        Node* temp = new Node(val, head);
        return temp;
    }
    Node* temp = head;
    int cnt= 0 ;
    while(temp != NULL){
        cnt++;
        if(cnt == k-1){
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next= newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node* insertBeforeValue(Node* head, int val, int ele){
    if(head == NULL){
        cout << "element not found" << endl;
        return NULL;
    }

    if(ele==head->data){
        Node* temp = new Node(val, head);
        return temp;
    }
    Node* temp = head;
    bool found = false;
   
    while(temp->next != NULL){
        
        if(ele == temp->next->data){
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next= newNode;
            found = true;
            break;
        }
        temp = temp->next;
    }

    if(found == false) cout << "ele not there" << endl;
    return head;
}

void printLL(Node* head){
    while(head != nullptr){
        cout<<head->data<<" ->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    vector<int> arr = {1,2,3,4,5,};
    Node* head = convertArr2LL(arr);
    head = insertBeforeValue(head,300, 6);
    printLL(head);

    return 0;
}

