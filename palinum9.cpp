#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0 || (x%10==0 && x!=0)){return false;}
        int y = 0;
        while (x>y){
            y = y*10 + x%10;
            x = x/10;
        }/*
		cout << x << endl;
		cout << y << endl;*/
        return x==y || x==y/10;
    }
};

int main(){
	Solution s;
	cout << s.isPalindrome(123454321) << endl << endl;
	cout << s.isPalindrome(12344321) << endl << endl;
	cout << s.isPalindrome(123443) << endl << endl;
	cout << s.isPalindrome(0) << endl << endl;
	cout << s.isPalindrome(11) << endl << endl;
	
	return 0;
}