class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size() , m = matrix[0].size();
        int sr = 0 , er = n-1 , sc = 0 , ec = m-1;
        while(sr <= er && sc <= ec){
            // top
            for(int i = sc ; i <= ec ;i++){
                ans.push_back(matrix[sr][i]);
            }
            //right
            for(int i = sr + 1; i <= er;i++){
                ans.push_back(matrix[i][ec]);
            }
            //bottom
            for(int j = ec - 1; j >= sc; j--){
                if(sr == er){
                    break;
                }
                ans.push_back(matrix[er][j]);
            }
            //left
            for(int k = er - 1; k > sr ; k--){
                if(sc == ec){
                    break;
                }
                ans.push_back(matrix[k][sc]);
            }
            sc++ , sr++ , ec-- , er--;
        }
    return ans;
    }
};