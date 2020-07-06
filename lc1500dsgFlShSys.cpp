/*
1500. Design a File Sharing System

Medium
Companies	Twitch
Related Topics	Array
Similar Questions Design Twitter

 "The user with userID will leave the system, you cannot take file chunks from them anymore."
 You can still access the file if that file is owned by other users who didn't leave. 
 
["FileSharing","join","request","request","request","request","join","request","request","join","request","request","join","join","request","request","request","request","join","join","request","leave","leave","join","request","leave","request","leave","join","join","request","leave","request","request","request","leave","join","join","leave","join","request","request","request","leave","request","request","request","request","join","join","leave","request","request","request","request","join","join","request","request","request","request","join","request","leave","request","request","leave","leave","join","request","request","request","request","request","request","leave","join","request","request","join","leave","request","leave","join","leave","leave","request","leave","request","request","leave","request","request","request","join","request","join","request","request"]
[[212],[[51,31,82,42,154,68,180,187,17,73,15,149,69,58,195,193,43]],[1,3],[1,152],[1,37],[1,14],[[70,15,10,16,80,103,97,73,147,153,148,181,26,17,135,142]],[1,123],[1,98],[[45,67]],[3,144],[1,48],[[99,152,87,211,179,148,1,104,128]],[[212,207,53,187]],[4,101],[4,132],[3,34],[3,34],[[127,15]],[[179,68,186,30,150,62]],[2,184],[1],[2],[[60,27,48,11,201,57,64,159,42,122,162]],[6,117],[5],[3,44],[7],[[159]],[[72,155,106]],[6,116],[2],[3,96],[6,8],[1,16],[6],[[88,84,165,164,116,135]],[[172,177,128,147,16,9,134,198,62,86,32,59,200]],[6],[[194,101,162,16,166,90,211,120,200,150,119,64,208,145,20,195,130,122,203,126]],[2,167],[1,41],[5,7],[3],[6,210],[1,169],[1,151],[1,202],[[188,142]],[[52,78,175,201,67,16,210,45,142,101]],[2],[6,115],[7,63],[1,148],[6,196],[[196,179,166,12,59,90,85]],[[129,35,210,17,156,126,92,89,90,26,122,202,3,157]],[4,25],[4,129],[8,88],[3,86],[[154,185,119,57,74,80,21,178,130,125,48,159,205,112,209,110,104,26,42,181]],[4,31],[9],[3,82],[3,141],[6],[8],[[31,203,74,33,78,23,162,96,132,44,49,62,143,54,155,186,170,70,112,201,97,180,20,36]],[7,44],[1,102],[1,210],[5,23],[2,206],[2,130],[5],[[40,169,154,37,190,49,130,191,42,121,193,95,201,149,28,54,168,57,38,15,171,26,97,50,199,195,100,135,21,134]],[4,208],[5,100],[[94,31,115,158,209,192,151,106,154,212,109,96,15,152,153,133,107,191,122,64,63,13,39,21,77,7,149,76]],[3],[6,89],[8],[[120,135,5]],[2],[3],[6,110],[1],[4,175],[5,204],[5],[4,10],[4,109],[7,122],[[162,18,188,163,98,123,196,58,7,77,34,45,29,119,206,126,19,13,189,186,153,149,174,26,166,55,54,117]],[6,196],[[76,110,200,86,13,165,137,173,24,141,8,146,212,23,128,60,203,41,33,36,144]],[6,90],[6,31] ]
["FileSharing","join","request","request","request","request","join","request","request","join","request","request","join","join","request","request","request","request","join","join","request","leave","leave","join","request","leave","request","leave","join","join","request","leave","request","request","request","leave","join","join","leave","join","request","request","request","leave","request","request","request","request","join","join","leave","request","request","request","request","join","join","request","request","request","request","join","request","leave","request","request","leave","leave","join","request","request","request","request","request","request","leave","join","request","request","join","leave","request","leave","join","leave","leave","request","leave","request","request","leave","request","request","request","join","request","join","request","request","join","request","request","request","leave","request","request","request","join","leave","request","join","request","join","request","join","join","join","join","request","join","leave","request","request","request","join","request","leave","request","join","join","leave","join","join","request","leave","request","join","request","request","request","leave","join","request","leave","leave","join","join","request","request","leave","request","leave","request","request","join","leave","request","join","request","request","request","join","join","join","request","join","request","join","join","join","leave","request","request","join","join","join","request","join","join","request","request","join","request","request","request","join","leave","request","request","request","leave","join","request","join","request","request","request","leave","join","join","join","request","join","request","join","request","request","join","leave","join","request","request","leave","request","request","request","join","leave","request","request","request","request","leave","request","request","join","leave","request","join","request","join","join","request","join","join","request","request","leave","request","join","request","request","leave"]
[[212],[[51,31,82,42,154,68,180,187,17,73,15,149,69,58,195,193,43]],[1,3],[1,152],[1,37],[1,14],[[70,15,10,16,80,103,97,73,147,153,148,181,26,17,135,142]],[1,123],[1,98],[[45,67]],[3,144],[1,48],[[99,152,87,211,179,148,1,104,128]],[[212,207,53,187]],[4,101],[4,132],[3,34],[3,34],[[127,15]],[[179,68,186,30,150,62]],[2,184],[1],[2],[[60,27,48,11,201,57,64,159,42,122,162]],[6,117],[5],[3,44],[7],[[159]],[[72,155,106]],[6,116],[2],[3,96],[6,8],[1,16],[6],[[88,84,165,164,116,135]],[[172,177,128,147,16,9,134,198,62,86,32,59,200]],[6],[[194,101,162,16,166,90,211,120,200,150,119,64,208,145,20,195,130,122,203,126]],[2,167],[1,41],[5,7],[3],[6,210],[1,169],[1,151],[1,202],[[188,142]],[[52,78,175,201,67,16,210,45,142,101]],[2],[6,115],[7,63],[1,148],[6,196],[[196,179,166,12,59,90,85]],[[129,35,210,17,156,126,92,89,90,26,122,202,3,157]],[4,25],[4,129],[8,88],[3,86],[[154,185,119,57,74,80,21,178,130,125,48,159,205,112,209,110,104,26,42,181]],[4,31],[9],[3,82],[3,141],[6],[8],[[31,203,74,33,78,23,162,96,132,44,49,62,143,54,155,186,170,70,112,201,97,180,20,36]],[7,44],[1,102],[1,210],[5,23],[2,206],[2,130],[5],[[40,169,154,37,190,49,130,191,42,121,193,95,201,149,28,54,168,57,38,15,171,26,97,50,199,195,100,135,21,134]],[4,208],[5,100],[[94,31,115,158,209,192,151,106,154,212,109,96,15,152,153,133,107,191,122,64,63,13,39,21,77,7,149,76]],[3],[6,89],[8],[[120,135,5]],[2],[3],[6,110],[1],[4,175],[5,204],[5],[4,10],[4,109],[7,122],[[162,18,188,163,98,123,196,58,7,77,34,45,29,119,206,126,19,13,189,186,153,149,174,26,166,55,54,117]],[6,196],[[76,110,200,86,13,165,137,173,24,141,8,146,212,23,128,60,203,41,33,36,144]],[6,90],[6,31],[[14,150,190,32,166,138,101,97,53,137,88,145,111,35]],[2,60],[7,159],[4,64],[2],[6,177],[4,49],[3,39],[[105,74,146,116,198,106,130,139,138,151,107,197,11,114,48,66,99,185,5,122,158,68]],[1],[2,184],[[94,22,189,98,196,18,128,40,163,111,198,102,105,109,45,122,76,177,125]],[1,154],[[99,48,153,105,14,137,210,32,21,131,2,200,94,159,60,50,53,44,196,207,135]],[4,109],[[90,64,139,107,147,131,86,112,103,57,91,114,62,88,180,115,1,33,32,181,98,140,48,30,148]],[[69,185,144,131,95,73,82,16,13,133,24,2,105,192,98,89,48,50,83,3,204]],[[51,70,184,127,102,176,111,31,28,199,202,183,119,138,79,168,26,48,209,6,166,16,62,61]],[[47,69,82,204,107,112,64,168]],[3,44],[[155,146,107]],[12],[1,60],[4,187],[5,212],[[9,147]],[12,107],[8],[1,84],[[77,196,87,82,1]],[[]],[10],[[203,164,18,59,113,204,77,41,158,35,34,210,206,128,172,10,75,79,194,183]],[[84,79,124,188,93,98,109,129,201,70,209,150,65,191,177,57,161,158,198,128,8,49,82]],[7,41],[3],[4,9],[[147,186,97,150,181,90,187,74,207]],[10,35],[3,188],[5,195],[2],[[45,127,65,131,204,143,11,16,7,57,63,106,174,8,165,207,162,142,176,15,151,149,97,33,12,46,87,114,43,40]],[1,41],[1],[13],[[]],[[104,180,81,152,123,45,5,167,174,193]],[11,199],[8,178],[12],[1,132],[4],[8,149],[7,106],[[137,202,140,128,15,39,41,32,86,83,120,207,153,164,157,112,160,105,133,109,161,64,211,125,97,53,7,26]],[8],[1,79],[[86,175,105,165,194,198,148,120,208,159,101,60,177,180,68,201,74,125,92,109,5,79,114]],[2,201],[13,110],[9,28],[[62,17,61,185,22,27,187,124,193,46,90,111,103,175,106]],[[9,1,77,178,73,164,140,70]],[[11,27,113,12,82,181,139,22,31,35,137,14,3,30,159,172,111,50,204,133,102,104,180,201,123,193,95,161,17]],[12,162],[[176,48,191,17,21,44,73,47,198,10,211,32,193,37,157]],[2,109],[[189,101,184,37,82]],[[123,11,189]],[[50,194,198,102,27,125,197,150]],[6],[7,77],[19,52],[[203,126,211,1,179,8,199,133,78,19,95,148,30,76,106,149,28,108,141]],[[191,82,166,24,186,47,139,137,71,10,177,173,8,89,202,206,61,97,205,107,190,135]],[[118,198,3,50,31,42,87,85,9,157,16,127,187,166,104,93,192,210,150,51,70,154,149,143,153,101,95]],[21,159],[[166,70,12,31,8,121,86,123,54,33,28,117,160,88,189,6,81,75,177,4,48,57,27,83]],[[204,101]],[14,82],[14,169],[[127,183,85,196,69,174,112,143,75,170,189,120,195,17,96,63,139,95,209,138]],[1,211],[8,147],[1,98],[[125,97,26,30,87]],[2],[18,134],[6,177],[8,1],[25],[[115,56,44,21,94,129,205,139,158,172,165,181,176,32,203,50,160,43,95,66,175,46]],[8,58],[[42,211,151,202,181,6,163,85,127,96,186,170,59,25,109,112,61,51,64,89,60,205,73,153,110,39,128]],[2,170],[2,16],[16,41],[15],[[12,29,146,52,59,143,14,38,165,132,118,171,205,70,55,6,68,133,16,31,184,67,9,41,5,21,182]],[[58,87,105,190,192,92,156,16,211]],[[191,62,180,104,94,54,14,9,50,31,192,61]],[6,112],[[49,3,34]],[5,209],[[194,175,69,73,138,47,13,65,99,88,193,20,202,207,58,204,137]],[24,81],[4,32],[[10,36,124,187,88,26,44,95,153,152,66,201,82,68,19,28,174,150,16,135,120,188,65,14,181]],[19],[[207,79,73,156,38,155,168]],[7,1],[2,210],[16],[2,157],[30,189],[1,171],[[6,164,127,26,43,98,102,54,73,70,117,188,63,82,25,139]],[13],[3,143],[4,134],[11,136],[31,122],[21],[29,107],[28,100],[[148,48,51,1,128,158,44,115,9,125,117,113,197,145,79,16,130,10,101]],[2],[14,113],[[208,134,23,111,63,119,115,15,67,77,151,30,204,147,36,143,170,191,89,28,85,4,87,88,161,172,139,62,202]],[16,170],[[61,92,18,106,182,21,190,154,102,184,185,73]],[[71,142,33,73,72,140,157,159,184]],[31,9],[[142,194,35,171,73,188,110,145,61,114,100,49,158,113,33,159,29,52,187]],[[109,14,189,135,197,87,80,15,62]],[23,195],[7,114],[9],[26,31],[[46,126,97,84,1,42,13,151,62]],[26,132],[11,176],[32]]
["FileSharing","join","join","join","join","join","request","request","request","request","request","request","request","request","request","request","request"]
[[17],[[]],[[6,8,7,15,16,9,10,4,13,12,5,14,1,11,2,17,3]],[[9,11,14,16,10,6,1,15,12]],[[]],[[17,10,16]],[1,6],[1,1],[1,13],[5,15],[3,5],[2,5],[1,4],[1,7],[2,15],[3,5],[2,1]]
["FileSharing","join","join","join","join","join","request","request","request","request","request"]
[[9],[[9,1,8,2,4,5,7,3,6]],[[7,8,9]],[[7,8,3,9,5,1,2,4,6]],[[2,9]],[[]],[1,4],[3,3],[4,8],[2,7],[2,7]]
["FileSharing","join","join","join","request","request","leave","request","leave","join"]
[[4],[[1,2]],[[2,3]],[[4]],[1,3],[2,2],[1],[2,3],[2],[[]]]
*/

