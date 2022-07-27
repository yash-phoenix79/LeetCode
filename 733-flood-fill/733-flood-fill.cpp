class Solution {
public:
    
    void fill(vector<vector<int>>& image,int sr,int sc,int newColor,int col,int n,int m){
        if(sr<0||sr>=n||sc<0||sc>=m||image[sr][sc]!=col)
            return;
        
        image[sr][sc]=newColor;
         fill(image,sr+1,sc,newColor,col,n,m);
         fill(image,sr-1,sc,newColor,col,n,m);
         fill(image,sr,sc+1,newColor,col,n,m);
         fill(image,sr,sc-1,newColor,col,n,m);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int col=image[sr][sc];
        int n=image.size(),m=image[0].size();
        
        if(col==newColor)
        return image;
        
        fill(image,sr,sc,newColor,col,n,m);
        return image;
    }
};