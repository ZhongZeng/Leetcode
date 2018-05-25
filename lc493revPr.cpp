
/*
Leetcode 493. Reverse Pairs

Companies 
Google 
Related Topics 
Divide and Conquer, Binary Indexed Tree, Segment Tree, Binary Search Tree 
Similar Questions 
Count of Smaller Numbers After Self, Count of Range Sum

Next challenges: Count of Smaller Numbers After Self, Count of Range Sum

Test Cases:
[2147483647,2147483647,2147483647,2147483647,2147483647,2147483647]
[1,3,2,3,1]
[2,4,3,5,1]
[3,1,1]
[4,1]
[1]

Runtime: 297 ms
Your runtime beats 36.19 % of cpp submissions. 

*/

class Solution {
public:
    int reversePairs(vector<int>& nums) {
		// divide&conquer, similiar to merge sort; O(n*log(n)) time, O(n) space 
        if(nums.size()<2)   return 0;
        int rt=0, b=0, e=nums.size(), m=b+(e-b)/2;
		
		dv( nums, b, m, rt);
		dv( nums, m, e, rt);
		mge( nums, b, m, e, rt);
		
		return rt;
    }
	
	void dv(vector<int>& nums, int b, int e, int& rt){// divide 
		if(e-b==1)	return;
		
		int m=b+(e-b)/2;
		dv(nums, b, m, rt);
		dv(nums, m, e, rt);
		mge(nums, b, m, e, rt);
		
		return ;
	}
	
	void mge(vector<int>& nums, int b, int m, int e, int& rt){ // merge, 2 pointer 
		int i, j, k;
		vector<int> vc;
		for( i=b; i<m; i++)	vc.push_back(nums[i]);
		
		for( i=b, j=m; j<e; ){//count reverse pairs 
            // nums[i] is the smallest element larger than 2*nums[j] proveable 
			if(i==m||nums[j]<nums[i]/2.0){// corner case 2147483647, int overlow
				rt+=m-i; //cout<<rt<<":"<<b<<" "<<m<<" "<<e<<endl;//cout<<i<<" "<<j<<endl<<endl;
				j++;
			}else{
				i++;
			}
		}
		
		for( i=0, j=m, k=b; i<vc.size(); k++){// merge sort 
			if(j==e||vc[i]<nums[j])	nums[k]=vc[i++];
			else	nums[k]=nums[j++];
		}
		
		return ;
	}
};
