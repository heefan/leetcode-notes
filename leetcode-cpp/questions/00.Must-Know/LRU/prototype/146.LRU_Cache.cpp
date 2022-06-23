//
// Created by litian on 14/6/22.
//

#include "common_inc.h"

struct DLinkedNode {
    int key;
    int value;
    DLinkedNode * prev;
    DLinkedNode * next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode *> cache;
    DLinkedNode *head;
    DLinkedNode *tail;
    int size;
    int capacity;

public:
    LRUCache(int _capacity) : capacity(_capacity), size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->next = head;
    }

    int get(int key) {
        if (!cache.count(key)) { return -1; }

        DLinkedNode *node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            DLinkedNode *node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);

            ++size;

            if (size > capacity) {
                DLinkedNode *removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                --size;
            }
        }
    }

private:
    void moveToHead(DLinkedNode *node) {
        removeNode(node);
        addToHead(node);
    }


private:
    // A <--> B <--> C
    void removeNode(DLinkedNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    //  head->A   head<--Node-->A
    void addToHead(DLinkedNode *node) {
        node->prev = head;  // head <- Node
        node->next = head->next;   // node->A
        head->next->prev = node;   // node <- A (head->next->prev)
        head->next = node;   // head-> node
    }

    DLinkedNode *removeTail() {
        DLinkedNode *node = tail->prev;
        removeNode(node);
        return node;
    }
};
