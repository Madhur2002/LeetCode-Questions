class DListNode{
public:
    int key;
    int value;
    int freq;
    DListNode *prev, *next;
    
    DListNode(int k, int v){
        key = k;
        value = v;
        freq = 1;
        prev = next = nullptr;
    }
};

class DList{
public:
    DListNode* sentinel;
    /*
    sentinel->next points to the head of list,
    sentinel->prev points to the tail of list
    */
    int size;
    
    DList(){
        size = 0;
        //sentinel is a dummy node
        sentinel = new DListNode(-1, -1);
        sentinel->prev = sentinel->next = sentinel;
    }
    
    void prepend(DListNode* node){
        //append to head
        //update node itself
        node->next = sentinel->next;
        node->prev = sentinel;
        //update node->next's prev
        sentinel->next->prev = node;
        //update node->prev's next
        //node becomes head of list
        sentinel->next = node;
        ++size;
    }
    
    DListNode* pop(DListNode* node = nullptr){
        if(size == 0) return nullptr;
        //the last in the list
        if(node == nullptr) node = sentinel->prev;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        --size;
        return node;
    }
};

class LFUCache {
public:
    //(key, node)
    unordered_map<int, DListNode*> nodes;
    //(freq, DList)
    unordered_map<int, DList*> freqs;
    int capacity;
    int min_freq;
    
    LFUCache(int capacity) {
        this->capacity = capacity;
        min_freq = 0;
    }
    
    void _update(DListNode* node){
        //update the node's freq, freq list and min_freq
        if(freqs.find(node->freq) == freqs.end()){
            freqs[node->freq] = new DList();
        }
        if(freqs.find(node->freq+1) == freqs.end()){
            freqs[node->freq+1] = new DList();
        }
        // cout << "pop from freqs[" << node->freq << "]" << endl;
        freqs[node->freq]->pop(node);
        if(min_freq == node->freq && freqs[node->freq]->size == 0){
            ++min_freq;
        }
        
        ++node->freq;
        // cout << "prepend to freqs[" << node->freq << "]" << endl;
        freqs[node->freq]->prepend(node);
    }
    
    int get(int key) {
        // cout << "get " << key << endl;
        if(nodes.find(key) == nodes.end()){
            return -1;
        }
        
        DListNode* node = nodes[key];
        
        //update the node's freq, freq list and min_freq
        _update(node);
        
        return node->value;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        // cout << "put (" << key << ", " << value << ")" << endl;
        if(nodes.find(key) != nodes.end()){
            DListNode* node = nodes[key];
            //update the node's freq, freq list and min_freq
            _update(node);
            //the node's value is also needed to be updated!
            node->value = value;
        }else{
            if(nodes.size() == capacity){
                if(freqs.find(min_freq) == freqs.end()){
                    freqs[min_freq] = new DList();
                }
                
                // cout << "freqs[" << min_freq << "]: ";
                // DListNode* cur = freqs[min_freq]->sentinel->next;
                // while(cur != freqs[min_freq]->sentinel){
                //     cout << "(" << cur->key << ", " << cur->value << ") ";
                //     cur = cur->next;
                // }
                // cout << endl;
                
                //delete the node from freq list and the map
                DListNode* node = freqs[min_freq]->pop();
                if(node){
                    // cout << "evict (" << node->key << ", " << node->value << ")" << endl;
                    nodes.erase(node->key);
                }
            }
            
            DListNode* node = new DListNode(key, value);
            nodes[key] = node;
            if(freqs.find(1) == freqs.end()) freqs[1] = new DList();
            freqs[1]->prepend(node);
            min_freq = 1;
        }
    }
};