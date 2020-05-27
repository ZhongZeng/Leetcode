/*
1312. Minimum Insertion Steps to Make a String Palindrome

Related Topics	Dynamic Programming

Test Cases:
"eii"
"eiiw"
"zjveiiwvc"
"zzazz"
"mbadm"
"leetcode"
"g"
*/
/*
Runtime: 32 ms, faster than 95.90% of C++ online submissions for Minimum Insertion Steps to Make a String Palindrome.
Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for Minimum Insertion Steps to Make a String Palindrome.
*/
class Solution {
public:
    int minInsertions(string s) {
        // Dynamic Programming; O(n*n) time, O(n) space
        if(s.size()<1)  return 0;
        vector<int> vc={0};// vc[j]=minInsertions(s[k,i-1)) for k<j or minInsertions(s[k,i)) for j<k
        for( int i=1; i<=s.size(); i++){
			vc.push_back(0);// vc.size()==i+1
            for( int j=i-1, prev=0, cur; -1<j; j--, prev=cur){// [j,i)
                cur=vc[j];
                vc[j]+=1;// from s[j,i-1)
                if(vc[j+1]+1<vc[j]) vc[j]=vc[j+1]+1;// from s[j+1,i)
                if(s[j]==s[i-1]&&prev<vc[j])    vc[j]=prev;// from s[j+1,i-1)
            }
        }
        return vc[0];
    }
};

/*
Runtime: 164 ms, faster than 5.16% of C++ online submissions for Minimum Insertion Steps to Make a String Palindrome.
Memory Usage: 49.1 MB, less than 100.00% of C++ online submissions for Minimum Insertion Steps to Make a String Palindrome.
Runtime: 152 ms, faster than 5.16% of C++ online submissions for Minimum Insertion Steps to Make a String Palindrome.
Memory Usage: 49 MB, less than 100.00% of C++ online submissions for Minimum Insertion Steps to Make a String Palindrome.
Next challenges: 4 Keys Keyboard, Largest Sum of Averages, Minimum Number of Refueling Stops
*/
class Solution {
public:
    int minInsertions(string s) {
        // Dynamic Programming; O(n*n) time, O(n) space
        if(s.size()<1)  return 0;
        vector<int> vc={0};// vc[j]=minInsertions(s[j,i-1))
        for( int i=1; i<=s.size(); i++){
            vector<int> vd;// vd[j]=minInsertions(s[j,i)); overriding vc saves space
            for( int j=0; j<=i; j++)    vd.push_back(i-j);// initialization: copy entire s[j,i)
            for( int j=i-1; -1<j; j--){// [j,i)
                if(vc[j]+1<vd[j])   vd[j]=vc[j]+1;// from s[j,i-1)
                if(vd[j+1]+1<vd[j]) vd[j]=vd[j+1]+1;// from s[j+1,i)
                if(s[j]==s[i-1]){// from s[j+1,i-1)
                    if(j==i-1)  vd[j]=0;
                    else if(vc[j+1]<vd[j])   vd[j]=vc[j+1];
                }
            }
            vc=vd;// save space but increase time
        }
        return vc[0];
    }
};