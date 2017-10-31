
/*
Leetcode 551. Student Attendance Record I

Related Topics 
String 
Similar Questions 
Student Attendance Record II 

Next challenges: Student Attendance Record II

Test Cases:
"PPALLP"
"PPALLL"

Runtime: 3 ms
You are here! 
Your runtime beats 28.13 % of cpp submissions.

*/


class Solution {
public:
    bool checkRecord(string s) {
        int a=0, l=0;
        for(string::iterator si=s.begin(); si!=s.end(); si++){
            switch( *si ){
                case 'A':   if(a)   return false;
                            a=1;
                            l=0;
                            break;
                case 'L':   if(l==2)   return false;
                            l++;
                            break;
                case 'P':   l=0;
                            break;
            }            
        }
        return true;
    }
};
