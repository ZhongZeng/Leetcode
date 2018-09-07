
/*
Leetcode 720. Longest Word in Dictionary

Companies   
Google 
Related Topics 
Hash Table, Trie 
Similar Questions 
Longest Word in Dictionary through Deleting, Implement Magic Dictionary

Test Cases:
["w","wo","wor","worl","world"]
["w","wo","wor","world"]
["w","wo","wor","woa","world"]
["a","banana","app","appl","ap","apply","apple"]

Runtime: 32 ms
Your runtime beats 89.61 % of cpp submissions.

*/

class Solution {
public:
    string longestWord(vector<string>& words) {
        // trie; hash table, topological sort 
        if(words.size()<1)  return "";
		int mx=0, i; 
		string rt="";
		unordered_map<int,list<string>> um;
		unordered_map<int,list<string>>::iterator umi;
		unordered_set<string> us, ut;
		unordered_set<string>::iterator usi;
		list<string>::iterator it;
		
		for( i=0; i<words.size(); i++){// O(n) 
			umi=um.find(words[i].size());
			if(umi!=um.end()){
				umi->second.push_back(words[i]);
			}else{
				list<string> ls;
				ls.push_back(words[i]);
				um.emplace( words[i].size(), ls );
			}
		}
		
        us.emplace("");
		for( i=1; true; i++){// build string 1-by-1 char; O(n) 
			ut.clear();
			umi=um.find(i);
			if(umi!=um.end()){
				for( it=umi->second.begin(); it!=umi->second.end(); it++){
					string s=*it;
					s.pop_back();
					
					if(us.find(s)!=us.end())    ut.emplace(*it);
				}
			}
            if(ut.size()<1) break;
            us=ut;
		}
		
        // traversal buildable string 
        rt=*us.begin();
		for( usi=us.begin(); usi!=us.end(); usi++){
			if(*usi<rt)	rt=*usi;
		}
		
		return rt;
    }
};
