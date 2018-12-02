
/*
949. Largest Time for Given Digits

Related Topics: Math 

Test Cases:
[1,2,3,4]
[5,5,5,5]
[4,2,4,4]
[0,0,1,0]
[1,9,6,0]
[6,2,3,9]
[2,0,6,6]

Runtime: 4 ms

*/

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        // 00:00 to 23:59
        string rt="";
        int b, c, d;
        
        b=largestLessThanT( A, 3);
        if(b==-1)  return rt;
        
        if(b==2){
            c=largestLessThanT( A, 4);
            if(c==-1){
                A.push_back(2);
                b=largestLessThanT( A, 2);// break;
            }else{
                d=largestLessThanT( A, 6);
                if(d==-1){
                    A.push_back(2);
                    A.push_back(c);
                    b=largestLessThanT( A, 2);// break
                }else{
                    rt.push_back('2');
                    rt.push_back((char)('0'+c));
                    rt.push_back(':');
                    rt.push_back((char)('0'+d));
                    rt.push_back((char)('0'+A[0]));
                    return rt;
                }
            }
        }
        
        // b<'2'
        if(b==-1)   return rt;
        
        c=largestLessThanT( A, 10);
        d=largestLessThanT( A, 6);
        if(d==-1)   return rt;
        
        rt.push_back((char)('0'+b));
        rt.push_back((char)('0'+c));
        rt.push_back(':');
        rt.push_back((char)('0'+d));
        rt.push_back((char)('0'+A[0]));        
        
        return rt;
    }
    
protected:
    int largestLessThanT(vector<int>& A, int t){
        int i, j, c=-1;
        for( i=0; i<A.size(); i++){
            if(A[i]<t){
                c=A[i];
                j=i;
                break;
            }
        }
        for( ; i<A.size(); i++){
            if(A[i]<t&&c<A[i]){
                c=A[i];
                j=i;
            }
        }
        if(c!=-1)  A.erase(A.begin()+j);
        return c;
    }
};