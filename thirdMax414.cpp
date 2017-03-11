/*
You are here! 
Your runtime beats 31.85% of cpp submissions.
The code can be extended to nth largest number in an array. 
*/

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
		int nnum= 3;
        int len = nums.size();       
		int isdone = 0;
		
		vector<int> nth;
		nth.push_back(nums[0]);		
		
        for (vector<int>::iterator it = nums.begin(); it < nums.end(); it++){
			//cout << *it << "*it" << endl;			
			for (vector<int>::iterator iu = nth.begin(); iu < nth.end(); iu++){
				//cout << *iu << "*iu" << endl;
				if ( *it == *iu) {
					isdone = 1;
					break;
				}
				else if ( *it > *iu) {
					nth.insert( iu, *it);	
					isdone = 1;
					if (nth.size() > nnum) nth.erase( nth.end()-1 );
					break;					
				}	
			}	
			if (nth.size() < 3 &&  isdone == 0 ) {
				nth.push_back( *it );
				//cout << *it << "push_back"  << endl;
			}
			isdone = 0;			
        }
        
		//cout << nth[0] << endl << nth[1] << endl << nth[2] << endl << endl;
        return (nth.size() == nnum) ? *nth.rbegin() : *nth.begin();      
    }	
};

int main(){
	vector<vector<int>> vec;
	vec.push_back({1, 2, 3});		
	vec.push_back({1, 2, 6, 4, 5, 6});
	vec.push_back({6, 2, 3, 4, 5, 6});
	vec.push_back({3, 2, 1});
	vec.push_back({1});
	vec.push_back({1, 2});
	vec.push_back({1, 2, 3});
	vec.push_back({1, 2, 2, 3});
	vec.push_back({1, 6, 3, 4, 5, 6});
	vec.push_back({3, 3, 1});	
	vec.push_back({5,2,4,1,3,6,0});
	vec.push_back({2, 2, 3});
	vec.push_back({2, 2, 3, 1});
		
	Solution s;
	for (vector<vector<int>>::iterator it = vec.begin(); it < vec.end(); it++){
		cout << "3rd is "<< s.thirdMax( *it ) << endl << endl;
	}

	return 0;
}