/*
Runtime: 1312 ms, faster than 22.05% of C++ online submissions for Design a File Sharing System.
Memory Usage: 138.6 MB, less than 100.00% of C++ online submissions for Design a File Sharing System.
Next challenges:	Design Twitter

Runtime: 1116 ms, faster than 31.50% of C++ online submissions for Design a File Sharing System.
Memory Usage: 138.5 MB, less than 100.00% of C++ online submissions for Design a File Sharing System.

https://leetcode.com/problems/design-a-file-sharing-system/discuss/721940/Three-Hash-Tables
*/
class FileSharing {
public:
    FileSharing(int m) {
        min_id=1;
    }
    
    int join(vector<int> ownedChunks) {
        for( ; user_ids.find(min_id)!=user_ids.end(); min_id++){}
        user_ids.emplace(min_id);
        
        for( int i=0; i<ownedChunks.size(); i++){
            unordered_map<int,unordered_set<int>>::iterator it=file_user.find(ownedChunks[i]);
            if(it!=file_user.end()) it->second.emplace(min_id);
            else    file_user[ownedChunks[i]]={min_id};
        }
        
        user_file[min_id]=vecToSet(ownedChunks);
        
        return min_id++;
    }
    
    void leave(int userID) {
        user_ids.erase(userID);
        min_id=min_id<userID?min_id:userID;
        
        unordered_map<int,unordered_set<int>>::iterator it=user_file.find(userID);
        if(it==user_file.end()) return ;
        for( unordered_set<int>::iterator jt=it->second.begin(); jt!=it->second.end(); jt++)
            file_user.find(*jt)->second.erase(userID);
        
        user_file.erase(userID);
        
        return ;
    }
    
