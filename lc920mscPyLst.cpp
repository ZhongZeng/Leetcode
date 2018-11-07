
/*
Leetcode 920. Number of Music Playlists

Companies   
Coursera 

Next challenges: Serialize and Deserialize BST, Cherry PickupExam Room

Test Cases: 
2
3
0
3
3
1
4
7
2
16
16
4

Runtime: 0 ms
Your runtime beats 100.00 % of cpp submissions.

*/

class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
		// DP; 0 <= K < N <= L <= 100; O(N*L+K) time, O(1) space
        if(L<N||N<K)	return 0;
        int i, j;
        long t=1;
		vector<long> vc(N-K,0), vd(N-K,0);
		vc[0]=1;
		
		// 1st K+1 songs must be distinct: 2nd rule
		for( i=0; i<=K; i++)	vc[0]=vc[0]*(N-i)%1000000007;
		
		// L-K-1 songs; previous K+1 songs must be unque 
		for( ; i<L; i++){// vc[j]: list w/ i songs & j+K+1 unique songs 
            // for(auto e:vc)  cout<<e<<" ";   cout<<endl;
            vd.clear();
			vd.push_back(vc[0]);// same song 
			for( j=1; j<vc.size(); j++)	// diff+same song; 1st rule: can't choose from previous K 
                vd.push_back((vc[j-1]*(N-j-K)%1000000007+vc[j]*(j+1)%1000000007)%1000000007);
			vc=vd;
		}
        
        return vc.back();// 1st rule
    }
};
