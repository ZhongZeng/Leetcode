/*
1502. Can Make Arithmetic Progression From Sequence

Weekly Contest 196
Rank	Name	Score	Finish Time 	Q1 (3)	Q2 (4)	Q3 (5)	Q4 (7)
7787 / 14301	zhongzeng 	3	0:06:31	0:06:31 		

Easy

Test Cases:
[-68,-96,-12,-40,16]
[0,0,0,0]
[3,5,1]
[1,2,4]
*/

/*
Runtime: 16 ms
Memory Usage: 9.4 MB
*/
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
		// O(n) time; hash table 
		if(arr.size()<3)	return true;
		int i, min0=arr[0]<arr[1]?arr[0]:arr[1], min1=arr[0]<arr[1]?arr[1]:arr[0], d;
		unordered_set<int> us;
        
		for( i=1; i<arr.size()&&arr[i-1]==arr[i]; i++){}
		if(i==arr.size())	return true;
		
		for( i=0; i<arr.size(); i++){
			if(us.find(arr[i])!=us.end())	return false;
			else	us.emplace(arr[i]);
		}
		
		for( i=2; i<arr.size(); i++){
			if(arr[i]<min0){
				min1=min0;
				min0=arr[i];
			}else if(arr[i]<min1){
				min1=arr[i];
			}
		}
		
		d=min1-min0;
		for( unordered_set<int>::iterator it=us.begin(); it!=us.end(); it++){
			if(*it!=min0&&us.find((*it)-d)==us.end())	return false;
		}
		
		return true;
	}
};

/*
Runtime: 12 ms	Your runtime beats 75.00 % of cpp submissions.
Memory Usage: 8.9 MB
*/
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        // O(n*log(n)) time; O(n) space; sort
        if(arr.size()<3)    return true;
        sort( arr.begin(), arr.end());
        int d=arr[1]-arr[0];
        
        for( int i=2; i<arr.size(); i++){
            if(arr[i]-arr[i-1]!=d)  return false;
        }
        
        return true;
    }
};