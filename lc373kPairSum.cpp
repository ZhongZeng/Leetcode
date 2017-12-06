
/*
Leetcode 373. Find K Pairs with Smallest Sums

Related Topics 
Heap 
Similar Questions 
Kth Smallest Element in a Sorted Matrix, Find K-th Smallest Pair Distance 



Runtime: 13 ms
Your runtime beats 53.75 % of cpp submissions.

*/

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // Tag: 2-pointer, heap
        // O(klg(k)) time; O(k) space.
        // nums1,nums2 might have different length; k might exceeds limit. 
        // We can prove following:
        // a. if (i,j) is the next smallest, (i-1,j) and (i,j-1) must have been pushed into heap,
        // since both are smaller (i,j)
        // a. means we will be able to find the next smallest 
        // b. recursively all pairs with first<i and second<j have been visited. 
        // Solving this problem also gives me ideas to solve .
                
        vector<pair<int,int>> vc;
        if(nums1.size()<1||nums2.size()<1)  return vc;
        
        unordered_map<int,unordered_set<int>> vst;// visited or not 
        
        vector<pair<int,pair<int,int>>> hp;// min
        pair<int,pair<int,int>> pp;
        pp.first=nums1[0]+nums2[0];
        pp.second.first=0;
        pp.second.second=0;
        hp.push_back(pp);
        
        for(int i=0,r,c,lmt=nums1.size()*nums2.size(); i!=k&&i!=lmt; i++){
            //cout<<i<<"-"<<hp[0].first<<" ";
            r=hp[0].second.first;
            c=hp[0].second.second;
            vc.push_back(make_pair(nums1[r],nums2[c]));
            
            hp[0]=*hp.rbegin();
            hp.pop_back();
            topDown(hp);
            
            pushPp(r+1,c,hp,nums1,nums2,vst);
            pushPp(r,c+1,hp,nums1,nums2,vst);
        }
        
        return vc;
    }

protected:
    bool unVisited(int r, int c, unordered_map<int,unordered_set<int>> & vst){
        unordered_map<int,unordered_set<int>>::iterator umi=vst.find(r);
        unordered_set<int> us;
        if(umi!=vst.end()){
            if(umi->second.find(c)!=umi->second.end()){
                return false;
            }else{
                umi->second.emplace(c);
                return true;
            }
        }else{
            us.emplace(c);
            vst.emplace(r,us);
            return true;
        }
    }
    
    void pushPp(int r, int c, vector<pair<int,pair<int,int>>> & hp, vector<int> & nums1, vector<int> & nums2, 
                unordered_map<int,unordered_set<int>> & vst){
        if(r<nums1.size()&&c<nums2.size()&&unVisited(r,c,vst)){
            hp.push_back(make_pair(nums1[r]+nums2[c],make_pair(r,c)));
            int i=hp.size()-1;
            pair<int,pair<int,int>> pp;
            while(0<i){
                if(lessThan(hp[i],hp[(i-1)/2])){
                    pp=hp[i];
                    hp[i]=hp[(i-1)/2];
                    hp[(i-1)/2]=pp;
                    i=(i-1)/2;
                }else{
                    return;
                }
            }            
        }
        return;
    }
    
    void topDown(vector<pair<int,pair<int,int>>> & hp){
        int i=0;
        pair<int,pair<int,int>> pp;
        while(2*i+2<hp.size()){
            if(lessThan(hp[2*i+2],hp[i])&&!(lessThan(hp[2*i+1],hp[2*i+2]))){
                pp=hp[2*i+2];
                hp[2*i+2]=hp[i];
                hp[i]=pp;
                i=2*i+2;
            }else if(lessThan(hp[2*i+1],hp[i])&&!(lessThan(hp[2*i+2],hp[2*i+1]))){
                pp=hp[2*i+1];
                hp[2*i+1]=hp[i];
                hp[i]=pp;
                i=2*i+1;                
            }else{
                return;
            }
        }
        if(2*i+1<hp.size()&&lessThan(hp[2*i+1],hp[i])){
            pp=hp[2*i+1];
            hp[2*i+1]=hp[i];
            hp[i]=pp;            
        }
        return;
    }
    
    bool lessThan(pair<int,pair<int,int>> & pp1, pair<int,pair<int,int>> & pp2){
        if(pp1.first<pp2.first){
            return true;
        }else{
            return false;
        }
    }
    
};
