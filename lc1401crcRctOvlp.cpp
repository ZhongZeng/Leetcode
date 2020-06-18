/*
1401. Circle and Rectangle Overlapping

Medium
Companies	Google
Related Topics	Geometry

Test Cases:
1
0
0
1
-1
3
1

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Circle and Rectangle Overlapping.
Memory Usage: 6.1 MB, less than 20.89% of C++ online submissions for Circle and Rectangle Overlapping.
Next challenges: Erect the Fence, Minimum Area Rectangle II, Maximum Number of Darts Inside of a Circular Dartboard
*/

class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        // if overlap, must overlap on one of edges
        if(x2<x1)   return checkOverlap( radius, x_center, y_center, x2, y1, x1, y2);
        if(y2<y1)   return checkOverlap( radius, x_center, y_center, x1, y2, x2, y1);
        
        if(x1<=x_center&&x_center<=x2&&y1<=y_center&&y_center<=y2)  
            return true;// circle inside square
        if((x1-x_center)*(x1-x_center)+(y1-y_center)*(y1-y_center)<=radius*radius)  
            return true;// square inside circle
        
        if(circleVerticleOverlap(radius, x_center, y_center, x1, x2, y1))   return true;
        if(circleVerticleOverlap(radius, x_center, y_center, x1, x2, y2))   return true;
        if(circleHorizontalOverlap(radius, x_center, y_center, y1, y2, x1))   return true;
        if(circleHorizontalOverlap(radius, x_center, y_center, y1, y2, x2))   return true;
        
        return false;
    }
    
protected:
    bool circleVerticleOverlap( int radius, int x_center, int y_center, int x1, int x2, int y){// x1<=x2 guranteed
        if(x_center<x1) 
            return distanceSquared( x_center, x1, y_center, y)<=radius*radius;
        else if(x2<x_center)    
            return distanceSquared( x_center, x2, y_center, y)<=radius*radius;
        else    
            return (y_center-y)*(y_center-y)<=radius*radius;
    }
    
    bool circleHorizontalOverlap( int radius, int x_center, int y_center, int y1, int y2, int x){// y1<=y2 guranteed
        if(y_center<y1) 
            return distanceSquared( x_center, x, y_center, y1)<=radius*radius;
        else if(y2<y_center)    
            return distanceSquared( x_center, x, y_center, y2)<=radius*radius;
        else    
            return (x_center-x)*(x_center-x)<=radius*radius;
    }
    
    int distanceSquared( int x1, int x2, int y1, int y2){
        return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    }
};