
/*

Leetcode 561. Array Partition I

Tag: Array
Next challenges: (M) Combination Sum II(E) Shortest Word Distance(M) 3Sum Smaller

You are here! 
Your runtime beats 49.30 % of cpp submissions.
85 ms

We can prove that it must be
( 1st smallest, 2st smallest), ( 3th smallest, 4th smallest)

*/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        
        
		sort(nums.begin(),nums.end());
        // mergeSort(nums.begin(),nums.end());
		/*You are here! 
		Your runtime beats 5.69 % of cpp submissions.	Runtime: 116 ms
		*/
		
        int minsum=0;
        for(vector<int>::iterator it=nums.begin();it<nums.end(); it+=2){
            minsum+=*it;
        }
        return minsum;
    }

protected: 
    void mergeArray(vector<int>::iterator nums1, vector<int>::iterator nums2, vector<int>::iterator nums3){
    	vector<int> nums0;
    	for(vector<int>::iterator it=nums1;it!=nums2;it++){
    		nums0.push_back(*it);
    		// cout<<*it<<" copy"<<endl;
    	}
    	
    	vector<int>::iterator it1=nums0.begin();
    	while(it1!=nums0.end()){ // ||nums2!=nums3
    		// cout<<*it1<<" "<<*nums2<<" merge"<<endl;
    		if(nums2!=nums3 && *nums2<*it1){
    			*nums1=*nums2;
    			nums1++;
    			nums2++;			
    		}else{
    			*nums1=*it1;
    			nums1++;
    			it1++;
    		}
    	}
    	return ;
    }
    
    void mergeSort(vector<int>::iterator nums1, vector<int>::iterator nums3){	
    	if(nums3-nums1<2){
    		return ;
    	}else{
    		vector<int>::iterator nums2=nums1+((int)(nums3-nums1))/2;
    		// cout<<((int)(nums3-nums1))<<" nums3-nums1"<<endl;
    		mergeSort(nums1, nums2);
    		mergeSort(nums2, nums3);
    		mergeArray(nums1, nums2, nums3);
    		return ;
    	}
    }   
    
};