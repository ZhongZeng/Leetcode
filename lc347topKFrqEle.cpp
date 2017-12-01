

/*
Leetcode 347. Top K Frequent Elements

Related Topics 
Hash Table Heap 
Similar Questions 
Word Frequency, Kth Largest Element in an Array, Sort Characters By Frequency, 
Split Array into Consecutive Subsequences, Top K Frequent Words 

Next challenges: Word Frequency

Test Cases:
[1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,6,6,6,6,6,6]
3

[1,2,2,3,3,3,4,4,4,4,5,5,5,5,5]
3

Runtime: 19 ms
Your runtime beats 53.55 % of cpp submissions.

*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // similar to lc451 Sort Characters By Frequency
        // How to be better than O(nlg(n))? I can do O(nlg(k)).
        vector<int> vc;
        vector<pair<int,int>> hp;// min; value, frq
        unordered_map<int,int> um;// value, frq
        unordered_map<int,int>::iterator umi;
        int i,c=0;
        // count frq
        for(vector<int>::iterator it=nums.begin();it!=nums.end();it++){
            umi=um.find(*it);
            if(umi!=um.end())   umi->second++;
            else    um.emplace(*it,1);
        }
        
        // heapify-min
        umi=um.begin();
        pair<int,int> pr(umi->first,umi->second);
        hp.push_back(pr);
        //cout<<umi->first<<" "<<umi->second<<endl;
        while(++umi!=um.end()&&++c!=k){
            //cout<<umi->first<<" "<<umi->second<<endl;
            pr.first=umi->first;
            pr.second=umi->second;
            hp.push_back(pr);
            i=hp.size()-1;
            while( i!=0 ){
                if(hp[i].second<hp[(i-1)/2].second){
                    pr=hp[i];
                    hp[i]=hp[(i-1)/2];
                    hp[(i-1)/2]=pr;
                    i=(i-1)/2;
                }else{
                    break;
                }
            }
        }      
        
        while(umi!=um.end()){
            //cout<<umi->first<<" "<<umi->second<<endl;
            // umi--; doesn't compile. 
            if(hp[0].second<umi->second){
                hp[0].first=umi->first;
                hp[0].second=umi->second;
                topDown(hp);
            }
            umi++;
        }
        
        // extract
        while( hp.size()!=0 ){
            vc.push_back(hp[0].first);
            hp[0]=*hp.rbegin();
            hp.pop_back();
            topDown(hp);
        }
        
        // reverse vector to return
        for(int j=0, k=vc.size()-1; j<k; j++,k--){
            c=vc[j];
            vc[j]=vc[k];
            vc[k]=c;
        }
        
        return vc;
    }

protected:    
    void topDown(vector<pair<int,int>> & hp){
        // modify the heap due to change of its top
        int i=0;
        pair<int,int> pr;
        while(2*i+2<hp.size()){
            if( hp[2*i+1].second<hp[i].second && !(hp[2*i+2].second<hp[2*i+1].second) ){
                pr=hp[i];
                hp[i]=hp[2*i+1];
                hp[2*i+1]=pr;
                i=2*i+1;
            }else if( hp[2*i+2].second<hp[i].second && !(hp[2*i+1].second<hp[2*i+2].second) ){
                pr=hp[i];
                hp[i]=hp[2*i+2];
                hp[2*i+2]=pr;
                i=2*i+2;
            }else{
                break;
            }
        }
        if(2*i+1<hp.size()&&hp[2*i+1].second<hp[i].second){
            pr=hp[i];
            hp[i]=hp[2*i+1];
            hp[2*i+1]=pr;
        }
        return ;
    }
};
