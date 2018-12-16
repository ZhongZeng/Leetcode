/*
957. Prison Cells After N Days

Related Topic: Hash Table 

Test Cases:
[1, 1, 0, 1, 1, 0, 1, 1]
6
[0,1,0,1,1,0,0,1]
7

Runtime: 8 ms

*/

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        // bit manipulation, DP
        int c=0, d;
        for( int i=cells.size()-1; -1<i; i--)  c=(c<<1)+cells[i];
        vector<int> vc={c}, rt;
        unordered_map<int,int> um;
        um.emplace(c,0);
        unordered_map<int,int>::iterator umi;
        
        for( int i=1; i<=N; i++){
            //for( int j=0, t=255^(((c<<1)&255)^(c>>1)); j<8; j++, t=t>>1)    cout<<(t%2)<<" ";   cout<<endl;
            c=255^(((c<<1)&255)^(c>>1));// 1<<8-1==255 
            if((c>>7)==1)   c-=128;// 1<<7==128 
            if((c>>1)<<1!=c)c-=1;// adjust for cell at both ends 
            
            vc.push_back(c);
            umi=um.find(c);
            if(umi!=um.end()){
                c=vc[umi->second+(N-i)%(i-(umi->second))];// <=i guranteed 
                break;
            }else{
                um.emplace(c,i);
            }
        }
        
        for( int i=0; i<8; i++, c=c>>1) rt.push_back(c%2);
        
        return rt;
    }
};