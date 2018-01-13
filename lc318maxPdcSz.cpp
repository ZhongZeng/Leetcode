
/*
Leetcode 318. Maximum Product of Word Lengths

Related Topics 
Bit Manipulation

Next challenges: Subsets, Power of Four, Maximum XOR of Two Numbers in an Array

Test Case:
["abcw","baz","foo","bar","xtfn","abcdef"]

Runtime: 46 ms
Your runtime beats 57.70 % of cpp submissions.
*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        // O(max(total words length by char, n*n))
        // max int is 2 to its 31th(>26) power minus 1
        int pd=0, b, len;
        vector<int> vc, lt;
        vector<string>::iterator it;
        string::iterator jt;
        vector<int>::iterator kt;
        for(it=words.begin(); it!=words.end(); it++){
            vector<int> lt(26, 0);
            b=0;
            for(jt=it->begin(); jt!=it->end(); jt++)    lt[*jt-'a']=1;
            // for(auto e:lt)  cout<<e<<" ";   cout<<endl;
            for(kt=lt.begin(); kt!=lt.end(); kt++){
                b=b<<1;
                *kt!=0?b++:b;
            }
            vc.push_back(b);
        }
        
        for(int i=0; i<vc.size(); i++){
            for(int j=i+1; j<vc.size(); j++){
                if((vc[i]&vc[j])==0){
                    // cout<<words[i]<<" "<<words[j]<<endl;
                    len=words[i].size()*words[j].size();
                    pd=pd<len?len:pd;
                }
            }
        }
        
        return pd;
    }
};