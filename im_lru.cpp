#include <immer/map.hpp>
#include "order_tree.hpp"
#include "im_lru.hpp"

ImmutableLRUCache::ImmutableLRUCache(int capacity) {
    this->capacity = capacity;
    this->used = 0;
    int h = 0, c = capacity;
    while (c > 0) {
        c /= 2;
        h++;
    }
    this->order_tree = new OrderTree(h + 1);
    this->map = immer::map<int, Node*>{};
}

int ImmutableLRUCache::get(int key) {
    Node *node = map[key];
    if (node == nullptr) {
        return -1;
    }
    this->order_tree->to_head(node);
    return node->value;
}

ImmutableLRUCache* ImmutableLRUCache::put(int key, int value) {
    return nullptr;
}