struct Node{
    int val;
    struct Node* next=NULL;
    Node(int val){
        this->val=val;
    }
};
class LL {
    public:
    struct Node *dummy=NULL,*last=NULL;
    int size;
    unordered_map<int,struct Node*> hash_ptr;
    LL(){
        dummy=new Node(0);
        last=dummy;
        size=0;
    }

    void add(int key){
        struct Node* newNode=new Node(key);
        hash_ptr[key]=last;
        last->next=newNode;
        last=newNode;
        size++;
    }

    void remove(int key){
        struct Node* ptr = hash_ptr[key];
        if(ptr->next->next!=NULL)
        hash_ptr[ptr->next->next->val]=ptr;
        if(ptr->next == last)
        last=ptr;
        ptr->next = ptr->next->next;
        size--;
        hash_ptr.erase(key);
    }

    int remove_front(){
        int key=dummy->next->val;
        remove(dummy->next->val);
        return key;
    }
};
class LRUCache {
public:
    int capacity;
    unordered_map<int,int> hash_map;
    LL ll;
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(hash_map.find(key)!=hash_map.end()){
            ll.remove(key);
            ll.add(key);
            return hash_map[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(hash_map.find(key)!=hash_map.end()){
            //found update LL for key
            ll.remove(key);
            ll.add(key);
            //update val in hashmap
            hash_map[key]=value;
        }
        else{
            if(ll.size>=capacity){
                int key_to_rem = ll.remove_front();
                hash_map.erase(key_to_rem);
            }
            ll.add(key);
            hash_map[key]=value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
