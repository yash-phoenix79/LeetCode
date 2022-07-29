class LRUCache {
public:
    
    class Node{
        public:
            int key;
            int val;
            Node* next;
            Node* prev;
            Node(int key,int val){
                this->key=key;
                this->val=val;
            
        }
    };
    
    
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    
    unordered_map<int,Node*>m;
    int sizer;
    
    void removeNode(Node* curNode){
        Node* nextNode=curNode->next;
        Node* prevNode=curNode->prev;
        nextNode->prev=prevNode;
        prevNode->next=nextNode;
    }
    
    void addNode(Node* curNode){
        curNode->next=head->next;
         curNode->prev=head;
        curNode->next->prev=curNode;
       
        head->next=curNode;
    }
    
    LRUCache(int capacity) {
        
        this->sizer=capacity;
        head->next=tail;
        tail->prev=head;
        
    }
    
    int get(int key) {
        if(m.find(key)==m.end())return -1;
        
        Node* curNode=m[key];
        int res=curNode->val;
        m.erase(key);
        removeNode(curNode);
        addNode(curNode);
        m[key]=head->next;
        return res;
    }
    
    void put(int key, int value) {
        
        if(m.find(key)!=m.end()){
            Node* curNode=m[key];
            m.erase(key);
            removeNode(curNode);
        }
        
        if(m.size()==sizer){
            m.erase(tail->prev->key);
            removeNode(tail->prev);
        }
        
        addNode(new Node(key,value));
        m[key]=head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */