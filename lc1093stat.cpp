/*
1093. Statistics from a Large Sample

Test Cases:
[0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
[0,4,3,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

Next challenges: Restore IP Addresses, Boundary of Binary Tree, Nth Magical Number

Runtime: 4 ms
Memory Usage: 9 MB
*/

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        // minimum, maximum, mean, median, mode; [0,255]
        int i, cc, ct=0, mst=0;
        double mean=0.0;
        vector<double> rt;
        
        for( i=0; i<count.size(); i++){// min 
            if(count[i]!=0) break;
        }
        rt.push_back(i);
        
        for( i=count.size()-1; -1<i; i--){// max
            if(count[i]!=0) break;
        }
        rt.push_back(i);
        
        for( i=0; i<count.size(); i++)  ct+=count[i];
        for( i=0; i<count.size(); i++)  mean+=i*1.0*count[i]/ct;// mean 
        rt.push_back(mean);
        
        if(ct%2==1){// median 
            for( i=0, cc=0; i<count.size(); i++){
                cc+=count[i];
                if(ct/2<cc)  break;// ct/2==(ct-1)/2; < not <= 
            }
            rt.push_back(i);
        }else{
            for( i=0, cc=0; i<count.size(); i++){
                cc+=count[i];
                if(ct/2<cc){
                    rt.push_back(i);
                    break;
                }else if(ct/2==cc){
                    rt.push_back(i);
                    for( i++; i<count.size()&&count[i]==0; i++){}
                    rt.back()=(rt.back()+i)/2.0;
                    break;
                }
            }
        }
        
        for( int i=0; i<count.size(); i++){// mode
            if(count[mst]<count[i]) mst=i;
        }
        rt.push_back(mst);
        
        return rt;
    }
};