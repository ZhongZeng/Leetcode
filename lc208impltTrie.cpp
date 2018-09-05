
/*
Leetcode 208. Implement Trie (Prefix Tree)

Companies   
Microsoft, Google, Amazon, Facebook, Apple, Uber 
Related Topics 
Design, Trie 
Similar Questions 
Add and Search Word - Data structure design, Design Search Autocomplete System, 
Replace Words, Implement Magic Dictionary

Test Cases:
["Trie","insert","search","search","startsWith","insert","search"]
[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]
["Trie","startsWith"]
[[],["a"]]

Runtime: 48 ms
Your runtime beats 67.74 % of cpp submissions.

*/

struct node{
	char c;
	bool cpt;
	unordered_map<char,node*> um;
	node():cpt(false){}
	node(char _c ): c(_c), cpt(false){}
    node(char _c, bool _cpt): c(_c), cpt(_cpt){}// not used 
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new node();// initialization of root required 
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
		int i;
        node * nd=root, * newNd;
		unordered_map<char,node*>::iterator umi;
		
		for( i=0; i<word.size(); i++){
            umi=nd->um.find(word[i]);
			if(umi!=nd->um.end())	nd=umi->second;
			else	break;
		}
        
		for( ; i<word.size(); i++){
			//cout<<word[i]<<" ";
			newNd=new node(word[i]);
			nd->um.emplace(word[i],newNd);
			nd=newNd;
		}
		nd->cpt=true;
		
		return ;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node * nd=root;
		unordered_map<char,node*>::iterator umi;
		
		for( int i=0; i<word.size(); i++){
            //cout<<word[i]<<" ";
            umi=nd->um.find(word[i]);
			if(umi!=nd->um.end())	nd=umi->second;
			else	return false;
		}
		
		return nd->cpt;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int i=0;
        node * nd=root;
		unordered_map<char,node*>::iterator umi;        
        
		for( ; i<prefix.size(); i++){
			umi=nd->um.find(prefix[i]);
			if(umi!=nd->um.end())	nd=umi->second;
			else	return false;
		}
        
        return i==prefix.size();
    }
	
protected:
	node * root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
