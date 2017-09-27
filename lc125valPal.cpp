

/*
Leetcode 125. Valid Palindrome

Related Topics 
Two Pointers, String 
Similar Questions 
Palindrome Linked List, Valid Palindrome II 

Test Cases: 
"0P"
"1P"
"A man, a plan, a canal: Panama"
"z  Aca,Z"
"race a car"
"."

Runtime: 9 ms
You are here! 
Your runtime beats 26.97 % of cpp submissions.


*/


class Solution {
public:
    bool isPalindrome(string s) {
        // cout<< (int) ('a'-'A') <<endl; // 32
        // cout<< (int) ('0'-'A') <<endl; // -17
        // cout<< (int) ('9'-'A') <<endl; // -8        
		string::iterator b=s.begin()-1, e=s.end();
        int i;
        b = findNxB( b, e);
		e = findNxE( b, e);
        // cout<<*b<<' '<<*e<<endl;
        while ( b < e ) {      
            i = *b-*e; 
            // cout<<*b<<' '<<*e<<endl;     
			if( isNum(*b) || isNum(*e) ){
                if( i!=0 )  return false; 
            }else{
                if( i!=0 && i!=32 && i!=-32 )   return false;
            }
            b = findNxB( b, e); 
			e = findNxE( b, e); 
		}
        return true;
    }
	
protected:
	string::iterator findNxB( string::iterator b, string::iterator e ){
        b++; 
		while( b<e && isSep(*b) )	b++; 
		return b; 
	}
	
	string::iterator findNxE( string::iterator b, string::iterator e ){
        e--;
		while( b<e && isSep(*e) )	e--; 
		return e; 
	}

    bool isSep(char c){
        // is special character
		int i=c-'A';
        if( i<-17){
            return true;
        }else if( -8<i && i<0 ){
            return true;
        }else if( 25<i && i<32 ){
			return true;
		}else if( 57<i){
			return true;
		}			
		return false;
	}
    
	bool isNum(char c){
        // is number
		int i=c-'A'; 
        if( -18<i && i<-7 ){
            return true; 
        }else{
            return false; 
        }   
	}        
    
	bool isLetter(char c){
        // is English letter
		int i=c-'A';
        if( i<0 ){
			return false;
		}else if( 25<i && i<32 ){
			return false;
		}else if( 57<i){
			return false;
		}			
		return true;
	}    
	
};

