#include<string>
#include<iostream>
using namespace std;

int main(){
	string s="abcd";	
	cout << s[0] << endl;
	s = s.append( s[2], 1);
	cout << s << endl;
}
