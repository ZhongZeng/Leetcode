
/*
Leetcode 859. Buddy Strings

Test Cases: 
"ab"
"ba"
"aa"
"aa"
"abc"
"abc"

Next challenges: Text Justification, Palindrome Pairs, Output Contest Matches

*/

// Runtime: 12 ms	Your runtime beats 27.53 % of cpp submissions.
// Memory Usage: 9.1 MB
class Solution {
public:
    bool buddyStrings(string A, string B) {
		// O(n) time&space
		if(A.size()!=B.size())	return false;
        vector<int> vc;
		for( int i=0; i<A.size(); i++){
			if(A[i]!=B[i]){
				if(vc.size()<2)	vc.push_back(i);
				else	return false;
			}
		}
		if(vc.size()==0){// A and B are the same 
			unordered_set<char> us;
			for( int i=0; i<A.size(); i++){
				if(us.find(A[i])==us.end())	us.emplace(A[i]);
				else	return true;
			}
			return false;
		}else if(vc.size()==1){
			return false;
		}else if(vc.size()==2){// vc.size()<=2 guranteed 
			return A[vc[0]]==B[vc[1]]&&A[vc[1]]==B[vc[0]];// swap 
		}
		return true;// won't be triggered
    }
};

// Runtime: 10 ms
class Solution {
public:
    bool buddyStrings(string A, string B) {
        // O(n) time&space
        if(A.size()!=B.size())  return false;
        vector<char> vc;
        int ct=0;
        
        for( int i=0; i<A.size(); i++ ){
            if(A[i]!=B[i]){
                if(1<ct){
                    return false;
                }else{
                    vc.push_back(A[i]);
                    vc.push_back(B[i]);
                    ct++;
                }
            }
        }
        
        if(ct==0){// same string 
            unordered_set<char> us;
            unordered_set<char>::iterator usi;
            for( int i=0; i<A.size(); i++ ){
                usi=us.find(A[i]);
                if(usi!=us.end()){
                    return true;
                }else{
                    us.emplace(A[i]);
                }
            }
        }
        
        if(vc.size()!=4)    return false;
        if(vc[0]!=vc.back()||vc[1]!=vc[2])  return false;
        
        return true;
    }
};

