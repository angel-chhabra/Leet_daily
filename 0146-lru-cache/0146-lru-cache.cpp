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
unordered_map<int , Node*> map;  //to store the key and nodes
Node* head = new Node(-1 ,-1);  //initialised (head->tail) ye to hoga hi baki add remove sb bich m iske
Node*tail = new Node(-1 , -1);

void addNode(Node* node){ 
    node->next=head->next;  //head ke bad add kr rhe h
    node->prev=head;
    head->next->prev=node;
    head->next=node;
}
void deleteNode(Node* node){
    Node* prevnode=node->prev;  //bich m se delte kr rhe h
    Node* nextnode=node->next;
    prevnode->next=nextnode;
    nextnode->prev=prevnode;
}
void moveTohead(Node* node){   //use krli to ab aage jayegi to phle delete fr new ki trh add hojegi
    deleteNode(node);
    addNode(node);
}
Node* pop(){
    Node* res=tail->prev;   //tail ka prev (lru) ko nikal dnge and return b
    deleteNode(res);
    return res;
}

    LRUCache(int capacity) {
        limit=capacity;   //initialise kr rhe h
        head->next=tail;   // sirf head->tail h abi ll m baki age sb bich m add or remove honge
        tail->prev=head;
    }
    
    int get(int key) {
        if(map.find(key)==map.end()){   //agr present n h map m to -1
            return -1;
        }
        Node* node=map[key];   //agr h present to usko node bnaliya
        moveTohead(node);   //ab vo use hogyi to lru se mru bngyi to aage ajyegi ab
        return node->val;   // and uski val return hogi
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end()){  //agr phle se present h to new values se overwrite hongi
            Node* node=map[key];  //jha b h map m ussko point krlia
            node->val=value;      //uski purani value ki jgh new value daldi
            moveTohead(node);     // ab vo mru hogyi to aage jayegi
        } else{
            if(map.size()==limit){   //agr already limit jitni nodes present h map m 
                Node* lru=pop();     // to point kra kr piche wali ko pop kradia
                map.erase(lru->key);  //map s b erase krdia
                deleteNode(lru);      // delte b krdia kyuki ab new dalni h
                delete(lru);
            }
            Node* newNode= new Node(key , value);  //agr jgh h to new node bnakr key nd value di usse
            map[key]=newNode;    //map m b usko add krdia
            addNode(newNode);    //ll m b usko head ke bad add krdia
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */ 