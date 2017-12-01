
/*
Leetcode 451. Sort Characters By Frequency

Related Topics 
Hash Table, Heap 
Similar Questions 
Top K Frequent Elements 

Next challenges: Split Array into Consecutive Subsequences,
Employee Importance, Sentence Similarity

Test Cases:
"tree"
"2a554442f544asfasssffffasss"
"Mymommaalwayssaid,\"Lifewaslikeaboxofchocolates.Youneverknowwhatyou'regonnaget."

Runtime: 16 ms
Your runtime beats 66.29 % of cpp submissions.

I have new understanding of heap sort from this exercise.
Previously I did redunently in extrac from heap. 

*/

class Solution {
public:
    string frequencySort(string s) {
        string rs;
        unordered_map<char,int> um;
        unordered_map<char,int>::iterator umi;
        vector<pair<int,char>> vc;
        pair<int,char> pr;
        int i;
        char c;
        for(string::iterator it=s.begin(); it!=s.end(); it++){
            umi=um.find(*it);
            if(umi!=um.end())   umi->second++;
            else    um.emplace(*it,1);
        }
        
        // heapify
        for(umi=um.begin();umi!=um.end();umi++){
            pr.first=umi->second;
            pr.second=umi->first;
            vc.push_back(pr);
            i=vc.size()-1;
            while(i!=0){
                if(vc[(i-1)/2].first<vc[i].first){
                    pr=vc[(i-1)/2];
                    vc[(i-1)/2]=vc[i];
                    vc[i]=pr;
                    i=(i-1)/2;
                }else{
                    break;
                }
            }
        }
        
        // travse heap
        while(vc.size()!=0){
            i=vc[0].first;
            c=vc[0].second;
            for(int j=0;j!=i;j++)   rs.push_back(c);
            
            // extract 
            vc[0]=*vc.rbegin();
            vc.pop_back();
            i=0;
            while( 2*i+2<vc.size() ){
                if(vc[i].first<vc[2*i+1].first && !(vc[2*i+1].first<vc[2*i+2].first) ){
                    pr=vc[i];
                    vc[i]=vc[2*i+1];
                    vc[2*i+1]=pr;
                    i=2*i+1;
                }else if(vc[i].first<vc[2*i+2].first && !(vc[2*i+2].first<vc[2*i+1].first) ){
                    pr=vc[i];
                    vc[i]=vc[2*i+2];
                    vc[2*i+2]=pr;
                    i=2*i+2;
                }else{
                    break;
                }
            }
            if(2*i+1<vc.size()&&vc[i].first<vc[2*i+1].first){
                pr=vc[i];
                vc[i]=vc[2*i+1];
                vc[2*i+1]=pr;
            }
        }
        
        
        return rs;
    }
};
