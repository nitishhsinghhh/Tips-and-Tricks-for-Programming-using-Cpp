class MyHashMap {
    struct ListNode {
        int key;
        int value;
        ListNode *next;
        ListNode(int key, int value) : key(key), value(value), next(nullptr) {}
    };
private:
    vector<ListNode*> data;
    int size;

    int hash(int key) {
        return key % size;
    }

public:
    MyHashMap() {
        size = 10000;
        data.resize(size);
    }
    
    void put(int key, int value) {
        int h = hash(key);
        if (!data[h]) {
            data[h] = new ListNode(key, value);
            return;
        }
        ListNode* node = data[h];
        while (node) {
            if (node->key == key) {
                node->value = value;
                return;
            }
            if (!node->next) {
                node->next = new ListNode(key, value);
                return;
            }
            node = node->next;
        }
    }
    
    int get(int key) {
        int h = hash(key);
        ListNode* node = data[h];
        while (node) {
            if (node->key == key) 
                return node->value;
            node = node->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int h = hash(key);
        ListNode* node = data[h];
        if (!node) {
            return;
        }
        if (node->key == key) {
            data[h] = node->next;
            delete node;
            return;
        }
        while (node->next) {
            if (node->next->key == key) {
                ListNode* del = node->next;
                node->next = del->next;
                delete del;
                return;
            }
            node = node->next;
        }
    }
};
