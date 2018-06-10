

/*
Leetcode 848. Shifting Letters
Weekly Contest 88

Test Cases:
"abc"
[3,5,9]
"z"
[52]
"zz"
[52,52]

Runtime: 54 ms

*/

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        // O(n) time, O(1) space
        for(int i=shifts.size()-2; -1<i; i--)   shifts[i]=(shifts[i]+shifts[i+1])%26;
        if(!shifts.empty()) shifts.back()=shifts.back()%26;// corner case 
        //for(auto e:shifts)  cout<<e<<" ";   cout<<endl;
        
        for( int i=0; i<S.size(); i++){
            if('z'-S[i]<shifts[i])  S[i]=S[i]+shifts[i]-26;//'z'<S[i]+shifts[i]
            else    S[i]=S[i]+shifts[i];
        }
        
        return S;
    }
};
