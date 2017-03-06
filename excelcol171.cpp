
#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
		int col = 0;
		int len = s.length();
		for (int i=0; i<len; i++) col = col*26 + s[i]-'A'+1;
		return col;
    }
};

int main(){
	cout << ('A'-'a') << endl;
	cout << ('B'-'A') << endl;
	
	
	return 0;
}
