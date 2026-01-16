class LRUCache {
public:
    class Node{
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int key, int val){
            this->key = key;
            this->val = val;
        }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int,Node*> hash;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAfter(Node* node){
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
        
    }
    
    int get(int key) {
        if (hash.count(key)){
            Node* node = hash[key];
            deleteNode(node);
            insertAfter(node);
            return node->val;

        }
        else return -1;
    }
    
    void put(int key, int value) {
        if (hash.count(key)){
            Node* node = hash[key];
            node->val = value;
            deleteNode(node);
            insertAfter(node);
        }
        else{
            if (hash.size() == cap){
                Node* node = tail->prev;
                hash.erase(node->key);
                deleteNode(node);
            }
            Node* newnode = new Node(key, value);
            hash[key] = newnode;
            insertAfter(newnode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */