/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases.
*/

#include<vector>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string str;
		int rem;
        while (n > 0){
			rem = n%26;
			if ( rem == 0 ){
				str.insert( str.begin(), 'Z');
				n = n / 26 - 1;
			}else{
				str.insert( str.begin(), 'A' + rem - 1);
				n = n / 26;
			}			
        }		
        return str;
    }
};

int main(){
	cout << static_cast<char>('A'+1) << endl;
	Solution s;
	cout << s.convertToTitle(1) << endl;
	cout << s.convertToTitle(26) << endl;
	cout << s.convertToTitle(30) << endl;
	cout << s.convertToTitle(52) << endl;
	cout << s.convertToTitle(260) << endl;
	return 0;
}

