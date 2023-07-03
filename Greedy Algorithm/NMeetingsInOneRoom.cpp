class Solution{

private:
    static bool comp(pair<int, int>& a, pair<int, int>& b){
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
    
    public:
    //Function to find the maximum number of meetings that can
    /be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> time;
        for(int i=0; i<n; i++) time.push_back({start[i], end[i]});
        
        sort(time.begin(), time.end(), comp);
        int ans = 1;
        auto lastMeeting = time[0];
        for(int i=1; i<n; i++){
            if(time[i].first > lastMeeting.second){
                ans++;
                lastMeeting = time[i];
            }
        }
        return ans;
    }
};