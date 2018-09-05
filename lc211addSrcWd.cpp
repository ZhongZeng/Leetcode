
/*
Leetcode 211. Add and Search Word - Data structure design

Companies   
Facebook, Amazon 
Related Topics 
Backtracking, Design 
Similar Questions 
Implement Trie (Prefix Tree), Prefix and Suffix Search

Test Cases:
["WordDictionary","addWord","search","search"]
[[],["a"],[".a"],["a."]]
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
["WordDictionary","search","search","search","search"]
[[],["pad"],["bad"],[".ad"],["b.."]]

Next challenges: Prefix and Suffix Search

Runtime: 92 ms
Your runtime beats 20.15 % of cpp submissions.

*/

// trie, backtrack; only a-z and .==one char
struct node{
    char c;
	bool end;
    vector<node*> vc;
    node():end(false){vector<node*> vv(26,NULL);vc=vv;}
    node(char _c):c(_c),end(false){vector<node*> vv(26,NULL);vc=vv;}
	node(char _c, bool _end):c(_c),end(_end){vector<node*> vv(26,NULL);vc=vv;}
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root=new node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
		int i;
		node * nd=root, * newNd;
        for( i=0; i<word.size(); i++){
			if(nd->vc[word[i]-'a']!=NULL)	nd=nd->vc[word[i]-'a'];
			else	break;
		}
		for( ; i<word.size(); i++){
			newNd=new node(word[i]);
			nd->vc[word[i]-'a']=newNd;// nd:last char
			nd=newNd;
		}
		nd->end=true;
		return ;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
		return search( word, 0, root);
    }
	
	bool search( string& word, int i, node * nd){
		for( int j=i; j<word.size(); j++){
			if(word[j]!='.'){
				if(nd->vc[word[j]-'a']!=NULL)	nd=nd->vc[word[j]-'a'];
				else	return false;
			}else{
				for( int k=0; k<nd->vc.size(); k++){
					if(nd->vc[k]!=NULL&&search(word,j+1,nd->vc[k]))	return true;
				}
                return false;
			}
		}
		
		return nd->end;
	}
    
    node * root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
