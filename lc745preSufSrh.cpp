
/*
Leetcode 745. Prefix and Suffix Search

Companies   
Google
Related Topics 
Trie
Similar Questions 
Add and Search Word - Data structure design

Test Cases:
["WordFilter","f"]
[[["apple"]], ["a","le"]]
["WordFilter","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f"]
[[["pop"]],["",""],["","p"],["","op"],["","pop"],["p",""],["p","p"],["p","op"],["p","pop"],["po",""],["po","p"],["po","op"],["po","pop"],["pop",""],["pop","p"],["pop","op"],["pop","pop"],["",""],["","p"],["","gp"],["","pgp"],["p",""],["p","p"],["p","gp"],["p","pgp"],["pg",""],["pg","p"],["pg","gp"],["pg","pgp"],["pgp",""],["pgp","p"],["pgp","gp"],["pgp","pgp"]]
["WordFilter","f","f","f","f","f","f","f","f","f","f"]
[[["cabaabaaaa","ccbcababac","bacaabccba","bcbbcbacaa","abcaccbcaa","accabaccaa","cabcbbbcca","ababccabcb","caccbbcbab","bccbacbcba"]],["bccbacbcba","a"],["ab","abcaccbcaa"],["a","aa"],["cabaaba","abaaaa"],["cacc","accbbcbab"],["ccbcab","bac"],["bac","cba"],["ac","accabaccaa"],["bcbb","aa"],["ccbca","cbcababac"]]

Next challenges: Maximum XOR of Two Numbers in an Array, Word Squares, Concatenated Words

Runtime: 224 ms
Your runtime beats 93.16 % of cpp submissions.

*/

struct node{
    char c;
    bool end;
    unordered_map<char,node*> um;
    list<int> id;// unordered_set<int> TLE, b/c find max weight 
    
    node():end(false){}
    node(char _c):c(_c),end(false){}
};

class WordFilter {
public:
    WordFilter(vector<string> words) {// O(n) time&space 
        pre=new node();
        suf=new node();
        for( int i=0; i<words.size(); i++)  insert( words[i], i);
    }
    
    int f(string prefix, string suffix) {
        int i, j;
        node * np=pre, * ns=suf;
        unordered_map<char,node*>::iterator umi;
        
        for( i=0; i<prefix.size(); i++){
            umi=np->um.find(prefix[i]);
            if(umi!=np->um.end())   np=umi->second;
            else    break;
        }
        
        for( j=suffix.size()-1; -1<j; j--){
            umi=ns->um.find(suffix[j]);
            if(umi!=ns->um.end())   ns=umi->second;
            else    break;
        }
        
        if(i!=prefix.size()||j!=-1) return -1;
        //for(auto e:np->id)  cout<<e<<" ";   cout<<endl;
        //for(auto e:ns->id)  cout<<e<<" ";   cout<<endl;
        
        list<int>::reverse_iterator ip=np->id.rbegin(), is=ns->id.rbegin();
        while( ip!=np->id.rend()&&is!=ns->id.rend() ){
            if(*ip<*is){
                is++;
            }else if(*is<*ip){
                ip++;
            }else{
                return *ip;
            }
        }
        
        return -1;
    }
    
protected:
    node *pre, *suf;// root should have all ids 
    
    void insert(string& str, int& id){
        node * nd, * newNd;
        unordered_map<char,node*>::iterator umi;
        
        nd=pre;
        nd->id.push_back(id);
        for( int i=0; i<str.size(); i++){
            umi=nd->um.find(str[i]);
            if(umi!=nd->um.end()){
                nd=umi->second;
            }else{
                newNd=new node(str[i]);
                nd->um.emplace(str[i],newNd);
                nd=newNd;
            }
            nd->id.push_back(id);
        }
        nd->end=true;
        
        nd=suf;
        nd->id.push_back(id);
        for( int i=str.size()-1; -1<i; i--){
            umi=nd->um.find(str[i]);
            if(umi!=nd->um.end()){
                nd=umi->second;
            }else{
                newNd=new node(str[i]);
                nd->um.emplace(str[i],newNd);
                nd=newNd;
            }
            nd->id.push_back(id);
        }
        nd->end=true;
        
        return ;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */