
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int sum;
        int num0 = num;
        
        do{
			sum = 0;
            while (num0 > 0){
                sum += num0%10;
                num0 = num0/10;			
            }
            num0 = sum;
        }while (num0 > 9);
        
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
