

/*
Leetcode 477. Total Hamming Distance

Related Topics 
Bit Manipulation 
Similar Questions 
Hamming Distance 

Test Cases:
[4,2,10]
[4,2]

Runtime: 73 ms
You are here! 
Your runtime beats 39.32 % of cpp submissions.

*/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int sum=0, one, zero, i;
        bool z=true;
        while( z ){
            z = false;
            one=0; zero=0;            
            i=-1;
            while( ++i<nums.size() ){
                if( (nums[i]>>1<<1)-nums[i]!=0 ){
                    one++;
                }else{
                    zero++;
                }
                nums[i]=nums[i]>>1;
                //cout<<zero<<' '<<one<<endl;
                
                if( nums[i]!=0 ){
                    z = true;
                    break;
                }
            }

            while( ++i<nums.size() ){              
                if( (nums[i]>>1<<1)-nums[i]!=0 ){
                    one++;
                }else{
                    zero++;
                
                }                
                nums[i]=nums[i]>>1;                
                //cout<<zero<<' '<<one<<endl;                
            }            
            
            sum += one*zero;                
            //cout<<sum<<endl;
        }
        
        return sum;
    }
};
