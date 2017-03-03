/*
cd F:/Michael/Fordham_University/Computer_Science/Leetcode
*/

#include<vector>
#include<iostream>

using namespace std;

int main(){
	vector<int> arr = {1, 2, 3};
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(6);
	
	cout << arr[5] << endl;
	
	for (vector<int>::reverse_iterator i=arr.rbegin(); i!=arr.rend(); i++){
		cout << *i << endl;
	}
	
	return 0;
}