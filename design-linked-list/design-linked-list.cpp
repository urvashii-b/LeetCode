class MyLinkedList {
private:
    struct Node{
        int val;
        Node* next;
        Node(int x): val(x), next(nullptr){};
    };
    
    int size;
    Node* head;
    
public:
    MyLinkedList(){
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if(index>=size || index<0){
            return -1;
        }
        Node* temp = head;
        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if(head==nullptr){
            head = newNode;
        }else{
            Node* temp = head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }
        if(index==0){
            addAtHead(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        Node* current = head;
        if(index==0){
            head = head->next;
            delete(current);
        }else{
            for(int i=0;i<index-1;i++){
                current = current->next;
            }
            Node* delNode = current->next;
            current->next=current->next->next;
            delete(delNode);
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */