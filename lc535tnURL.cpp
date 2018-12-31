/*
535. Encode and Decode TinyURL

Related Topics: Hash Table, Math 

Runtime: 4 ms	Your runtime beats 99.12 % of cpp submissions.

*/

class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        db.push_back(longUrl);
        return convert2Str(db.size()-1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return db[covert2Num(shortUrl)];
    }
    
protected:
    long covert2Num( string& s){
        long rt=0;
        for( int i=0; i<s.size(); i++){
            rt+=(s[i]-'a')*64;
        }
        return rt;
    }
    
    string convert2Str( long n){// 64 base, more significant at back 
        string rt;
        for( ; 0<n; n=n>>6) rt.push_back((char)('a'+n%64));
        return rt;
    }
    
    vector<string> db;// data base
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));