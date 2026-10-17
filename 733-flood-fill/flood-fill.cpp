
class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc,
             int original, int color) {

        int m = image.size();
        int n = image[0].size();

        if (sr < 0 || sc < 0 || sr >= m || sc >= n)
            return;

        if (image[sr][sc] != original)
            return;

        image[sr][sc] = color;

        dfs(image, sr - 1, sc, original, color); // Up
        dfs(image, sr + 1, sc, original, color); // Down
        dfs(image, sr, sc - 1, original, color); // Left
        dfs(image, sr, sc + 1, original, color); // Right
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int original = image[sr][sc];

        if (original == color)
            return image;

        dfs(image, sr, sc, original, color);

        return image;
    }
};
