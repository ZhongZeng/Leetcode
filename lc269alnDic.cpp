
/*
Leetcode 269. Alien Dictionary

Companies 
Google, Facebook, Twitter, Snapchat, Airbnb, Pocket Gems 
Related Topics 
Graph, Topological Sort 
Similar Questions 
Course Schedule II

Next challenges: Minimum Height Trees, Is Graph Bipartite?, Similar String Groups

Test Cases:
["wrt","wrf","er","ett","rftt"]
["z", "x"]
["z","x","z"]

Runtime: 5 ms
Your runtime beats 53.52 % of cpp submissions.

*/


class Solution {
public:
    string alienOrder(vector<string>& words) {
		// O(N) time 
		int len, i, j;
        char t;
		string rt, vs, ep; 
		unordered_map<char, unordered_set<char>> um;// first<second 
		unordered_map<char, unordered_set<char>>::iterator umi;
		unordered_set<char>::iterator usi; 
		unordered_map<char, int> ed;// all chars, # outgoing edges 
		unordered_map<char, int>::iterator edi; 
		
		// record backward edges/priorities 
        for( i=0; i<words.size()-1; i++){
			len=words[i].size()<words[i+1].size()?words[i].size():words[i+1].size();
            for( j=0; j<len; j++){
				if(words[i][j]!=words[i+1][j]){
					umi=um.find(words[i+1][j]);
					if(umi!=um.end()){
						if(umi->second.find(words[i][j])==umi->second.end())	umi->second.emplace(words[i][j]);
					}else{
						unordered_set<char> us;
						us.emplace(words[i][j]);
						um.emplace(words[i+1][j], us);
					}
					break;
				}
			}
        }
		
        for( i=0; i<words.size(); i++){// record all chars 
			for( j=0; j<words[i].size(); j++){
				if(ed.find(words[i][j])==ed.end())  ed.emplace(words[i][j], 0);
			}
        }
		
		for( umi=um.begin(); umi!=um.end(); umi++){// record foreward edges 
			for( usi=umi->second.begin(); usi!=umi->second.end(); usi++){
				ed.find(*usi)->second+=1;
			}
		}
		
		for( edi=ed.begin(); edi!=ed.end(); edi++){// find positions to start 
			if(edi->second<1)	vs.push_back(edi->first);
		}
		
		while(!vs.empty()){// topological sort 
			rt.push_back(vs.back());
			vs.pop_back();
			umi=um.find(rt.back());
            if(umi!=um.end()){
                for( usi=umi->second.begin(); usi!=umi->second.end(); usi++){
                    edi=ed.find(*usi);
                    edi->second-=1;
                    if(edi->second<1)	vs.push_back(edi->first);
                }   
            }
		}
        if(rt.size()<ed.size()) return ep;// if cycle exists
        
        for( i=0, j=rt.size()-1; i<j; i++, j--){
            t=rt[i];
            rt[i]=rt[j];
            rt[j]=t;
        }
		
		return rt;
    }
};
