#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0) {return "";}
        string stri;
        string prefix = strs[0];
		if (prefix.length()==0) {return "";}
        int i, leni;
        for (vector<string>::iterator it=strs.begin(); it<strs.end(); it++){
			 stri = *it;
             if (stri.length()==0) return "";
             leni = (it->length() > prefix.length()) ? prefix.length() : it->length();
             prefix = prefix.substr(0, leni);
             for (i=0; i< leni; i++){
                if( prefix[i] != stri[i]){
                    prefix = prefix.substr(0,i);
                    break;
                }
            }
        }
        return prefix;
    }
};

int main(){
	Solution s;
	vector<string> strs,strs1;
	strs.push_back("abcde");
	strs.push_back("abcd");
	strs.push_back("abcdef");
	strs.push_back("abc");
	cout << strs[0] << endl;
	vector<string>::iterator it1=strs.begin();
	//cout << *(*it1 + 2) << endl;//wrong
	cout << s.longestCommonPrefix(strs) << endl;
	strs.push_back("");
	cout << s.longestCommonPrefix(strs) << endl;
	cout << s.longestCommonPrefix(strs1) << endl;
	return 0;

}
