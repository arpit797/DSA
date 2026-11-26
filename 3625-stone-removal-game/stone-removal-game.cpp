class Solution {
public:
    bool canAliceWin(int n) {
        if (n < 10) return false;

        int turn = 10;
        bool alice = true;

        while (n >= turn) {
            n -= turn;
            turn--;

            alice = !alice;
        }

        return !alice;
    }
};