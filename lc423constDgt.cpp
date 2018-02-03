

/*
Leetcode 423. Reconstruct Original Digits from English

Related Topics 
Math

Next challenges: Strobogrammatic Number III, Smallest Good Base, Cracking the Safe

Test Cases:
"owoztneoer"
"zerozero"
"zeroonetwothreefourfivesixseveneightnine"

Runtime: 30 ms
Your runtime beats 45.70 % of cpp submissions.

*/

class Solution {
public:
    string originalDigits(string s) {
        // O(n) time
        // the idea is interersting, but implementation is easy 
        string st;
        vector<int> vc(26,0), nm(10,0);
        
        for(int i=0; i<s.size(); i++){
            vc[s[i]-'a']+=1;
        }
        
        // 1st round
        nm[0]+=vc[25];//'z'
        nm[1]+=vc[14]-vc[25]-vc[22]-vc[20];//'o'-'z'_zero-'w'_two-'u'_four
        nm[2]+=vc[22];//'w'
        nm[3]+=vc[19]-vc[22]-vc[6];//'t'-'w'_two-'g'_eight
        nm[4]+=vc[20];//'u'
        nm[5]+=vc[5]-vc[20];//'f'-'u'_four
        nm[6]+=vc[23];//'x'
        nm[7]+=vc[18]-vc[23];//'s'-'s'_six
        nm[8]+=vc[6];//'g'
        nm[9]+=(vc[13]-nm[1]-nm[7])/2;//'n'-one-seven
        
        //for(auto ele:nm)    cout<<ele<<" "; cout<<endl;
        
        for(int i=0; i<nm.size(); i++){
            for(int j=0; j<nm[i]; j++)  st.append(to_string(i));
        }
        
        return st;
    }
};