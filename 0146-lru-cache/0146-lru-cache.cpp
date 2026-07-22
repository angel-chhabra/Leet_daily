class LRUCache {
public:
    class Node {
    public:
        int val;
        int key;
        Node* prev;
        Node* next;

        Node(int val, int key) {
            this->val = val;
            this->key = key;
            prev = next = NULL;
        }
    };

    Node* head;
    Node* tail;
    int cap, curr_cap;

    unordered_map<int, Node*> map;

    // Insert node at front
    Node* insertFront(int key, int val) {
        Node* newNode = new Node(val, key);

        if (head == NULL) {
            head = tail = newNode;
            return newNode;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;

        return newNode;
    }

    // Delete last node and return its key
    int deleteEnd() {
        if (tail == NULL)
            return -1;

        int dkey = tail->key;

        if (head == tail) {
            delete tail;
            head = tail = NULL;
            return dkey;
        }

        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;

        return dkey;
    }

    // Move a node to the front
    Node* moveNthNodeFront(Node* curr) {
        if (curr == head)
            return curr;

        // detach
        if (curr == tail) {
            tail = tail->prev;
            tail->next = NULL;
        } else {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }

        // insert at front
        curr->prev = NULL;
        curr->next = head;
        head->prev = curr;
        head = curr;

        return curr;
    }

    LRUCache(int capacity) {
        cap = capacity;
        curr_cap = 0;
        head = tail = NULL;
    }

    int get(int key) {
        if (map.count(key) == 0)
            return -1;

        Node* curr = moveNthNodeFront(map[key]);
        return curr->val;
    }

    void put(int key, int value) {
        if (map.count(key)) {
            Node* curr = moveNthNodeFront(map[key]);
            curr->val = value;
            return;
        }

        if (curr_cap == cap) {
            int dkey = deleteEnd();
            map.erase(dkey);
            curr_cap--;
        }

        Node* curr = insertFront(key, value);
        map[key] = curr;
        curr_cap++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */