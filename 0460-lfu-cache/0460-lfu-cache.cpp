class LFUCache {
    struct Node {
   int key, value, cnt;
   Node *next; 
   Node *prev;
   Node(int _key, int _value) {
       key = _key;
       value = _value; 
       cnt = 1; 
   }
}; 

// To implement the doubly linked list
struct List {
   int size; // Size 
   Node *head; // Dummy head
   Node *tail; // Dummy tail
   
   // Constructor
   List() {
       head = new Node(0, 0); 
       tail = new Node(0,0); 
       head->next = tail;
       tail->prev = head; 
       size = 0;
   }
   
   // Function to add node in front 
   void addFront(Node *node) {
       Node* temp = head->next;
       node->next = temp;
       node->prev = head;
       head->next = node;
       temp->prev = node;
       size++; 
   }
   
   // Function to remove node from the list
   void removeNode(Node* delnode) {
       Node* prevNode = delnode->prev;
       Node* nextNode = delnode->next;
       prevNode->next = nextNode;
       nextNode->prev = prevNode;
       size--; 
   }
};
private:
    map<int, Node*> keynode;
    map<int, List*> freqlistmap;
    int maxSize;
    int minFreq;
    int curSize;

public:
    LFUCache(int capacity) {
        maxSize = capacity;
        minFreq =0;
        curSize =0;
    }
    void updateFreqList(Node * node){
        keynode.erase(node->key);
        freqlistmap[node->cnt]->removeNode(node);

        if(node->cnt == minFreq && freqlistmap[node->cnt]->size == 0){
            minFreq++;
        } 
        List* nextHigherFreqList = new List();

        if(freqlistmap.find(node->cnt +1) != freqlistmap.end()){
            nextHigherFreqList = freqlistmap[node->cnt + 1];
        }
        node->cnt +=1;
        nextHigherFreqList->addFront(node);
        freqlistmap[node->cnt] = nextHigherFreqList;
        keynode[node->key] = node;
    }
    
    int get(int key) {
        if(keynode.find(key) != keynode.end()){
            Node* node = keynode[key];
            int val = node->value;
            updateFreqList(node);

            return val;
        }
        return -1;

    }
    
    void put(int key, int value) {
        if(maxSize == 0){
            return;
        }
        if(keynode.find(key) != keynode.end()){
            Node* node = keynode[key];
            node->value = value;
            updateFreqList(node);
        }
        else{
            if(curSize == maxSize){
                List* list = freqlistmap[minFreq];
                keynode.erase(list->tail->prev->key);
                freqlistmap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq =1;
            List* listfreq = new List();
            if(freqlistmap.find(minFreq)!= freqlistmap.end()){
                listfreq = freqlistmap[minFreq];
            }
            Node* node = new Node(key,value);
            listfreq->addFront(node);
            keynode[key] = node;
            freqlistmap[minFreq] = listfreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */