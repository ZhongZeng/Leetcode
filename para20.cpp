
// Leetcode #20 

#include<stack>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for (int i=0; i<s.length(); i++){
            
            switch(s[i]){
                case '(':
                case '[':
                case '{':sta.push(s[i]);
                        break;
                case ')':
                        if (sta.empty()) 
                            return false;
                        else
							if(sta.top()=='(') sta.pop();
							else  return false;
                        break;
                case ']':
                        if (sta.empty()) 
                            return false;
                        else
							if(sta.top()=='[') sta.pop();
							else  return false;
                        break;
                case '}':
						if (sta.empty()) 
						    return false;
                        else
							if(sta.top()=='{') sta.pop();
							else  return false;
                        break;
            }
            
        }
        return sta.empty() ? true: false;
    }
};

int main(){
	string str="{[()]}";
	Solution s;
	cout << s.isValid(str) << endl;
	stack<char> strcha;
	// cout << strcha.top() << endl; // error
	
	return 0;
}