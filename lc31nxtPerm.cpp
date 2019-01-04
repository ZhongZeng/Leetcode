

/*
Leetcode 31. Next Permutation

Tag: Array
Similar Problems: (M) Permutations (M) Permutations II (M) Permutation Sequence (M) Palindrome Permutation II
Next challenges: (M) Permutations II(M) Permutation Sequence(M) Palindrome Permutation II

Test Cases:
[1]
[1,1]
[1,2]
[2,3,1]
[1,2,3]
[3,2,1]
[5,1,1]
[3,1,1,2,4]
[3,2,1,1]
[3,6,4,2]
*/

//Runtime: 12 ms, faster than 49.20% of C++ online submissions for Next Permutation.
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // O(n) time, O(1) space
        if(nums.size()<2)   return ;
        int i, j, k;
        for( i=nums.size()-1; 0<i; i--){// start from back 
            if(nums[i-1]<nums[i]){// find 1st element < previous one, (i:] non-increasing
                for( j=i, k=nums.size()-1; j<k; j++, k--)   swap(nums, j, k); 
                
                for( j=i; ; j++){// find smallest element > nums[i-1] in non-decreasing (i:]
                    if(nums[i-1]<nums[j]){
                        swap( nums, i-1, j);
                        return ;
                    }
                }
                return ;// won't be triggered 
            }
        }
        
        for( i=0, j=nums.size()-1; i<j; i++, j--)   swap(nums, i, j);// entire vector is non-increasing 
        
        return ;
    }
    
    void swap(vector<int>& nums, int a, int b){
        int t=nums[a];
        nums[a]=nums[b];
        nums[b]=t;
        return ;
    }
};

// Your runtime beats 86.04 % of cpp submissions.	9 ms
// Your runtime beats 56.52 % of cpp submissions.	12 ms
// Your runtime beats 1.68 % of cpp submissions.	25 ms
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
        
		/* find the smallest element larger than *its */
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

// Runtime: 13 ms	Your runtime beats 33.94 % of cpp submissions.
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // O(n*lg(n)) time, average O(n) time
        int max=*nums.rbegin(), min=*nums.rbegin(), i=nums.size(), j=nums.size(), k, nxt, temp;
        while( --i!=-1 ){
            if( nums[i]<max ){                
                break;
            }else{
                max = nums[i];
            }            
        }        
        
        if(i==-1){
            sort(nums.begin(), nums.end());
            return ;
        }
        
        while( --j!=i ){ // find the fisrt element larger than nums[i]
            if( nums[i]<nums[j] ){
                nxt = j;
                break;
            }            
        }
                    
        k=j;
        while( --j!=i ){ // find the smallest element larger than nums[i]
            if( nums[j]<nums[nxt] && nums[i]<nums[j] ){
                nxt = k;
            }
        }
        
        temp = nums[i] ;
        nums[i] = nums[k] ;
        nums[k] = temp;
        
        sort( nums.begin()+i+1, nums.end());
        return ; 
    }
};