    vector<int> request(int userID, int chunkID) {
        unordered_map<int,unordered_set<int>>::iterator it=file_user.find(chunkID);
        if(it==file_user.end()) return  {};
        vector<int> vc=setToVec(it->second);
        sort( vc.begin(), vc.end());
        
        if(!vc.empty()){
            user_file[userID].emplace(chunkID);
            file_user[chunkID].emplace(userID);
        }// no one has file chunkID
        
        return vc;
    }
    
protected:
    unordered_map<int,unordered_set<int>> file_user;
    unordered_map<int,unordered_set<int>> user_file;
    unordered_set<int> user_ids;
    int min_id;
    
    vector<int> setToVec(unordered_set<int> & us){
        vector<int> vc;
        for( unordered_set<int>::iterator it=us.begin(); it!=us.end(); it++)
            vc.push_back(*it);
        return vc;
    }
    
    unordered_set<int> vecToSet(vector<int> & vc){
        unordered_set<int> us;
        for( int i=0; i<vc.size(); i++) us.emplace(vc[i]);
        return us;
    }
};

/*
Runtime: 1160 ms, faster than 29.92% of C++ online submissions for Design a File Sharing System.
Memory Usage: 138.4 MB, less than 100.00% of C++ online submissions for Design a File Sharing System.
Next challenges:	Design Twitter
*/
struct lessThan{
    bool operator()( int a, int b){
        return a>b;
    }
};

