class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int score = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                st.push(score);
                score = 0;
            }
            else {
                int prev = st.top();
                st.pop();

                if (s[i - 1] == '(') {
                    score = prev + 1;
                }
                else {
                    score = prev + 2 * score;
                }
            }
        }

        return score;
    }
};