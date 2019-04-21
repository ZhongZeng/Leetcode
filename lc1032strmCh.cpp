/*
1032. Stream of Characters

Companies	Google
Related Topics	Trie

Test Case:
["StreamChecker","query","query","query","query","query","query","query","query","query","query","query","query"]
[[["cd","f","kl"]],["a"],["b"],["c"],["d"],["e"],["f"],["g"],["h"],["i"],["j"],["k"],["l"]]

Runtime: 344 ms
Memory Usage: 88.8 MB
*/

struct node{
    char c;
    bool b;// a word or no 
    unordered_map<char,node*> um;
    node():b(false){}
    node(char c0):b(false),c(c0){}
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {// constructor
        rt=new node(' ');
        for( int i=0; i<words.size(); i++){// build trie
            node * nd=rt;
            for( int j=words[i].size()-1; -1<j; j--){
                if(nd->b==true)  break;// match as short ap to save time&space
                unordered_map<char,node*>::iterator umi=nd->um.find(words[i][j]);
                if(umi!=nd->um.end()){
                    nd=umi->second;
                }else{
                    node * nt=new node(words[i][j]);
                    nd->um.emplace(words[i][j], nt);
                    nd=nt;
                }
            }
            nd->b=true;
        }
    }
    
    bool query(char letter) {
        s.push_back(letter);
        node * nd=rt;
        for( int i=s.size()-1; -1<i; i--){
            unordered_map<char,node*>::iterator umi=nd->um.find(s[i]);
            if(umi!=nd->um.end())   nd=umi->second;
            else    return false;
            if(nd->b==true)  return true;
        }
        return false;
    }
    
protected:
    node * rt;
    string s;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */