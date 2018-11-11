
/*
Leetcode 937. Reorder Log Files

Runtime: 12 ms

*/

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> lt, nu;
        
        for( int i=0; i<logs.size(); i++){
            if(isLetter(logs[i]))   lt.push_back(logs[i]);
            else    nu.push_back(logs[i]);
        }
        
        sort( lt.begin(), lt.end(), compare);
        
        for( int i=0; i<nu.size(); i++) lt.push_back(nu[i]);
        
        return lt;
    }
    
protected:
    static int findId(string& s1){
        for( int i=0; i<s1.size(); i++)    if(s1[i]==' ')  return i+1;
        return -1;
    }
    
    static bool compare(string& s1, string& s2){// return s1<s2
        int id1=findId(s1), id2=findId(s2), i1, i2;
        for( i1=id1, i2=id2; i1<s1.size()&&i2<s2.size(); i1++, i2++){
            if(s1[i1]<s2[i2])   return true;
            else if(s2[i2]<s1[i1])  return false;
        }
        if(i1<s1.size())    return true;
        else if(i2<s2.size())   return false;
        
        for( i1=0, i2=0; i1<id1&&i2<id2; i1++, i2++){
            if(s1[i1]<s2[i2])   return true;
            else if(s2[i2]<s1[i1])  return false;
        }
        if(i1<id1)  return true;
        else if(i2<id2)   return false;
        
        return false;
    }
    
    bool isLetter(string& s){// O( length of 1st word in s)
        int i=0, t;
        while( ++i<s.size() ){
            if(s[i]==' ')   break;
        }
        while( ++i<s.size() ){
            t=s[i]-'0';
            if(-1<t&&t<10)  return false;
            else    return true;
        }
        return true;
    }
};
