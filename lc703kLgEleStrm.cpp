
/*
Leetcode 703. Kth Largest Element in a Stream

Companies   
Amazon 
Related Topics 
Heap 
Similar Questions 
Kth Largest Element in an Array

Test Cases: 
["KthLargest","add","add","add","add","add"]
[[3,[4,5,8,2]],[3],[5],[10],[9],[4]]
["KthLargest","add","add","add","add","add"]
[[3,[5,-1]],[2],[1],[-1],[3],[4]]

Next challenges: Find K-th Smallest Pair Distance, 
Shortest Path to Get All Keys, Minimum Number of Refueling Stops

Runtime: 28 ms
Your runtime beats 98.08 % of cpp submissions.

*/

class KthLargest {
public:
	// a typical heap problem
    KthLargest(int k, vector<int> nums) {// min heap 
        sz=k;
		for( int i=0; i<nums.size(); i++)	pushHp(nums[i]);
    }
    
    int add(int val) {
        pushHp(val);
		return hp[0];
    }

protected:	
	int sz;
	vector<int> hp;
	
	void pushHp( int& t){
		if(hp.size()<sz){
			int i=hp.size(), tp;
			hp.push_back(t);
			
			while(0<i){
				if(hp[i]<hp[(i-1)>>1]){
					tp=hp[i];
					hp[i]=hp[(i-1)>>1];
					hp[(i-1)>>1]=t;
					i=(i-1)>>1;
				}else{
					break;
				}
			}
		}else{// hp.size()==sz
			if(hp[0]<t){
				hp[0]=t;
				int i=0, tp;
				
				while(2*i+2<hp.size()){
					if(hp[2*i+2]<hp[i]&&hp[2*i+2]<hp[2*i+1]){
						tp=hp[i];
						hp[i]=hp[2*i+2];
						hp[2*i+2]=t;
						i=2*i+2;
					}else if(hp[2*i+1]<hp[i]){
						tp=hp[i];
						hp[i]=hp[2*i+1];
						hp[2*i+1]=t;
						i=2*i+1;
					}else{
						break;
					}
				}
				if(2*i+1<hp.size()&&hp[2*i+1]<hp[i]){
					tp=hp[i];
					hp[i]=hp[2*i+1];
					hp[2*i+1]=t;
				}
			}
		}
		
		return ;
	}
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
