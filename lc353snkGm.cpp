
/*
Leetcode 353. Design Snake Game

Companies 
Google
Related Topics 
Design, Queue 

Next challenges: Implement Queue using Stacks, 
Design Twitter, Design Phone Directory

Test Cases
["SnakeGame","move","move","move","move","move","move"]
[[3,2,[[1,2],[0,1]]],["R"],["D"],["R"],["U"],["L"],["U"]]
["SnakeGame","move","move","move","move","move","move","move","move","move","move","move","move"]
[[3,3,[[2,0],[0,0],[0,2],[2,2]]],["D"],["D"],["R"],["U"],["U"],["L"],["D"],["R"],["R"],["U"],["L"],["D"]]

Runtime: 187 ms
Your runtime beats 23.78 % of cpp submissions.

*/

class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    // Saw the Tag Queue
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        f=0;
        w=width;
        h=height;
        fd=food;
        move(0,0);
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int r=sn.back().first, c=sn.back().second;
        switch(direction[0]){
            case 'U': 
                if(sn.back().first<1)   return -1;
                r--;
                break;
            case 'D': 
                if(h-2<sn.back().first) return -1;
                r++;
                break;
            case 'L': 
                if(sn.back().second<1)  return -1;
                c--;
                break;
            case 'R': 
                if(w-2<sn.back().second)    return -1;
                c++;
                break;
        }
        
        if(r==fd[f].first&&c==fd[f].second) f++;
        else    popTail();

        if(move( r, c)) return -1;// this must be after popTail()
        
        return f;
    }
    
protected:     
    bool move(int r, int c){
        sn.push( make_pair(r, c));
        unordered_map<int, unordered_set<int>>::iterator umi=um.find(r);
        if(umi!=um.end()){
            if(umi->second.find(c)!=umi->second.end())  return true;
            else    umi->second.emplace(c);
        }else{
            unordered_set<int> us;
            us.emplace(c);
            um.emplace(r, us);
        }
        return false;
    }
    
    void popTail(){
        unordered_map<int, unordered_set<int>>::iterator umi=um.find(sn.front().first);
        if( 1<umi->second.size() )  umi->second.erase(umi->second.find(sn.front().second));
        else    um.erase(umi);
        sn.pop();
        return ;
    }
   
    int f, w, h;
    vector<pair<int, int>> fd;// food 
    queue<pair<int,int>> sn;// snake: back() head; front() tail
    unordered_map<int, unordered_set<int>> um;// snake
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
