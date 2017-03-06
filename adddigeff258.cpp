
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        int num0 = num;
        
        while (num0 > 0){
            sum += num0%10;
            num0 = num0/10;			
			if (sum > 9) sum -= 9; 
        }
        
        return sum;
    }
};

int main(){
	Solution s;
	cout << s.addDigits(0) << endl << endl;
	cout << s.addDigits(10) << endl << endl;
	cout << s.addDigits(1234) << endl << endl;
	return 0;
}