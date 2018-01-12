

/*
Leetcode 45. Jump Game II

Related Topics 
Array, Greedy

Next challenges: Course Schedule III, My Calendar I, My Calendar II

Test Cases:
[2,3,1,1,4]
[4,1,1,3,1,1,1]
[1,2,3]
[2,1,1,1,1]

Runtime: 18 ms
Your runtime beats 14.33 % of cpp submissions.
Runtime: 17 ms
Your runtime beats 14.89 % of cpp submissions.

*/


class Solution {
public:
    int jump(vector<int>& nums) {
		// greedy, stack 
        // O(n) time, every element will be visited at most twice
        if(nums.size()<2)   return 0;
        
        int lt=nums.size()-1, r;
        vector<pair<int,int>> vc;
        vc.push_back(make_pair(nums.back()+nums.size()-1,nums.size()-1));
        // furthest reachable, index
        
        for(int i=nums.size()-2; -1<i; i--){
            r=nums[i]+i;
            if(vc.back().second<=r){
                while(1<vc.size()&&vc[vc.size()-2].second<=r)    vc.pop_back();
                vc.push_back(make_pair(r,i));
            }
            // for(auto e:vc)  cout<<e.first<<","<<e.second<<" ";  cout<<endl;
        }
        
        return vc.size()-1;
    }
};


class Solution {
public:
    int jump(vector<int>& nums) {
        // greedy, O(n*lg(n)) time 
        // nums - an array of non-negative integers
        // go to the smallest point able to reach the lastest furthest point 
		// Runtime: 27 ms
		// Your runtime beats 3.14 % of cpp submissions.
        if(nums.size()<2)   return 0;
        
        int st=0, nx=nums.size()-1, sm;
        vector<pair<int,int>> vc;
        for(int i=0; i<nums.size(); i++){
            vc.push_back(make_pair(i+nums[i],i)); // furthest reachable, current index
        }
        
        mergeSort(vc, 0, vc.size());
        // for(auto e:vc)    cout<<e.first<<","<<e.second<<" ";   cout<<endl;
            
        for(int i=0, sm=nums.size(); i<vc.size(); i++){
            if(vc[i].first<nx){
                //cout<<nx<<" ";
                nx=sm;
                sm=nums.size();
                st++;
            }
            
            if(vc[i].second<sm) sm=vc[i].second;
        }
        
        return nx!=0?st+1:st;
    }

protected:    
    void mergeSort(vector<pair<int,int>> & vc, int b, int e){
        if(e<b+2)   return ;
        int mid=b+(e-b)/2;
        mergeSort(vc, b, mid);
        mergeSort(vc, mid, e);
        merge(vc, b, mid, e);
        return ;
    }
    
    void merge(vector<pair<int,int>> & vc, int b, int mid, int e){
        //cout<<b<<" "<<mid<<" "<<e<<endl;
        vector<pair<int,int>> vc1;
        for(int i=b; i<mid; i++)    vc1.push_back(vc[i]);
        for(int i=b, j=0, k=mid; j<vc1.size(); i++){
            if(k==e||largerThan(vc1[j],vc[k])){// k==e must be put first!
                vc[i]=vc1[j];
                j++;
            }else{
                vc[i]=vc[k];
                k++;
            }
        }
        return ;
    }
    
    bool largerThan(pair<int,int> & pr1, pair<int,int> & pr2){
        if(pr2.first<pr1.first){
            return true;
        }else if(pr1.first<pr2.first){
            return false;
        }else{
            return pr2.second<pr1.second;
        }
    }
};
