/* 
Leetcode 412. Fizz Buzz
You are here! 
Your runtime beats 12.84% of cpp submissions. 6 ms
*/

#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> str;
        for (int i=1; i!= n+1; i++){
            bool five = i/5 == i /5.0;
            if (i/3 == i /3.0){
                if (five){
                    str.push_back("FizzBuzz");
                }else{
                    str.push_back("Fizz");
                }
            }else {
                if (five){
                    str.push_back("Buzz");
                }else{
                    str.push_back(to_string (i));
                }
            }
        }
		return str;
    }
};

int main(){
	Solution sol;
	vector<string> fizz = sol.fizzBuzz(16);
	for (int i=0; i!=fizz.size(); i++){
		cout << fizz[i] << endl;
	}
}
