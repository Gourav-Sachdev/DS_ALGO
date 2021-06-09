#include<bits/stdc++.h>
using namespace std;



bool is_inside(int row,int col,int i,int j)
{
    return i>=0 && i<row && j>=0 && j<col;
}

void bfs_01(int m,int n,vector<string>& v)
    {

         
        
            vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
               int row_movement[4]={1,-1,0,0};   // i+1,j  i-1,j i,j-1  i,j+1
               int col_movement[4]={0,0,1,-1};
                           //       D U R  L
               // string given_movement="DURL";
                char given_movement[]={'D','U','R','L'};          
      

             priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
         ///  deque<pair<int,int>>dq;

            pq.push({0,{0,0}});
            dist[0][0]=0;


            while(!pq.empty())
            {
               pair<int,pair<int,int>> source=pq.top();

               //int nbr_dist=source.first;
               int nbr_x=source.second.first;
               int nbr_y=source.second.second;
                pq.pop();


                for(int i=0;i<4;i++)
                {
                     int x_new=nbr_x+row_movement[i];
                     int y_new=nbr_y+col_movement[i];

                     if(is_inside(m,n,x_new,y_new))
                     {     //if hum down jaa rahe and v[i][j] bhi D diya hai to cost =0        
                         int wt= (given_movement[i]==v[nbr_x][nbr_y])?0:1;

                         if(dist[x_new][y_new]>dist[nbr_x][nbr_y]+wt)
                         {
                             dist[x_new][y_new]=dist[nbr_x][nbr_y]+wt;
                             pq.push({dist[x_new][y_new],{x_new,y_new}});
   
                         }
                     }
                }

                

               

                
            }
            // cout<<dist[m-1][n-1];

            // cout<<"dfbdf";
            for(int i=0;i<dist.size();i++)
            {
                for(int j=0;j<dist[0].size();j++)
                {
                    cout<<dist[i][j]<<"  ";
                }
                cout<<endl;
            }

            
            cout<<"the cost of v[0][0] to v[m-1][n-1] = "<<dist[m-1][n-1]<<endl;
    }


int main()
{
   

//    int m,n;
//    cin>>m,n;

   //vector<vector<char>>(m,vector<char>(n));
   vector<string>v;
     v.push_back("RRD");
     v.push_back("DDU");
     v.push_back("LLL");

     for(int i=0;i<v.size();i++)
     {
         cout<<v[i]<<endl;
     }

     

       bfs_01(3,3,v);
       

    return 0;



}