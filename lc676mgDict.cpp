

/*
Leetcode 676. Implement Magic Dictionary

Companies   
Google 
Related Topics 
Hash Table, Trie 
Similar Questions 
Implement Trie (Prefix Tree), Longest Word in Dictionary

Test Cases: 
["MagicDictionary", "buildDict", "search", "search", "search", "search", "search"]
[[], [["hello","leetcode"]], ["hello"], ["helle"], ["hhllo"], ["hell"], ["leetcoded"]]
["MagicDictionary", "buildDict", "search", "search", "search", "search"]
[[], [["hello","hallo","leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]

Next challenges: Longest Word in Dictionary

Runtime: 0 ms
Your runtime beats 100.00 % of cpp submissions.

*/

// trie, backtracking 
// corner case: [[], [["hello","hallo","leetcode"]], ["hhllo"] ] 
// the code can be easily modified for add/delete char(s) 
struct node{
	char c;
	bool end;
	unordered_map<char,node*> um;
	node():end(false){}
	node(char _c):c(_c),end(false){}
	node(char _c, bool _end):c(_c),end(_end){}
};

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
		
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        root=new node();
		for( int i=0; i<dict.size(); i++)	insertStr( dict[i]);
		return ;
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
		return search( word, 0, root, 0);
    }
	
	bool search(string& word, int i, node * nd, int skip){// recursion 
        if(1<skip)  return false;
        if(i==word.size())  return nd->end&&skip==1;
        
        for( unordered_map<char,node*>::iterator umi=nd->um.begin(); umi!=nd->um.end(); umi++){
            if(search( word, i+1, umi->second, skip+(umi->first!=word[i]?1:0) ))    return true;
        }
		
		return false;
	}

protected:	
	node * root;
	void insertStr( string& s ){
		node * nd=root, * newNd;
		unordered_map<char,node*>::iterator umi;
		int i=0;
		
		for( ; i<s.size(); i++){
			umi=nd->um.find(s[i]);
			if(umi!=nd->um.end())	nd=umi->second;
			else	break;
		}
		
		for( ; i<s.size(); i++){
			newNd=new node(s[i]);
			nd->um.emplace(s[i],newNd);
			nd=newNd;
		}
		nd->end=true;
		
		return ;
	}
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
