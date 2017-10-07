
/*

Leetcode 645. Set Mismatch

Related Topics 
Hash Table, Math 
Similar Questions 
Find the Duplicate Number 

Next challenges: Maximal Rectangle, Strobogrammatic Number, 4 Keys Keyboard

Runtime: 33 ms
You are here! 
Your runtime beats 96.79 % of cpp submissions.

*/


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> vc(nums.size()+1,0), rt;
        int dup, mis;// duplicated number, missed number

        for(vector<int>::iterator it=nums.begin(); it!=nums.end(); it++){
            if( vc[*it]!=0 ){
                dup=*it;
            }else{
                vc[*it]=1;
            }
        }        
        
        for(int i=1; i!=vc.size(); i++){
            if(vc[i]==0){
                mis=i;
                break;
            }
        }
        
        // for(int i=0; i!=vc.size(); i++) cout<<vc[i]<<endl;
        
        rt.push_back( dup );
        rt.push_back( mis );
        return rt;
    }
};

