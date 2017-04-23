

/*
Leetcode # 120. Triangle

Tag:  Array Dynamic Programming
Next challenges: (H) Longest Valid Parentheses(M) Unique Binary Search Trees II(M) Count Numbers with Unique Digits

You are here! 
Your runtime beats 30.15% of cpp submissions. 6 ms

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int lev = triangle.size();
        for(int i=lev-1; i!=0; i--){
            for(vector<int>::iterator itu=triangle[i-1].begin(), itd=triangle[i].begin(); itu!=triangle[i-1].end(); itu++){
                *itu = *itu + equalMin(*itd, *itd++);
                // cout<<i<<" "<<*itu<<endl;
            }
        }
        return triangle[0][0];
    }
	
	int equalMin(int a, int b){
		if(a<b) return a;
		else return b;
	}
};

int main(){
	vector<vector<int>> test1 = {{1},{2,3},{4,5,6},{10,8,9,7}};
	Solution s;
	cout << s.minimumTotal(test1) << endl;
	return 0;
}


