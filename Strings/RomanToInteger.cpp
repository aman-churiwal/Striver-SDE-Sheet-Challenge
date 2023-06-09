class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int ans = 0;
        int i = n-1;
        while(i >= 0){
            if(i>0 && mp[s[i-1]] < mp[s[i]]){
                ans += mp[s[i]] - mp[s[i-1]];
                i = i-2;
            } else {
                ans += mp[s[i]];
                i--;
            }
        }
        return ans;
    }
};