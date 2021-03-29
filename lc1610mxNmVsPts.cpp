/*
1610. Maximum Number of Visible Points

Companies:	Google, Amazon
Related Topics:	Two Points, Geometry 

Runtime: 836 ms	Your runtime beats 7.18 % of cpp submissions
Memory Usage: 131.7 MB
*/

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        // O(n) time; angle (360-based) in [0,360]; two pointer 
        if(angle==360)  return points.size();
        int originals=0, max_points=0;
        vector<double> angles;
        
        for( int i=0; i<points.size(); i++){
            if(points[i][0]<location[0]){
                double a=atan(1.0*(points[i][1]-location[1])/(location[0]-points[i][0]))
                        *45/atan(1);
                angles.push_back(180-a);
            }else if(points[i][0]>location[0]){
                double a=atan(1.0*(points[i][1]-location[1])/(points[i][0]-location[0]))
                        *45/atan(1);
                angles.push_back(0<=a?a:360+a);
            }else{// points[i][0]==location[0]
                if(points[i][1]==location[1])   originals++;
                else if(points[i][1]<location[1])   angles.push_back(270);
                else    angles.push_back(90);
            }
        }
        sort( angles.begin(), angles.end());
        for( int i=0, s=angles.size(); i<s; i++)
            angles.push_back(360+angles[i]);
        // for(auto e:angles)  cout<<e<<" ";   cout<<endl;
        
        for( int b=0, e=0; e<angles.size(); ){
            if(angles[e]-angles[b]<=angle){
                max_points=max_points<e-b+1?e-b+1:max_points;
                e++;
            }else{
                b++;
            }
        }
        return max_points+originals;
    }
};