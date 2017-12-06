

/*
Leetcode 149. Max Points on a Line

Related Topics 
Hash Table Math 
Similar Questions 
Line Reflection 

Test Cases:
[]
[[1,1],[2,2],[3,3]]
[[0,0],[0,1],[1,0]]
[[0,0],[0,1],[0,0]]
[[1,1],[1,1],[1,1]]
[[84,250],[0,0],[1,0],[0,-70],[0,-70],[1,-1],[21,10],[42,90],[-42,-230]]
[[0,0],[94911151,94911150],[94911152,94911151]]
[[0,0],[-1,-1],[2,2]]
[[3,1],[12,3],[3,1],[-6,-1]]

Runtime: 12 ms
Your runtime beats 39.79 % of cpp submissions.
Runtime: 9 ms
Your runtime beats 44.25 % of cpp submissions.

*/


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
/*struct Line{
    int k;
    int b;
    bool par;
    const Line(int k1, int b1, bool par) : k(k1) , b(b1), par(false) {
        
    }
    
    void chgLn(int k1, int b1, bool par1){
        this->k = k1;
        this->b = b1;
        this->par = par1;
    }
    
};*/

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        // O(n^)2 time
        // find all possible lines
        // y=k*x+b or x=c
        // on the line is transitive
        if(points.size()<3) return points.size();
        
        unordered_map<double,unordered_map<double,int>> um; // y=k*x+b 
        unordered_map<double,unordered_map<double,int>>::iterator umi;
        unordered_map<double,int> uy; // x=c 
        unordered_map<double,int> ut; // temp
        unordered_map<double,int>::iterator uti;
        
        double k, b;// k, b should be double!
        int mx=2, cmx, c;
        for(vector<Point>::iterator pi1=points.begin(); pi1!=points.end()-1; pi1++){
            um.clear(); // y=k*x+b 
            uy.clear(); // x=c 
            c=1; // # deplicates including itself
            cmx=0; // max pionts on a line with pi1 in this iteration except deplicates&itself
            // following this procedure, you actually don't need b! 
            for(vector<Point>::iterator pi2=pi1+1; pi2!=points.end(); pi2++){
                if(pi1->x!=pi2->x){ // slope line          
                    k = 10.0 * (pi1->y - pi2->y) / (pi1->x - pi2->x);
                    //*10 to pass [[0,0],[94911151,94911150],[94911152,94911151]]
                    b = 10.0 * pi1->y - k * pi1->x; 
                    //b = 10.0 * pi2->y - k * pi2->x;//fail on [[3,1],[12,3],[3,1],[-6,-1]]
                    //cout<<pi1->x<<" "<<pi2->x<<" "<<k<<" "<<b<<endl;
                    umi=um.find(k);
                    if(umi!=um.end()){ // k matches? 
                        uti=umi->second.find(b);
                        if(uti!=umi->second.end()){ // b matches?
                            uti->second+=1;
                            cmx=cmx<uti->second?uti->second:cmx;
                        }else{
                            umi->second.emplace(b,1);
                            cmx=cmx<1?1:cmx;
                        }
                    }else{
                        ut.clear();
                        ut.emplace(b,1);
                        um.emplace(k,ut);
                        cmx=cmx<1?1:cmx;
                    }
                }else{  // parallel to  y axis
                    if(pi1->y!=pi2->y){
                        uti=uy.find(pi1->x);
                        if(uti!=uy.end()){
                            uti->second+=1;
                            cmx=cmx<uti->second?uti->second:cmx;
                        }else{    
                            uy.emplace(pi1->x,1);
                            cmx=cmx<1?1:cmx;
                        }
                    }else{ // duplicate points
                        c++;                      
                    }
                }                                    
            }
            //cout<<cmx<<" "<<c<<"; "<<endl;
            mx=mx<cmx+c?cmx+c:mx;
        }
        
        return mx;
    }
    
};


/*
Failed Attempt

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        // O(n^)2 time
        // find all possible lines
        // y=k*x+b or x=c
        // points may contain duplidates!
        if(points.size()<3) return points.size();
        unordered_map<int,unordered_map<int,int>> pt; // points, x, y, #
        unordered_map<int,unordered_map<int,int>> um; // y=k*x+b 
        unordered_map<int,unordered_map<int,int>>::iterator umi;
        unordered_map<int,int> uy; // x=c 
        unordered_map<int,int> ut; // temp
        unordered_map<int,int>::iterator uti;
        int k, b, mx=1, c1, c2, c;
        
        for(vector<Point>::iterator pi1=points.begin(); pi1!=points.end(); pi1++){
            umi=um.find(pi1->x);
            if(umi!=pt.end()){
                uti=umi->second.find(pi1->y);
                if(uti!=umi->second.end()){
                    uti->second+=1;
                }else{
                    umi->second.emplace(pi1->y,1);
                }
            }else{
                ut.clear();
                ut.emplace(pi1->y,1);
                pt.emplace(pi1->x,ut);
            }
        }
        
        for(unordered_map<int,unordered_map<int,int>>::iterator pi1=pt.begin(); pi1!=pt.end(); pi1){
            
            for(unordered_map<int,unordered_map<int,int>>::iterator pi2=pi1; pi2!=pt.end(); pi2++){
                if(pi1->first!=pi2->first){ // parallel to x axis
                    k = (pi1->second.first - pi2->second.first) / (pi1->first - pi2->first);
                    b = pi1->second.first - k * pi1->second.first;
                    //cout<<pi1->first<<" "<<pi2->first<<" "<<k<<" "<<b<<endl;
                    umi=um.find(k);
                    c1=pi1->second.second;
                    c2=pi2->second.second;
                    c = c1*c2 + c1*(c1-1)/2 + c2*(c2-1)/2;
                    if(umi!=um.end()){
                        uti=umi->second.find(b);
                        if(uti!=umi->second.end()){
                            uti->second+=c;
                            mx=mx<uti->second?uti->second:mx;
                        }else{
                            umi->second.emplace(b,c);
                        }
                    }else{
                        ut.clear();
                        ut.emplace(b,c);
                        um.emplace(k,ut);
                    }
                }else{  // parallel to  y axis
                    uti=uy.find(pi1->x);
                    if(uti!=uy.end()){
                        uti->second+=c;
                        mx=mx<uti->second?uti->second:mx;
                    }else{    
                        uy.emplace(pi1->x,c);
                    }
                }                                    
            }
        }
        
        return perm(mx);
    }

protected:
    int perm(int mx){// n*(n-1)/2=mx; 1<mx
        int b=1,e=mx+2,mid;// corner case
        while(b<e-1){
            mid=b+(e-b)/2;
            if(2*mx/mid<mid-1)  e=mid;
            else    b=mid;
        }
        return b;
    }
    
};
*/