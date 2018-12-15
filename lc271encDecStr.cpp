/*
271. Encode and Decode Strings

Related Topics: String 
Similiar Questions: Count and Say, Serialize and Deserialize Binary Tree, 
String Compression, Count Binary Substrings


Test Cases:
["q?6?^7z5*","2_`Gw+","_D4-.3","-z5PU2="]

Runtime: 64 ms, faster than 10.71% of C++ online submissions for Encode and Decode Strings.
Runtime: 60 ms, faster than 17.23% of C++ online submissions for Encode and Decode Strings.

*/

class Codec {
public:
    // Encodes a list of strings to a single string.
    // O(n) time
    string encode(vector<string>& strs) {
        string rt;
        
        for( int i=0; i<strs.size(); i++){
            rt.append(to_string(strs[i].size()));
            rt.push_back(' ');
            rt.append(strs[i]);
        }
        
        return rt;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> rt;
        for( int i=0; i<s.size(); ){
            int len=0;
            string t;
            for( ; s[i]!=' '; i++) len=len*10+s[i]-'0';
            
            for( i++; 0<len; len--, i++)   t.push_back(s[i]);
            rt.push_back(t);
        }
        return rt;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));