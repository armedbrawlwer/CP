#include<vector>
#include<algorithm>
int solverec(int n,int day,int index, vector<vector<int>> &points){
    if(day==n || index==3){
        return 0;
    }

    int ans=0;
    for(int i=0;i<3;i++){
        if(i!=index){
            ans=max(ans,points[day][i]+solverec(n,day+1,i,points));
        }
    }
    return ans;
}


int solvemem(int n,int day,int index, vector<vector<int>> 
&points,vector<vector<int>> &dp){
     if(day==n || index==4){
         
        return 0;
    }
    if(dp[day][index]!=-1){
        return dp[day][index];
    }
    int ans=0;
    for(int i=1;i<=3;i++){
        if(i!=index){
            ans=max(ans,points[day][i-1]+solvemem(n,day+1,i,points,dp));
        }
    }
    dp[day][index]= ans;
    return dp[day][index];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    Write your code here.
    int day=0;
    int index=0;
    int prev=-1;
    vector<vector<int>> dp(n+1,vector<int>(4,-1));
   return solvemem(n,day,index,points,dp);


  
}