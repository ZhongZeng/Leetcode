

/*
Leetcode 139. Word Break

Companies   
Facebook, Uber, Amazon, Microsoft, Google, Bloomberg, Apple, Zillow , Yelp, Oracle, Paypal, Yahoo
Related Topics 
Dynamic Programming 
Similar Questions 
Word Break II

Test Cases:
"de"
["d"]
"leetcode"
["leet","code"]
"aaaaaaa"
["aaaa","aa"]
"dcacbcadcad"
["cbd","dca","bcdc","dcac","ad"]

Next challenges: Word Break II

Runtime: 4 ms
Your runtime beats 81.98 % of cpp submissions.

*/

// trie; DP, DFS, Topological Sort; backtrack may be TLE 
struct node{
	char c;
	unordered_map<char,node*> um;
	bool end;
	node():end(false){}
	node(char _c):c(_c),end(false){}
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        node * root=buildTrie( wordDict);
		vector<int> vv( s.size(), 0);// s[:j] constructable 
		
		return wordBreak(s,0,root,vv);
    }

protected:
	bool wordBreak(string& s, int i, node * root, vector<int>& vv){
		node * nd=root;
        int j;
        
		for( j=i; j<s.size(); j++){
			unordered_map<char,node*>::iterator umi=nd->um.find(s[j]);
			if(umi!=nd->um.end()){// s[j] found in trie node 
				nd=umi->second;
				if(nd->end==true&&vv[j]==0){// word matched 
					vv[j]=1;
					if(wordBreak(s,j+1,root,vv))	return true;
				}
			}else{// s[j] not found in trie node 
                if(nd!=root&&nd->end==true&&wordBreak(s,j,root,vv))    return true;
                else    return false;
			}
		}
		
		return j==s.size()&&nd->end==true;
	}
	
	node * buildTrie( vector<string>& wordDict){
		node * rt=new node(), * nd;
		int i, j;
		unordered_map<char,node*>::iterator umi;
		
		for( i=0; i<wordDict.size(); i++){
            nd=rt;
			for( j=0; j<wordDict[i].size(); j++){// no empty string in wordDict 
				umi=nd->um.find(wordDict[i][j]);
				if(umi!=nd->um.end()){
					nd=umi->second;
				}else{
					node * newNd=new node(wordDict[i][j]);
					nd->um.emplace(wordDict[i][j],newNd);
					nd=newNd;
				}
			}
			nd->end=true;
		}
		
		return rt;
	}
};
