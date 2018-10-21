
/*
Leetcode 925. Long Pressed Name

Test Cases:
"alex"
"aaleex"
"saeed"
"ssaaedd"
"laiden"
"laiden"
"pyplrz"
"ppyypllr"
"ab"
"a"

Runtime: 0 ms

*/


class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0, j=0;
        if(name.size()<1)   return typed.size()<1;
        if(typed.size()<1)  return name.size()<1;
        if(name[0]!=typed[0])   return false;
        
        while( j<typed.size() ){
            if(name.size()<i)   return false;
            if(i==name.size()||name[i]!=typed[j]){
                if(name[i-1]!=typed[j]) return false;
                else    j++;
            }else{
                i++;
                j++;
            }
        }
        
        
        return i==name.size()&&j;
    }
};
