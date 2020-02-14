/*
1344. Angle Between Hands of a Clock

Related Topics	Math

Test Cases:
12
30
3
30
3
15
4
50
12
0

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Angle Between Hands of a Clock.
Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Angle Between Hands of a Clock.

Next challenges:
Super Washing Machines, Nth Magical Number, Adding Two Negabinary Numbers
*/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        // relative angle to 12 
        double h=(hour+minutes/60.0)/12, m=minutes/60.0, a=m<h?h-m:m-h;
        
        if(0.5<a)   a=1-a;
        
        return a*360;
    }
};