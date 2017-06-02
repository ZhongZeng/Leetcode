
/*
Leetcode 22. Generate Parentheses

You are here! 
Your runtime beats 2.56 % of cpp submissions.	19 ms
You are here! 
Your runtime beats 2.43 % of cpp submissions.	23 ms

Tags: Backtracking String
Similar Problems: (M) Letter Combinations of a Phone Number (E) Valid Parentheses
Next challenges: (M) Permutations II(H) Shortest Palindrome(M) Longest Uncommon Subsequence II

*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // cout<< isValidPar("(())") <<endl;
        vector<string> vs={""}, vs2;
        string s;
        for(int i=0; i!=2*n-1; i++){
            for(vector<string>::iterator vsi=vs.begin(); vsi!=vs.end(); vsi++){
                s=*vsi+'(';
                if( isValidPre(s)){ vs2.push_back(s);   } // cout<<s<<endl;
                s=*vsi+')';
                if( isValidPre(s)){ vs2.push_back(s);   } // cout<<s<<endl;
            }
            vs=vs2;
            vs2.clear();
        }
        
        for(vector<string>::iterator vsi=vs.begin(); vsi!=vs.end(); vsi++){
            s=*vsi+')'; // the last element can't be '('
            if( isValidPar(s)){ vs2.push_back(s);   } // cout<<"test"<<endl;
        }
        
        return vs2;
    }

protected:
    bool isValidPar(string s){// is a valid parathesis
        stack<int> st;
        for(string::iterator it=s.begin(); it!=s.end(); it++){
            if(*it=='('){
                st.push(1);
            }else if(!st.empty()){
                st.pop();
            }else{
                return false;
            }
        }
        return st.empty() ? true : false; // the only different part b/t isValidPar and isValidPre
    }
        
    bool isValidPre(string s){// is a valid prefix of valid parathesis
        stack<int> st;
        for(string::iterator it=s.begin(); it!=s.end(); it++){
            if(*it=='('){
                st.push(1);
            }else if(!st.empty()){
                st.pop();
            }else{
                return false;
            }
        }
        return true; // the only different part b/t isValidPar and isValidPre
    }
    
};


/* 
// Another Version: exactly same time - 19 ms

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // cout<< isValidPar("(())") <<endl;
        if(n==0) return {""};
        vector<string> vs={"("}, vs2;
        string s;
        for(int i=1; i!=n; i++){
            for(vector<string>::iterator vsi=vs.begin(); vsi!=vs.end(); vsi++){
                cout<<"test"<<endl;                
                s=*vsi+'(';
                if( isValidPre(s)){ vs2.push_back(s);   } // cout<<s<<endl;
                s=*vsi+')';
                if( isValidPre(s)){ vs2.push_back(s);   } // cout<<s<<endl;
            }
            vs.clear();
            for(vector<string>::iterator vsi=vs2.begin(); vsi!=vs2.end(); vsi++){
                s=*vsi+'(';
                if( isValidPre(s)){ vs.push_back(s);   } // cout<<s<<endl;
                s=*vsi+')';
                if( isValidPre(s)){ vs.push_back(s);   } // cout<<s<<endl;
            }
            vs2.clear();
        }
        
        for(vector<string>::iterator vsi=vs.begin(); vsi!=vs.end(); vsi++){
            s=*vsi+')'; // the last element can't be '('
            if( isValidPar(s)){ vs2.push_back(s);   } // cout<<"test"<<endl;
        }
        
        return vs2;
    }

protected:
    bool isValidPar(string s){// is a valid parathesis
        stack<int> st;
        for(string::iterator it=s.begin(); it!=s.end(); it++){
            if(*it=='('){
                st.push(1);
            }else if(!st.empty()){
                st.pop();
            }else{
                return false;
            }
        }
        return st.empty() ? true : false; // the only different part b/t isValidPar and isValidPre
    }
        
    bool isValidPre(string s){// is a valid prefix of valid parathesis
        stack<int> st;
        for(string::iterator it=s.begin(); it!=s.end(); it++){
            if(*it=='('){
                st.push(1);
            }else if(!st.empty()){
                st.pop();
            }else{
                return false;
            }
        }
        return true; // the only different part b/t isValidPar and isValidPre
    }
    
};

*/