class FileSharing {
public:
    FileSharing(int m) {
        num_users=0;
    }
    
    int join(vector<int> ownedChunks) {
		int id;
        num_users++;
        if(user_ids.empty()){
			id=num_users;
		}else{
			id=user_ids.top();
			user_ids.pop();
		}
        
        for( int i=0; i<ownedChunks.size(); i++){
            unordered_map<int,unordered_set<int>>::iterator it=file_user.find(ownedChunks[i]);
            if(it!=file_user.end()) it->second.emplace(id);
            else    file_user[ownedChunks[i]]={id};
        }
        
        user_file[id]=vecToSet(ownedChunks);
        
        return id;
    }
    
    void leave(int userID) {
        user_ids.push(userID);
		num_users--;
        
        unordered_map<int,unordered_set<int>>::iterator it=user_file.find(userID);
        if(it==user_file.end()) return ;
        for( unordered_set<int>::iterator jt=it->second.begin(); jt!=it->second.end(); jt++)
            file_user.find(*jt)->second.erase(userID);
        
        user_file.erase(userID);
        
        return ;
    }
    
    vector<int> request(int userID, int chunkID) {
        unordered_map<int,unordered_set<int>>::iterator it=file_user.find(chunkID);
        if(it==file_user.end()) return  {};
        vector<int> vc=setToVec(it->second);
        sort( vc.begin(), vc.end());
        
        if(!vc.empty()){
            user_file[userID].emplace(chunkID);
            file_user[chunkID].emplace(userID);
        }// no one has file chunkID
        
        return vc;
    }
    
protected:
    unordered_map<int,unordered_set<int>> file_user;
    unordered_map<int,unordered_set<int>> user_file;
    priority_queue<int,vector<int>,lessThan> user_ids;
    int num_users;
    
    vector<int> setToVec(unordered_set<int> & us){
        vector<int> vc;
        for( unordered_set<int>::iterator it=us.begin(); it!=us.end(); it++)
            vc.push_back(*it);
        return vc;
    }
    
    unordered_set<int> vecToSet(vector<int> & vc){
        unordered_set<int> us;
        for( int i=0; i<vc.size(); i++) us.emplace(vc[i]);
        return us;
    }
};