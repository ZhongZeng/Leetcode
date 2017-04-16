

/*
Leetcode 415. Add Strings
You are here! 
Your runtime beats 56.73% of cpp submissions. 9 ms
Your runtime beats 36.04% of cpp submissions. 12 ms
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        string::reverse_iterator it1=num1.rbegin(), it2=num2.rbegin();
        string str("");
        int addone=0, digit;
        while(it1!=num1.rend() && it2!=num2.rend()){
            digit=*it1+*it2-2*'0'+addone;
            if(9<digit){
                addone=1;
                digit-=10;
            }else{
                addone=0;
            }
            str.append(to_string(digit));
            // cout<<*it1<<" "<<*it2<<" "<<digit<<endl<<str<<endl;
            ++it1;
            ++it2;
        }
        
        while(it1!=num1.rend()){
            digit=*it1-'0'+addone;
            if(9<digit){
                addone=1;
                digit-=10;
            }else{
                addone=0;
            }
            str.append(to_string(digit));
            ++it1;
        }
        
        while(it2!=num2.rend()){
            digit=*it2-'0'+addone;
            if(9<digit){
                addone=1;
                digit-=10;
            }else{
                addone=0;
            }
            str.append(to_string(digit));
            ++it2;
        }
        
        if(addone){
            str.append(to_string(1));
        }
        
        reverse(str.begin(), str.end());
		// insertion in array is expensive O(n), 
		// so push_back first and then reverse
        
        return str;
    }
    
};
