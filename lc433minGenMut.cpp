
/*
Leetcode 433. Minimum Genetic Mutation

Similar Questions 
Word Ladder

Next challenges: Circular Array Loop, Poor Pigs, Coin Change 2

Test Cases:
"AACCGGTT"
"AACCGGTA"
["AACCGGTA"]
"AAAAACCC"
"AACCCCCC"
["AAAACCCC", "AAACCCCC", "AACCCCCC"]
"AAAAAAAA"
"CCCCCCCC"
["AAAAAAAA","AAAAAAAC","AAAAAACC","AAAAACCC","AAAACCCC","AACACCCC","ACCACCCC","ACCCCCCC","CCCCCCCA"]

Runtime: 0 ms
Your runtime beats 42.11 % of cpp submissions.

*/

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        // ACGT
        // 2-end &find next-to-visit solution inspired by solution of Leetcode 127. Word Ladder
        // Starting point is assumed to be valid, so it might not be included in the bank.
        // TRICKY: end may not be in bank
        int i=0;
        vector<char> vc={'A','C','G','T'};
        unordered_set<string> ub, ub2, ue, ue2;
        for(vector<string>::iterator it=bank.begin(); it!=bank.end(); it++){
            ub.emplace(*it);
            ue.emplace(*it);
        }
        if(ue.find(end)==ue2.end())    return -1;
        ub2.emplace(start);
        ue2.emplace(end);
        
        while(!(ub2.empty()||ue2.empty())){
            i++;
            ub2=nextVisit(ub, ub2, vc);
            if(meet(ub2,ue2))   return i;
            
            i++;
            ue2=nextVisit(ue, ue2, vc);
            if(meet(ub2,ue2))   return i;
        }
        
        return -1;
    }
    
protected:
    unordered_set<string> nextVisit(unordered_set<string> & ub, unordered_set<string> & ub2, vector<char> & vc){
        unordered_set<string> us;
        unordered_set<string>::iterator ubi;
        string t;
        
        for(unordered_set<string>::iterator it=ub2.begin(); it!=ub2.end(); it++){
            //cout<<*it<<": ";
            for(int i=0; i<it->size(); i++){
                for(int j=0; j<vc.size(); j++){
                    t=*it;
                    if(t[i]!=vc[j]){
                        t[i]=vc[j];
                        ubi=ub.find(t);
                        if(ubi!=ub.end()){
                            us.emplace(t);
                            ub.erase(ubi);
                            //cout<<t<<" ";
                        }
                    }
                }
            }
            //cout<<endl;
        }
        return us;
    }
    
    bool meet(unordered_set<string> & ub2, unordered_set<string> & ue2){
        for(unordered_set<string>::iterator it=ub2.begin(); it!=ub2.end(); it++){
            if(ue2.find(*it)!=ue2.end()){
                //cout<<*it<<" ";
                return true;
            }
        }
        return false;
    }
};
