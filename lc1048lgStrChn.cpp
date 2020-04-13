/*
1048. Longest String Chain

Companies	Two Sigma, Google, Citadel, VMWare, SAP, Amazon
Related Topics	Hash Table, Dynamic Programming

Test Cases:
["a","b","ba","bca","bda","bdca"]

Runtime: 40 ms, faster than 96.52% of C++ online submissions for Longest String Chain.
Memory Usage: 9.8 MB, less than 100.00% of C++ online submissions for Longest String Chain.
Next challenges: Guess Number Higher or Lower II, Campus Bikes II, Make Array Strictly Increasing
*/

struct comp{
    bool operator()(string & s1, string & s2){
        return s1.size()<s2.size();
    }
};

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // hash table, DP, O(n*n*s) time 
        int max=0;
        vector<int> lens={1};
        
        sort( words.begin(), words.end(), comp());
        
        for( int i=1, pre=-1, cur=0; i<words.size(); i++){// [pre,cur).size()==[cur,i).size()-1
            lens.push_back(1);
            if(words[i].size()==words[i-1].size()+1){
                pre=cur;
                cur=i;
            }
            for( int j=cur-1; -1<j&&pre<=j; j--){
                if(isChain(words[j],words[i]))
                    lens[i]=lens[j]+1<lens[i]?lens[i]:lens[j]+1;// j==lens.size()-1
            }
            
        }
        
        for( int i=0; i<lens.size(); i++)   max=max<lens[i]?lens[i]:max;
        
        return max;
    }
    
protected:
    bool isChain( string & s1, string & s2){// s1 followed by s2; s1.size()==s2.size()-1 guranteed 
        int diff=0;
		for( int i=0, j=0; i<s1.size(); j++){
			if(s1[i]!=s2[j]){
				if(diff==0)	diff++;
				else	return false;
			}else{
				i++;
			}
		}
        return true;
    }
};

/*
Solution if you can reorder chars in words

Runtime: 1620 ms, faster than 5.04% of C++ online submissions for Longest String Chain.
Memory Usage: 209.5 MB, less than 100.00% of C++ online submissions for Longest String Chain.

Next challenges:
Guess Number Higher or Lower II, Campus Bikes II, Make Array Strictly Increasing
*/
struct comp{
    bool operator()(string & s1, string & s2){
        return s1.size()<s2.size();
    }
};

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // hash table, DP, O(n*n*s) time 
        int max=0;
        vector<int> lens={1};
        
        sort( words.begin(), words.end(), comp());
        
        for( int i=1, pre=-1, cur=0; i<words.size(); i++){// [pre,cur).size()==[cur,i).size()-1
            lens.push_back(1);
            if(words[i].size()==words[i-1].size()+1){
                pre=cur;
                cur=i;
            }
            for( int j=cur-1; -1<j&&pre<=j; j--){
                if(isChain(words[j],words[i]))
                    lens[i]=lens[j]+1<lens[i]?lens[i]:lens[j]+1;// j==lens.size()-1
            }
            
        }
        
        for( int i=0; i<lens.size(); i++)   max=max<lens[i]?lens[i]:max;
        
        return max;
    }
    
protected:
    bool isChain( string & s1, string & s2){// s1 followed by s2; s1.size()==s2.size()-1 guranteed 
        unordered_map<char,int> um1;
        for( int i=0; i<s2.size(); i++){
            unordered_map<char,int>::iterator umi=um1.find(s2[i]);
            if(umi!=um1.end())  umi->second+=1;
            else    um1.emplace(s2[i],1);
        }
        
        for( int i=0; i<s1.size(); i++){
            unordered_map<char,int>::iterator umi=um1.find(s1[i]);
            if(umi!=um1.end()){
                if(0<umi->second)   umi->second-=1;
                else    return false;
            }else{
                return false;
            }
        }
        
        return true;
    }
};