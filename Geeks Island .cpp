Menu






























































Geeks Island
MediumAccuracy: 81.22%Submissions: 4K+Points: 4
Lamp
Don't Let the Fear of Missing Out Hold You Back from a Lucrative Career in Data Science. Try this course!

Geeks Island is represented by an N * M matrix mat. The island is touched by the Indian Ocean from the top and left edges and the Arabian Sea from the right and bottom edges. Each element of the matrix represents the height of the cell.

Due to the rainy season, the island receives a lot of rainfall, and the water can flow in four directions(up, down, left, or right) from one cell to another one with height equal or lower.

You need to find the number of cells from where water can flow to both the Indian Ocean and the Arabian Sea.

Example 1:

Input:
N = 5, M = 5
mat[][] =    {{1, 3, 3, 2, 4},
               {4, 5, 6, 4, 4},
               {2, 4, 5, 3, 1},
               {6, 7, 1, 4, 5},
               {6, 1, 1, 3, 4}}
Output:
8
Explanation:
Indian    ~   ~   ~   ~   ~
Ocean  ~  1   3   3   2  (4) *
        ~  4   5  (6) (4) (4) *
        ~  2   4  (5)  3   1  *
        ~ (6) (7)  1   4   5  *
        ~ (6)  1   1   3   4  *           
           *   *   *   *   * Arabian Sea
Water can flow to both ocean and sea from the cells
denoted by parantheses().For example at index(1,2), the height of that island is 6. If a water drop falls on that island, water can flow to up direction(as 3<=6) and reach to Indian Ocean. ALso, water can flow to right direction(as 6>=4>=4) and reach to Arabian Sea.
Example 2:

Input:
N = 3, M = 2
mat[][] =    {{1, 1, 1},
               {1, 1, 1}}
Output:
6 
Explanation:
Water can flow from all cells to both Indian Ocean and Arabian Sea as the height of all islands are same.
Your Task:

Your task is to complete the function water_flow() which takes an integer array mat, integer N and integer M as the input parameter and returns an integer, denoting the number of cells from which water can to both ocean and sea.

Expected Time Complexity : O(N*M)
Expected Auxiliary Space : O(N*M)

Constraints:

1 <= N, M <= 103
1 <= mat[i][j] <= 106




***************************************

class Solution{   
public:
    void solve(vector<vector<int>>&mat,int i, int j, vector<vector<int>>&vis, int n, int m)
    {
        if(i<0 or j<0 or i>n or j>m or vis[i][j])return;
        
        vis[i][j]=1;
        if(i>0 and mat[i-1][j]>=mat[i][j])
        {
            solve(mat,i-1,j,vis,n,m);
        }
        if(i<n-1 and mat[i+1][j]>=mat[i][j])
        {
            solve(mat,i+1,j,vis,n,m);
        }
        if(j>0 and mat[i][j-1]>=mat[i][j])
        {
            solve(mat,i,j-1,vis,n,m);
        }
        if(j<m-1 and mat[i][j+1]>=mat[i][j])
        {
            solve(mat,i,j+1,vis,n,m);
        }
    }
    int water_flow(vector<vector<int>> &mat,int N,int M){
    // Write your code here.
        vector<vector<int>>indian(N,vector<int>(M,0));
        vector<vector<int>>arabian(N,vector<int>(M,0));
        
        for(int i=0;i<N; i++)
        {
            if(!indian[i][0])
            {
                solve(mat,i,0,indian,N,M);
            }
        }
        
        for(int j=0; j<M; j++)
        {
            if(!indian[0][j])
            {
                solve(mat,0,j,indian,N,M);
            }
        }
        
        for(int i=0;i<N; i++)
        {
            if(!arabian[i][M-1])
            {
                solve(mat,i,M-1,arabian,N,M);
            }
        }
        
        for(int j=0;j<M; j++)
        {
            if(!arabian[N-1][j])
            {
                solve(mat,N-1,j,arabian,N,M);
            }
        }
        
        int count=0;
        
        for(int i=0;i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(indian[i][j]==1 and arabian[i][j]==1)
                {
                    count++;
                }
            }
        }
        
        return count;
    }
};
