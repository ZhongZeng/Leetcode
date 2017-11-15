

/*
Leetcode 165. Compare Version Numbers

Related Topics 
String 

Next challenges: Longest Substring Without Repeating Characters, 
Restore IP Addresses, Longest Uncommon Subsequence II

Test Cases:
"13.34"
"3.3"
"1"
"0"
"01"
"1"
"1.1"
"1.10"
"0.1"
"0.0.1"
"1.1"
"1"
"1.0"
"1"
"0.9.9.9.9.9.9.9.9.9.9.9.9"
"1.0"
"19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.00.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000"
"19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000"

Runtime: 0 ms
You are here! 
Your runtime beats 45.87 % of cpp submissions.

*/

class Solution {
public:
    int compareVersion(string version1, string version2) {  
        return comVer( version1.begin(), version1.end(), version2.begin(), version2.end() );        
    }
    
protected:
    int comVer(string::iterator v1b, string::iterator v1e, string::iterator v2b, string::iterator v2e) {  
        trimZero( v1b, v1e );
        trimZero( v2b, v2e );
        
        int i1=0, i2=0;
        string::iterator si3=v1b, si4=v2b;
        
        /* integer length */
        while( *v1b!='.' && v1b!=v1e ){          
            i1++;
            v1b++;
        }  

        while( *v2b!='.' && v2b!=v2e ){
            i2++;
            v2b++;
        }  
                
        if( i1<i2 ){           
            return -1;
        }else if( i2<i1 ){
            return 1;
        }                      
        
        /* integer comparison */
        while( i1--!=0 ){
            if( *si3<*si4 ){
                return -1;
            }else if( *si4<*si3 ){
                return 1;
            }else{
                si3++;
                si4++;
            }
        }           
        
        /* decimal comparison */                      
        if( v1b!=v1e ){
            v1b++;
            if( v2b!=v2e ){
                v2b++;
                return comVer( v1b, v1e, v2b, v2e); 
            }else{
                return isZero( v1b, v1e );
            }                        
        }else{                       
            if( v2b!=v2e ){
                v2b++;
                return isZero( v2b, v2e ) ? -1 : 0;
            }else{
                return 0;
            }
        }                   
    }
    
    void trimZero( string::iterator & vb, string::iterator & ve ){ // triming preceding but not succeeding zeros
        while( vb!=ve && *vb=='0' ) vb++;
        
        if( *vb=='.' || vb==ve ) vb--;
                    
        return ;
    }
    
    int isZero( string::iterator vb, string::iterator ve ){
        while( vb!=ve ){
            if( *vb!='0' && *vb!='.' ){
                return 1;
            }
            vb++;
        }
        
        return 0;
    }
    
};


/*
// Solution II: Non-pointer Slow Solution
// Runtime: 3 ms
// You are here! 
// Your runtime beats 4.05 % of cpp submissions. 
class Solution {
public:
    int compareVersion(string version1, string version2) {  
        trimZero( version1 );
        trimZero( version2 );
        //cout<<version1<<' '<<version2<<endl;
        
        int i1=0, i2=0;
        string::iterator si1=version1.begin(), si2=version2.begin(), si3=version1.begin(), si4=version2.begin();        
        
        // Integer Length 
        while( *si1!='.' && si1!=version1.end() ){          
            i1++;
            si1++;
        }  

        while( *si2!='.' && si2!=version2.end() ){
            i2++;
            si2++;
        }  
                
        if( i1<i2 ){           
            return -1;
        }else if( i2<i1 ){
            return 1;
        }                      
        
        // Integer Comparison 
        while( i1--!=0 ){
            if( *si3<*si4 ){
                return -1;
            }else if( *si4<*si3 ){
                return 1;
            }else{
                si3++;
                si4++;
            }
        }           
        
        // Decimal Comparison 
        if( i2!=version1.size() ){
            version1 = version1.substr( i2+1, version1.size()-i2-1 );
            if( i2!=version2.size() ){
                version2 = version2.substr( i2+1, version2.size()-i2-1 );   
            }else{
                version2 = "0";
            }                        
        }else{                       
            if( i2!=version2.size() ){
                version1 = "0";
                version2 = version2.substr( i2+1, version2.size()-i2-1 );    
            }else{
                return 0;
            }             
        }
        
        return compareVersion(version1, version2);
    }
    
protected:
    void trimZero( string & s){ // triming preceding but not succeeding zeros
        string::iterator it = s.begin()-1;
        int i=0;
        while( ++it!=s.end() ){
            if( *it!='0' ){
                break;
            }else{
                i++;     
            }
        }
        
        if( *it!='.' && it!=s.end() ){
            s = s.substr( i, s.size()-i );            
        }else{
            s = s.substr( i-1, s.size()-i+1 );
        }
                    
        return ;
    }
    
};

*/