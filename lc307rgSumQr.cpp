
/*
Leetcode 307. Range Sum Query - Mutable

Companies   
Google, Twitter, Facebook 
Related Topics 
Binary Indexed Tree, Segment Tree 
Similar Questions 
Range Sum Query - ImmutableRange Sum Query 2D - Mutable

Solution: 
https://leetcode.com/articles/range-sum-query-mutable/

Test Case:
["NumArray","sumRange","update","sumRange"]
[[[1,3,5]],[0,2],[1,2],[0,2]]

Runtime: 20 ms
Your runtime beats 93.18 % of cpp submissions.

*/

class NumArray {
public:
    NumArray(vector<int> nums) {// build prefect-balanced segment tree thru vector, O(n) time 
		for( n=1; n<nums.size(); )	n=n<<1;
		vector<int> vt(2*n-1,0);
        sum=vt;
		for( int i=0; i<nums.size(); i++)	sum[n-1+i]=nums[i];// leaf nodes
		for( int i=n-2; -1<i; i--)	sum[i]=sum[2*i+1]+sum[2*i+2];// internal nodes 
		//for( auto e:sum)	cout<<e<<" ";	cout<<endl;
    }
    
    void update(int i, int val) {// O(log(n)) time 
        int d=val-sum[n-1+i];
		for( int j=n-1+i; 0<j; j=(j-1)>>1)	sum[j]+=d;
        sum[0]+=d;
        //for( auto e:sum)	cout<<e<<" ";	cout<<endl;
		return ;
    }
    
    int sumRange(int i, int j) {// O(log(n)) time 
		return sumRange( i, j, 0, 0, n-1);
    }
	
	int sumRange(int & i, int & j, int loc, int b, int e){// loc in sum: [b,e]
        //cout<<b<<","<<e<<":"<<loc<<","<<sum[loc]<<" ";
        if(sum.size()-1<loc)    return 0;
        
		if(i<=b&&e<=j){// [b,e] in [i,j] 
			return sum[loc]; 
		}else if(e<i||j<b){// [b,e] doesn't overlap w/ [i,j] 
			return 0; 
		}else{// [b,e] overlap w/ [i,j] partially 
			int mid=b+(e-b)/2; 
			return sumRange( i, j, 2*loc+1, b, mid)+sumRange( i, j, 2*loc+2, mid+1, e); 
		}
	}
	
protected:
	vector<int> sum;// range sum, segment tree; size=n-1+n 
	int n;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
