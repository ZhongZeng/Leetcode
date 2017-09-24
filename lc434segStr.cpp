
/*
Leetcode 434. Number of Segments in a String

Related Topics 
String

Next challenges: One Edit Distance, Encode and Decode Strings, Tag Validator

Test Cases:
"Hello, my name is John"
"love live! mu'sic forever"
""

Runtime: 0 ms
You are here! 
Your runtime beats 48.41 % of cpp submissions.

*/

#include<vector>
#include<string>
#include<iostream>
using namespace std;


class Solution {
public:
    int countSegments(string s) {
        int num=0, t;
        bool c=false;
        for(string::iterator si=s.begin(); si!=s.end(); si++){
            t = ' ' - *si;
            if( t!=0 ){
                if( !c ){
                    num++;
                    c = true;
                }                                
            }else{
                c = false;
            }
            
        }
        
        return num;
    }
};


int main(){
	int t1=' '-'a', t2='a'-'A';
	
	cout<< t1 << endl;
	cout<< t2 << endl; //32
	
	return 0; 
}

