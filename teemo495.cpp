#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int poison = 0;
        int diff = duration;
        for (vector<int>::reverse_iterator i = timeSeries.rend() ; i!= timeSeries.rbegin(); diff = *i - *--i ){
            poison +=  (diff > duration) ? duration : diff;
        }
        return poison;
        
    }
};

int main(){
	Solution a;
	vector<int> arr = [ 1, 2];
	cout << a.findPoisonedDuration( arr, 2);
	return 0;
}
