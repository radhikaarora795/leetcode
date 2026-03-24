#include <iostream>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image, int i,int j,int orgColour,int newColour){
        
        int m=image.size();
        int n=image[0].size();
        if(i<0 || j<0 || i>=m || j>=n || image[i][j]!=orgColour || image[i][j]==newColour){
            return;
        }
        image[i][j]=newColour;
        dfs(image,i-1,j,orgColour,newColour);
        dfs(image,i,j-1,orgColour,newColour);
        dfs(image,i+1,j,orgColour,newColour);
        dfs(image,i,j+1,orgColour,newColour);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
};

int main() {
    
    return 0;
}