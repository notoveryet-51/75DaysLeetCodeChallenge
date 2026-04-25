class WordDictionary {
public:
    struct Node {
        Node* links[26];
        bool isEnd = false;
        
        bool contains(char c) {
            return links[c - 'a'] != NULL;
        }
        
        void put(char c, Node* node) {
            links[c - 'a'] = node;
        }
        
        Node* get(char c) {
            return links[c - 'a'];
        }
    };
    
    Node* root;
    
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for (char c : word) {
            if (!node->contains(c)) {
                node->put(c, new Node());
            }
            node = node->get(c);
        }
        node->isEnd = true;
    }
    
    bool dfs(string &word, int index, Node* node) {
        if (index == word.size()) return node->isEnd;
        
        char c = word[index];
        
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->links[i] && dfs(word, index + 1, node->links[i])) {
                    return true;
                }
            }
            return false;
        } else {
            if (!node->contains(c)) return false;
            return dfs(word, index + 1, node->get(c));
        }
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */