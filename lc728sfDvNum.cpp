
/*
Leetcode 728. Self Dividing Numbers

Next challenges: Perfect Number

Test Cases:
1
22

Runtime: 6 ms

*/

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> num, dg(10,0), dr(2,0), rv;
        // digits, #digits, divisive, return vector
        int tn=left-1, ad, r;
        while( tn!=0 ){
            r=tn%10;
            num.push_back(r);
            dg[r]++;  
            tn=tn/10;
        }
        tn=left-1;
        for(int i=2; i!=10; i++)    dr.push_back(tn%i);        
                
        while(tn!=right){
            tn++;
            ad=1;
            for( vector<int>::iterator it=num.begin(); it!=num.end(); it++){
                // update num-digits, dg-#digits
                if(ad){
                    dg[*it]--;
                    *it=*it+1; 
                    if(9<*it){
                        *it=*it-10;
                        ad=1;
                    }else{
                        ad=0;
                    }
                    dg[*it]++;                    
                }else{
                    break;
                }                                        
            }
            if(ad)  num.push_back(1);// 1 doesn't matter as divider
            
            for( int i=2; i!=10; i++ ){// update dr-divisive
                if(dr[i]!=i-1)  dr[i]++;
                else    dr[i]=0;
            }          
            
            if(dg[0]!=0)    continue;
            int i=1;
            while(  ++i!=10 ){
                if(dg[i]!=0 && dr[i]!=0)  break;                                
            }
            if(i==10)    rv.push_back(tn);
        }
        
        return rv;
    }

protected:
    void prt(vector<int> num, vector<int> dg, vector<int> dr){
        // prt(num, dg, dr);
        for(int i=0; i!=num.size(); i++)    cout<<num[i]<<" ";
        cout<<endl;
        for(int i=0; i!=dg.size(); i++)    cout<<dg[i]<<" ";
        cout<<endl;
        for(int i=0; i!=dr.size(); i++)    cout<<dr[i]<<" ";
        cout<<endl<<endl;         
        return ;
    }
};
