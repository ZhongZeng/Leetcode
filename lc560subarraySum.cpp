
/*
Leetcode 560. Subarray Sum Equals K

Tags: Array, Map
Similar Problems: (E) Two Sum (M) Continuous Subarray Sum
Next challenges: (M) Continuous Subarray Sum

You are here! 
Your runtime beats 83.51 % of cpp submissions.
Runtime: 35 ms

Test Cases:
[-1,-1,1]
0
[-1,-1,1,-2,1,-3,4,-1]
-1

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // prefix solution
        int adj=0,cnt=0;
        unordered_map<int,int> m;
        unordered_map<int,int>::iterator mt,ct;
        for(vector<int>::iterator it=nums.begin();it!=nums.end();it++){
            adj+=*it;
            mt=m.find(*it-adj);
            if(mt!=m.end()){
                mt->second+=1;
            }else{
                m.emplace(*it-adj,1);
            }
            ct=m.find(k-adj);
            if(ct!=m.end()){
                cnt+=ct->second;
            }
        }
        return cnt;
    }
};

/*
//WRONG Solution, due to negative numbers
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // individual elements count as array of size 1
        // Two Points Approach
        vector<int>::iterator ib=nums.begin(),ie=nums.begin();
        int sum=*nums.begin(), count=0;
        while(ie!=nums.end()){
            // cout<<*ib<<" "<<*ie<<" "<<sum<<endl;
            if(ib==ie){
                if(*ie==k){
                    // cout<<*ib<<" "<<*ie<<" count++"<<endl;
                    count++;
                }
                ie++;
                sum+=*ie;
            }else{
                if(sum<k){
                    if(0<*(ie+1)){
                        ie++;
                        sum+=*ie;
                    }else if(*ib<0){
                        sum-=*ib;
                        ib++; 
                    }else{
                        ie++;
                        sum+=*ie;
                    }
                }else if(k<sum){
                    if(*(ie+1)<0){
                        ie++;
                        sum+=*ie;
                    }else if(0<*ib){
                        sum-=*ib;
                        ib++;
                    }else{
                        ie++;
                        sum+=*ie;                        
                    }
                }else{
                    // cout<<*ib<<" "<<*ie<<" count++"<<endl;
                    count++;
                    ie++; 
                    sum+=*ie;
                }
            }
        }
        return count;
    }
};
*/