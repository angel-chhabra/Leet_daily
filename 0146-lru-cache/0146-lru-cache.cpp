class LRUCache {
public:

class Node{
    public:
    int key ,  val;
    Node*next;
    Node*prev;
Node(int k , int v){
    this->key=k;
    this->val=v;
    prev=next=NULL;
}
};
int limit;
unordered_map<int , Node*> map;
Node* head = new Node(-1 ,-1);
Node*tail = new Node(-1 , -1);

void addNode(Node* node){
    node->next=head->next;
    node->prev=head;
    head->next->prev=node;
    head->next=node;
}
void deleteNode(Node* node){
    Node* prevnode=node->prev;
    Node* nextnode=node->next;
    prevnode->next=nextnode;
    nextnode->prev=prevnode;
}
void moveTohead(Node* node){
    deleteNode(node);
    addNode(node);
}
Node* pop(){
    Node* res=tail->prev;
    deleteNode(res);
    return res;
}

    LRUCache(int capacity) {
        limit=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(map.find(key)==map.end()){
            return -1;
        }
        Node* node=map[key];
        moveTohead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end()){
            Node* node=map[key];
            node->val=value;
            moveTohead(node);
        } else{
            if(map.size()==limit){
                Node* lru=pop();
                map.erase(lru->key);
                deleteNode(lru);
                delete(lru);
            }
            Node* newNode= new Node(key , value);
            map[key]=newNode;
            addNode(newNode);
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */ 