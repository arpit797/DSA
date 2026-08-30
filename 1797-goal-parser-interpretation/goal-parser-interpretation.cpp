class Solution {
public:
    string interpret(string s) {
        string ans = "";

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == 'G') {
                ans += 'G';
            }

            else if(s[i] == '(' && s[i + 1] == ')') {
                ans += 'o';
                i++;  // () ke dono characters skip
            }

            else if(s[i] == '(' && s[i + 1] == 'a') {
                ans += "al";
                i += 3;  // (al) ke remaining characters skip
            }
        }

        return ans;
    }
};