class Solution {
public:
    bool isValid(int row, int col,vector<vector<int>>& grid )
    {
        
        return row>=0 && row<grid.size() && col>=0 && col<grid[0].size() && grid[row][col]!=0;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        
        bool flag1=false, flag2=false;
        for(int i=0;i<grid.size();++i)
        {
            
            for(int j=0; j< grid[0].size() ; ++ j)
            {
                
                if(grid[i][j]==1)
                {
                    flag1=true;
                    
                }
                if(grid[i][j]==2)
                    flag2=true;
                
            }
        }
        
        
        if(!flag1)
            return 0;
        else if(!flag2)
            return -1;
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<grid.size(); ++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    grid[i][j]=0;
                }
            }
        }
        
        int time=0;
        while(!q.empty())
        {
           int levelsize=q.size();
            cout<<levelsize<<" ";
            while(levelsize--){
            pair<int,int> temp=q.front();
            
            
            
            q.pop();
            
            int i=temp.first,j=temp.second;
            
            
            grid[i][j]=0;
            
            static int index[]={-1,0,1,0,-1};
            
            bool change=false;
            for(int k=0;k<4;++k)
            {       
                
           if(isValid(i+index[k], j+index[k+1], grid))
           {
                   grid[i+index[k]][j+index[k+1]]=0;
                   q.push({i+index[k], j+index[k+1]});
              
               
           }
              
           }
            
            }
            time++;
            
        }
        
        for(int i=0;i<grid.size();++i)
            for(int j=0;j<grid[0].size();++j)
                if(grid[i][j]==1)
                    return -1;
        
        
        return time-1;
    }
};
