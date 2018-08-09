
/*
Leetcode 478. Generate Random Point in a Circle

Companies  
Leap Motion 
Related Topics 
Math, Random, Rejection Sampling 
Similar Questions 
Random Point in Non-overlapping Rectangles

Next challenges: Fraction to Recurring Decimal, Super Pow, Transform to Chessboard

Test Case: 
["Solution", "randPoint", "randPoint", "randPoint"]
[[1.0, 0.0, 0.0], [], [], []]

Runtime: 116 ms
Your runtime beats 65.48 % of cpp submissions.
*/

class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        r=radius;
		rq=radius*radius;
		x=x_center;
		y=y_center;
        //cout<<RAND_MAX; 
    }
    
    vector<double> randPoint() {
        vector<double> vd;
        if(r==0)    return vd;
		double r1=1.0*rand()/RAND_MAX*r, r2=1.0*rand()/RAND_MAX*r, dis=r1*r1+r2*r2; 
		
		while(rq<dis){
            //cout<<r1<<","<<r2<<" ";
			r1=1.0*rand()/RAND_MAX*r;
			r2=1.0*rand()/RAND_MAX*r;
            dis=r1*r1+r2*r2;
		}
		vd.push_back(x+r1*(rand()%2!=0?1:-1));
		vd.push_back(y+r2*(rand()%2!=0?1:-1));
		
		return vd;
    }
	
protected:
	double r, rq, x, y;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj.randPoint();
 */
