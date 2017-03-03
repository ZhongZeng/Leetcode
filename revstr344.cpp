#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string reverseString(string s) {
        string str = "";
        for(int i = s.length(); i>0; i--){
            str.push_back( s[i-1] );
        }
        return str;
    }
};

int main(){	
	string s="abcd";	
	cout << s[0] << endl;
	
	Solution sol;
	cout << sol.reverseString(s) << endl;
}
