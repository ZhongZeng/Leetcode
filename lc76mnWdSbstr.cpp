

/*

Leetcode 76. Minimum Window Substring

Companies  
Facebook, Amazon, Airbnb, LinkedIn, Google, Microsoft, Uber, Snapchat 
Related Topics 
Hash Table, Two Pointer, String 
Similar Questions 
Substring with Concatenation of All Words, Minimum Size Subarray Sum, Sliding Window Maximum, 
Permutation in StringSmallest Range, Minimum Window Subsequence

Test Case: 
"ADOBECODEBANC"
"ABC"

Next challenges: Substring with Concatenation of All Words, Smallest Range

Runtime: 12 ms
Your runtime beats 53.49 % of cpp submissions.

*/

class Solution {
public:
    string minWindow(string s, string t) {
		// hash table, 2-pointer, DP; O(n) time 
		int b=0, e=0, bt=0, et=-1, mn=s.size(), sz;// bt, et initialized for "" 
		string rt;
		unordered_map<char,int> um;
		unordered_map<char,int>::iterator umi;
		
		for( int i=0; i<t.size(); i++){// record t in hash table 
			umi=um.find(t[i]);
			if(umi!=um.end())	umi->second+=1;
			else	um.emplace(t[i],1);
		}
		sz=um.size();
		
		for( b=0, e=0; e<s.size(); e++ ){// move pointer e; invalid s[b,e] 
			umi=um.find(s[e]);
			if(umi!=um.end()){
				umi->second-=1;
				if(umi->second==0)	sz--;
				
				if(sz==0){// valid s[b,e] 
					for(  ; b<=e; b++){// move pointer b 
						umi=um.find(s[b]);
						if(umi!=um.end()){
							if(umi->second<0)	umi->second+=1;
							else	break;// umi->second==0 
						}
					}	
				
					bt=b;
					et=e;
					mn=e-b+1;
					
					break;
				}
			}
		}
		
		for( e++; e<s.size(); e++ ){// move pointer e; valid s[b,e], could be integrated with invalid s[b,e] 
			umi=um.find(s[e]);
			if(umi!=um.end()){
				umi->second-=1;
				
				for(  ; b<=e; b++){// move pointer b 
					umi=um.find(s[b]);
					if(umi!=um.end()){
						if(umi->second<0)	umi->second+=1;
						else	break;// umi->second==0 
					}
				}
				//cout<<b<<","<<e<<":"<<mn<<" "; 
				
				if(e-b+1<mn){
					bt=b;
					et=e;
					mn=e-b+1;
				}
			}			
		}
		
		for( int i=bt; i<=et; i++)	rt.push_back(s[i]);
		
		return rt;
    }
};


