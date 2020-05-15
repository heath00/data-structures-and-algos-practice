#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
class Trie {
    unordered_map<char,Trie*> children;
    bool isCompleteWord;

    public:
    Trie() : isCompleteWord(false) {};
    /** Inserts a word into the trie. */
    void insert(string word);
    /** Returns if the word is in the trie. */
    bool search(string word);
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix);
};

void Trie::insert(string word) {
    Trie* thisNode = this;
    for (auto c : word) {
        Trie* nextNode = thisNode->children[c] ? thisNode->children[c] : new Trie();
        thisNode->children[c] = nextNode;
        thisNode = nextNode;
    }
    thisNode->isCompleteWord = true;
}

bool Trie::search(string word) {
    Trie* searchedNode = this;
    for (auto c : word) {
        searchedNode = searchedNode->children[c];

        if (!searchedNode) return false;
    }
    return searchedNode->isCompleteWord;
}

bool Trie::startsWith(string prefix) {
    Trie* searchedNode = this;
    for (auto c : prefix) {
        searchedNode = searchedNode->children[c];
        if (!searchedNode) return false;
    }
    return true;
}

int main() {
    Trie* obj = new Trie();
    obj->insert("app");
    obj->insert("apple");
    obj->insert("beer");
    obj->insert("add");
    obj->insert("jam");
    obj->insert("rental");
    cout << obj->search("app") << endl;
    return 0;
}