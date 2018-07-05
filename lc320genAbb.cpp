
/*

Leetcode 320. Generalized Abbreviation

Companies 
Google
Related Topics 
Backtracking, Bit Manipulation
Similar Questions 
Subsets, Unique Word Abbreviation, Minimum Unique Word Abbreviation

Test Cases:
"war"
""
"dictionary"
"123"

Next challenges: Minimum Unique Word Abbreviation

Runtime: 20 ms
Your runtime beats 100.00 % of cpp submissions.

*/


class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        string s;
        vector<string> vs;
        if(word.size()<1){
            vs.push_back(s);
            return vs;
        }
        int2str( s, word.size());
        vs.push_back(s);        
        
        for( int i=0; i<word.size(); i++){
            vector<int> vc;// string of [begin,end) in word
            vc.push_back(i);
            vc.push_back(i+1);
            
            backTrack( vc, i+1, word, vs);
        }
        
        return vs;
    }
    
    void backTrack(vector<int>& vc, int j, string& word, vector<string>& vs){// DFS 
        if(j==word.size()){// push s to vs
            string s;
            if(vc[0]!=0)    int2str( s, vc[0]);// push number from begining
            for( int i=0; i<vc.size(); i+=2){
                for( int j=vc[i]; j<vc[i+1]; j++)   s.push_back(word[j]);// push string
                if(i+2<vc.size())   int2str( s, vc[i+2]-vc[i+1]);// push number 
            }
            if(vc.back()!=word.size())  int2str( s, word.size()-vc.back());// push number from end 
            vs.push_back(s);
            
            return ;
        }
        
        backTrack( vc, j+1, word, vs);
        
        if(j==vc.back()){
            vc.back()+=1;
            backTrack( vc, j+1, word, vs);
            vc.back()-=1;
        }else{
            vc.push_back(j);
            vc.push_back(j+1);
            backTrack( vc, j+1, word, vs);
            vc.pop_back();
            vc.pop_back();
        }
        
        return ;
    }
    
    void int2str( string&s, int t){
        string st;
        
        while(t!=0){
            st.push_back((char)(t%10+'0'));
            t=t/10;
        }
        
        for( int i=st.size()-1; -1<i; i--)  s.push_back(st[i]);
        
        return ;
    }
};