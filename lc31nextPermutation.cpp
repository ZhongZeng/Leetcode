

/*
Leetcode 31. Next Permutation

Tag: Array
Similar Problems: (M) Permutations (M) Permutations II (M) Permutation Sequence (M) Palindrome Permutation II
Next challenges: (M) Permutations II(M) Permutation Sequence(M) Palindrome Permutation II

You are here! 
Your runtime beats 86.04 % of cpp submissions.	9 ms
Your runtime beats 56.52 % of cpp submissions.	12 ms
Your runtime beats 1.68 % of cpp submissions.	25 ms

Test Cases:
[1]
[1,1]
[1,2]
[2,3,1]
[1,2,3]
[3,2,1]
[5,1,1]
[3,1,1,2,4]

*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // O(n) time, O(1) space
        if(nums.size()<2) return ;
        vector<int>::reverse_iterator it=nums.rbegin(),it2,its;
        int temp;
        while( it!=nums.rend() ){
            if( *it > *++it ){
                // cout<<"first test"<<endl;
                break;
            }
        }

        /* reverse the vector */
        its = it--;
        // cout<<*it<<endl;
        it2 = nums.rbegin();
        while( it2 < it ){
            temp=*it;
            *it--=*it2;
            *it2++=temp;
            // cout<<*it<<" "<<*it2<<endl;
        }
        // for(int e:nums) cout<<e<<" "; cout<<endl;
        
        if(its!=nums.rend()){
            it=its;
            while(--it!=--nums.rbegin()){
                if(*its<*it){
                    // cout<<*it<<endl;
                    temp=*its;
                    *its=*it;
                    *it=temp;
                    break;
                }
            }
        }
        // cout<<"last test"<<endl;
        
        return ;
    }
};

