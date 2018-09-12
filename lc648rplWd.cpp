

/*
Leetcode 648. Replace Words

Companies   
Uber 
Related Topics 
Hash Table, Trie 
Similar Questions 
Implement Trie (Prefix Tree)

Test Cases: 
["cat", "bat", "rat"]
"the cattle was rattled by the battery"
["cat", "bat", "rat"]
"  the  cattle was rattled by the battery  "

Next challenges: Maximum XOR of Two Numbers in an Array, Design HashMap, Maximum Frequency Stack

Runtime: 44 ms
Your runtime beats 87.93 % of cpp submissions.

*/

class node{
public:
    char c;
	bool end;
	unordered_map<char,node*> um;
	node():end(false){}
	node(char _c):c(_c),end(false){}
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        string rt;
		int i, j;
		node * root=new node(), * nd;
		unordered_map<char,node*>::iterator umi;
        
        for( int i=0; i<dict.size(); i++)   insert(dict[i],root);
		
        for( i=0; i<sentence.size()&&sentence[i]==' '; i++)	rt.push_back(sentence[j]);// trailing zeros 
		for( ; i<sentence.size(); i=j){
            for( j=i, nd=root; j<sentence.size()&&sentence[j]!=' '; j++){
				umi=nd->um.find(sentence[j]);
				if(umi!=nd->um.end())	nd=umi->second;
				else	break;// nd->end!=true
                
				rt.push_back(sentence[j]);
				
				if(nd->end==true)	break;
			}
			
			if(nd->end==true){
				for( ; j<sentence.size()&&sentence[j]!=' '; j++){}
			}else{
				for( ; j<sentence.size()&&sentence[j]!=' '; j++)	rt.push_back(sentence[j]);
			}
			for( ; j<sentence.size()&&sentence[j]==' '; j++)	rt.push_back(sentence[j]);
		}
		
		return rt;
    }
	
	void insert(string & str, node * nd){
        for( int i=0; i<str.size(); i++){
			if(nd->end==true)	break; // use root w/ the shortest length if many  
            
			unordered_map<char,node*>::iterator umi=nd->um.find(str[i]);
			if(umi!=nd->um.end()){
				nd=umi->second;
			}else{
				node * newNd=new node(str[i]);
				nd->um.emplace( str[i], newNd);
				nd=newNd;
			}
		}
        nd->end=true;
		
		return ;
	}
};
