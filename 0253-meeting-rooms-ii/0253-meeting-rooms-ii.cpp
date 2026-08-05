class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        int n = intervals.size();

        for(int i = 0; i < n; i++) {
            pq.push({intervals[i][0], intervals[i][1]});
        }

        priority_queue<int, vector<int>, greater<int>> rooms;

        while(!pq.empty()) {

            int start = pq.top().first;
            int end = pq.top().second;
            pq.pop();

            if(!rooms.empty() && rooms.top() <= start){
                rooms.pop();
            }

            rooms.push(end);
        }

        return rooms.size();
    }
};