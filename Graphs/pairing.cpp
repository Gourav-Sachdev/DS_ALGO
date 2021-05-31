#include<iostream>
#include<bits/stdc++.h>
using namespace std;



     int find(int i,vector<int>& parent)
	 {
		 if(parent[i]==-1)
		   return i;
		return parent[i]=find(parent[i],parent);
	 }

	 void union_set(int s1,int s2,vector<int>& parent,vector<int>& rank)
	 {
		 int parent1=find(s1,parent);
		 int parent2=find(s2,parent);


		 if(parent1!=parent2)
		 {
			 if(rank[parent1]>rank[parent2])
			 {
                  parent[parent2]=parent1;
				  rank[parent2]+=rank[parent1];

			 }
			 else{
                      parent[parent1]=parent2;
					   rank[parent1]+=rank[parent2];

			 }
		 }
	 }


int main() {

	int V;
	int edge;
	cin>>V>>edge;

	vector<pair<int,int>>edge_list(V);
	vector<int>parent(V,-1);
	vector<int>rank(V,1);     // all rank =1
     

      for(int i=0;i<edge;i++)
	  { 
		  int a;
		  int b;
		  cin>>a>>b;

          edge_list.push_back({a,b});
	  }

	       for(auto edge_pair:edge_list)
		   {
			   int s1=find(edge_pair.first,parent);
			    int s2=find(edge_pair.second,parent);


				if(s1!=s2)
				{
					union_set(s1,s2,parent,rank);
				}
		   }


		   for(int i=0;i<V;i++)
		   {
			   cout<<parent[i];

		   }  
		   cout<<endl;

		   for(int i=0;i<V;i++)
		   {
			   cout<<rank[i];

		   }  
		   cout<<endl;

	
	return 0;
}