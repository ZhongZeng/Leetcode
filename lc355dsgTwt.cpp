
/*
Leetcode 355. Design Twitter

Companies 
Amazon, Twitter 
Related Topics 
Hash Table, Heap, Design 

Test Cases:
["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]
[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]
["Twitter","postTweet","follow","getNewsFeed"]
[[],[1,5],[1,1],[1]]

Next challenges: Sudoku Solver, Copy List with Random Pointer, LFU Cache

Runtime: 37 ms
Your runtime beats 65.43 % of cpp submissions.

*/

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        t=0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {// O(1)
        unordered_map<int,vector<pair<int,int>>>::iterator twi=tw.find(userId);
        if(twi!=tw.end()){
            twi->second.push_back( make_pair(tweetId, t++));
        }else{
            vector<pair<int,int>> vc;
            vc.push_back( make_pair(tweetId, t++));
            tw.emplace( userId, vc);
        }
        return ;        
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {// O(n*lg(n))
        vector<int> rt;
        vector<pair<vector<pair<int,int>>::reverse_iterator,vector<pair<int,int>>::reverse_iterator>> hp;
        unordered_map<int,vector<pair<int,int>>>::iterator twi=tw.find(userId);
        if(twi!=tw.end())   pushHp(twi->second.rbegin(), twi->second.rend(), hp);
        
        unordered_map<int,unordered_set<int>>::iterator umi=um.find(userId);
        if(umi!=um.end()){
            for( unordered_set<int>::iterator usi=umi->second.begin(); usi!=umi->second.end(); usi++){
                if(*usi!=userId){// tricky: a user can follow itself
                    twi=tw.find(*usi);
                    if(twi!=tw.end())   pushHp(twi->second.rbegin(), twi->second.rend(), hp);
                }
            }
        }
        
        for( int i=0; i<10&&!hp.empty(); i++)   rt.push_back(popHp(hp));
        
        return rt;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {// O(1)
        unordered_map<int,unordered_set<int>>::iterator umi=um.find(followerId);
        if(umi!=um.end()){
            unordered_set<int>::iterator usi=umi->second.find(followeeId);
            if(usi==umi->second.end())  umi->second.emplace(followeeId);
        }else{
            unordered_set<int> us;
            us.emplace( followeeId);
            um.emplace( followerId, us);
        }
        return ;
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {// O(1)
        unordered_map<int,unordered_set<int>>::iterator umi=um.find(followerId);
        if(umi!=um.end()){
            unordered_set<int>::iterator usi=umi->second.find(followeeId);
            if(usi!=umi->second.end())  umi->second.erase(usi);
        }
        return ;        
    }
    
protected:    
    unordered_map<int,unordered_set<int>> um;// follower, followees 
    unordered_map<int,vector<pair<int,int>>> tw;// twitters: Id, time stamp 
    int t;
    
    void pushHp(vector<pair<int,int>>::reverse_iterator ib,vector<pair<int,int>>::reverse_iterator ie, 
                vector<pair<vector<pair<int,int>>::reverse_iterator,vector<pair<int,int>>::reverse_iterator>>& hp){
        // max heap w.r.t. timeStamp/second
        int i=hp.size();
        pair<vector<pair<int,int>>::reverse_iterator,vector<pair<int,int>>::reverse_iterator> pr;
        hp.push_back( make_pair(ib, ie) );
        
        while( 0<i ){
            if(hp[(i-1)/2].first->second<hp[i].first->second){
                pr=hp[i];
                hp[i]=hp[(i-1)/2];
                hp[(i-1)/2]=pr;
                i=(i-1)/2;
            }else{
                return ;
            }
        }
        
        return ;
    }
    
    int popHp( vector<pair<vector<pair<int,int>>::reverse_iterator, vector<pair<int,int>>::reverse_iterator>>& hp){
        //cout<<hp.size()<<endl;
        int r=hp[0].first->first, i=0;
        pair<vector<pair<int,int>>::reverse_iterator,vector<pair<int,int>>::reverse_iterator> pr;
        
        hp[0].first+=1;
        if( hp[0].first==hp[0].second ){
            hp[0]=hp.back();
            hp.pop_back();
        }
        
        while( 2*i+2<hp.size() ){
            if(hp[i].first->second<hp[2*i+1].first->second&&hp[2*i+2].first->second<hp[2*i+1].first->second){
                pr=hp[2*i+1];
                hp[2*i+1]=hp[i];
                hp[i]=pr;
                i=2*i+1;
            }else if(hp[i].first->second<hp[2*i+2].first->second){
                pr=hp[2*i+2];
                hp[2*i+2]=hp[i];
                hp[i]=pr;
                i=2*i+2;
            }else{
                break;
            }
        }
        
        if( 2*i+1<hp.size()&&hp[i].first->second<hp[2*i+1].first->second ){
            pr=hp[2*i+1];
            hp[2*i+1]=hp[i];
            hp[i]=pr;            
        }
        
        return r;
    }    
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */