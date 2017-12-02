

/*
Leetcode 215. Kth Largest Element in an Array

Related Topics 
Divide and Conquer, Heap 
Similar Questions 
Wiggle Sort II, Top K Frequent Elements, Third Maximum Number 

Next challenges: Wiggle Sort II, Top K Frequent Elements,
Third Maximum Number

Runtime: 9 ms
Your runtime beats 59.49 % of cpp submissions.

*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // O(n*lg(k)) time; k sapce; k belongs [1,nums.size()]
        vector<int> hp;// min
        int i=-1, j, tp;
        while(++i!=k){
            hp.push_back(nums[i]);
            for(j=hp.size()-1; j!=0; j=(j-1)/2){
                if( hp[j]<hp[(j-1)/2] ){
                    tp=hp[j];
                    hp[j]=hp[(j-1)/2];
                    hp[(j-1)/2]=tp;
                }else{
                    break;
                }
            }
        }
        
        //cout<<hp[0]<<endl;
        i--;
        while(++i!=nums.size()){
            if(!(nums[i]<hp[0])){// must include = bz it's not distinct
                hp[0]=nums[i];
                j=0;
                while(2*j+2<k){
                    if(hp[2*j+2]<hp[j] && !(hp[2*j+1]<hp[2*j+2])){
                        tp=hp[j];
                        hp[j]=hp[2*j+2];
                        hp[2*j+2]=tp;
                        j=2*j+2;
                    }else if(hp[2*j+1]<hp[j] && !(hp[2*j+2]<hp[2*j+1])){
                        tp=hp[j];
                        hp[j]=hp[2*j+1];
                        hp[2*j+1]=tp;
                        j=2*j+1;
                    }else{
                        break;
                    }
                }
                if(2*j+1<k && hp[2*j+1]<hp[j]){
                    tp=hp[j];
                    hp[j]=hp[2*j+1];
                    hp[2*j+1]=tp;                    
                }
            }
        }
        
        return hp[0];
    }
};
