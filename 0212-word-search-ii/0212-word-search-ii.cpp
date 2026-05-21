class Solution {
public:
    struct TrieNode{
        TrieNode* child[26];
        string word;
        TrieNode(){
            for(int i=0;i<26;i++){
                child[i]=nullptr;
            }
            word="";
        }
    };
    TrieNode* root=new TrieNode();
    void insert(string word){
        TrieNode* node=root;
        for(char ch:word){
            int idx=ch-'a';
            if(node->child[idx]==nullptr){
                node->child[idx]=new TrieNode();
            }
            node=node->child[idx];
        }
        node->word=word;
    }
    vector<string> ans;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    void dfs(vector<vector<char>>& board,int r,int c,TrieNode* node){

        if(r<0||c<0||r>=board.size()||c>=board[0].size())
            return;
        char ch=board[r][c];
        if(ch=='#')
            return;

        node=node->child[ch-'a'];
        if(node==nullptr)
            return;
        if(node->word!=""){
            ans.push_back(node->word);
            node->word="";
        }
        board[r][c]='#';
        for(int k=0;k<4;k++){
            dfs(board,r+dx[k],c+dy[k],node);
        }
        board[r][c]=ch;
    }
    vector<string> findWords(vector<vector<char>>& board,vector<string>& words){
        for(string& w:words){
            insert(w);
        }
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(board,i,j,root);
            }
        }
        return ans;
    }
};