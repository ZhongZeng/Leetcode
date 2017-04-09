
/*
Leetcode # 167. Two Sum II - Input array is sorted
You are here! 
Your runtime beats 30.63% of cpp submissions. 6 ms
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>::iterator ia=numbers.begin(), ib=--numbers.end();
		
		while(ia!=ib){
		    // cout<<*ia<<" "<<*ib<<endl;
			if(*ia+*ib < target)
				ia++;
			else if(target < *ia+*ib)
				ib--;
			else
			    break;
		}
		
		vector<int> res;
		res.push_back( ++ia-numbers.begin());
		res.push_back( ib-numbers.end()+numbers.size()+1);
		return res;
		
    }
	
};

int main(){


}
