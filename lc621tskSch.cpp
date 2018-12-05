
/*
621. Task Scheduler

Related Topics: Array, Greedy, Queue 
Similiar Questions: Rearrange String k Distance Apart, Reorganize String

Runtime: 60 ms
Your runtime beats 36.04 % of cpp submissions.

*/

struct comp{
	bool operator()(pair<char,int>& p1, pair<char,int>& p2){
		return p1.second<p2.second;
	}
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
		// O(m*log(n)) time 
		int rt=0, c=tasks.size();
		pair<char,int> pr;// task name, remaing # 
        priority_queue<pair<char,int>,vector<pair<char,int>>,comp> pq;// max on top 
		queue<pair<char,int>> qu;
		unordered_map<char,int> um;
		unordered_map<char,int>::iterator umi;
		
		for( int i=0; i<tasks.size(); i++){// count tasks 
			umi=um.find(tasks[i]);
			if(umi!=um.end())	umi->second+=1;
			else	um.emplace(tasks[i],1);
		}
		
		for( umi=um.begin(); umi!=um.end(); umi++)	pq.push(make_pair(umi->first, umi->second));
		
		for( int i=0; i<=n; i++)	qu.push(make_pair('a',0));// construct initial queue 
		
		for( ; 0<c; rt++){// arrange tasks; qu.size()==n guranteed 
			pr=qu.front();
			qu.pop();
			if(0<pr.second) pq.push(pr);
			
			if(!pq.empty()){
                c--;
				pr=pq.top();
				pr.second-=1;
				pq.pop();
				qu.push(pr);
                //cout<<pr.first<<","<<pr.second<<" ";
			}else{
				qu.push(make_pair('a',0));
			}
		}
		
		return rt;
    }
};
