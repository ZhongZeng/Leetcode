
/*
Leetcode 774. Minimize Max Distance to Gas Station

Companies 
Google
Related Topics 
Binary Search

Test Case: 
[1,2,3,4,5,6,7,8,9,10]
9

Next challenges: Max Sum of Rectangle No Larger Than K, 
Split Array Largest Sum, Maximum Average Subarray II

Runtime: 39 ms
Your runtime beats 96.26 % of cpp submissions.

*/

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        vector<int> vc;
        for(int i=1; i<stations.size(); i++)    vc.push_back(stations[i]-stations[i-1]);// assuming unique stations 
        
        int mx=vc[0], mn=vc[0];
        for(int i=0; i<vc.size(); i++){
            if(mx<vc[i])    mx=vc[i];
            else if(vc[i]<mn)   mn=vc[i];
        }
        
        double b=mx, e=mn*1.0/K, mid=b+(e-b)/2, df=1.0/1000000;
        int kb=findK(b,vc), ke=findK(e,vc), km=findK(mid,vc);
        
        while(df<b-e){// K [b,e) 
            mid=b+(e-b)/2;
            //cout<<b<<","<<mid<<","<<e<<": "<<kb<<","<<km<<","<<ke<<"; ";
            km=findK(mid,vc);
            if(K<km){
                e=mid;
                ke=km;
            }else{
                b=mid;
                kb=km;
            }
        }
        
        return b;
    }
    
    int findK( double& mid, vector<int>& vc){
        int sum=0, s;
        double t;
        
        for( int i=0; i<vc.size(); i++){
            t=vc[i]/mid;
            s=t;
            if(s!=t){
                sum+=s;
            }else{
                sum+=s-1;
            }
        }
        
        return sum;
    }
};
