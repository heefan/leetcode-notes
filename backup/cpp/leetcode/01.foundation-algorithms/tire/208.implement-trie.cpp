//
// Created by litian on 8/7/22.
//


#include "common_inc.h"

class Trie {
    bool isEnd;
    Trie * next[26];

public:
    Trie(): isEnd(false) {
        memset(next, 0, sizeof(next));
    }

    void insert(string word) {
        Trie * node = this;
        for (auto c: word) {
            if (node->next[c - 'a'] == nullptr) {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        Trie * node = this;

        for (auto c: word) {
            node = node->next[c-'a'];

            if (node == nullptr) {
                return false;
            }
        }

        return node->isEnd;
    }

    bool startsWith(string prefix) {
        Trie * node = this;
        for(auto c: prefix) {
            node = node->next[c-'a'];
            if(node == nullptr) {
                return false;
            }
        }
        return true;
    }
};

TEST_CASE("208. Implement Trie (Prefix Tree)") {
    SECTION("case1") {
        Trie trie = Trie();
        trie.insert("apple");
        REQUIRE(true == trie.search("apple"));
        REQUIRE(false == trie.search("app"));
        REQUIRE(true == trie.startsWith("app"));
        trie.insert("app");
        REQUIRE(true == trie.search("app"));
    }
}