
/*
Leetcode 72. Edit Distance

Related Topics 
String, Dynamic Programming 
Similar Questions 
One Edit Distance, Delete Operation for Two Strings, 
Minimum ASCII Delete Sum for Two Strings

Next challenges: Delete Operation for Two Strings, Minimum ASCII Delete Sum for Two Strings

Test Cases:
"abc"
"abcd"
"abc"
"abecd"

Runtime: 12 ms
Your runtime beats 94.42 % of cpp submissions.

*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        // DP, O(m*n) time, O(m) space; MITOCW 6.006 Intro2Algo 21.DPIII blowed my mind!! 
        // These 3 options can be applied to each word: 
        // dis(word1[:i],word2[:j]) = min( dis([:i-1],[:j])+1, dis([:i],[:j-1])+1, dis([:i-1],[:j-1])+([i]!=[j]?1:0) ) 
        int a, d, r;
        
        // edit distance b/t word1[:i] & an empty string ""
        vector<int> vc, vd;// consider empty string
        for(int i=0; i<=word1.size(); i++)  vc.push_back(i);
        //for(auto e:vc)  cout<<e<<" ";   cout<<endl;
        
        // edit distance b/t word1[:j] & word2[:i]
        for(int i=0; i<word2.size(); i++){
            vd={i+1};
            for(int j=0; j<word1.size(); j++){
                a=vc[j+1]+1;// word1[:j-1],word2[:i] 
                d=vd.back()+1;// word1[:j],word2[:i-1] 
                r=vc[j]+(word1[j]!=word2[i]?1:0);// word1[:j-1],word2[:i-1] 
                // min of a, d, r 
                if(a<d){
                    if(a<r) vd.push_back(a);
                    else    vd.push_back(r);
                }else{
                    if(d<r) vd.push_back(d);
                    else    vd.push_back(r);
                }
            }
            vc=vd;
            //for(auto e:vc)  cout<<e<<" ";   cout<<endl;
        }
        
        return vc.back();
    }
};
