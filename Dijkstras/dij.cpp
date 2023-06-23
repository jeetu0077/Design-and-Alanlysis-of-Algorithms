#include<iostream>
#include<string>
#define INF 999
using namespace std;
class shortest{
	private:
		int choice, n, a[50][50], source, destination;
		string output="";
		
	public:
		void initialise(){
			cout<<"Enter number of nodes:"<<endl;
			cin>>n;
			cout<<"Enter 999 for infinity (if edge is not present)"<<endl;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(i<=j){
						cout<<"Enter distance from node "<<i<<" to "<<"node "<<j<<endl;
						cin>>a[i][j];
						a[j][i]=a[i][j];
					}
				}
			}
			cout<<"adjacency matrix:"<<endl;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					cout<<a[i][j]<<"\t";
				}
				cout<<endl;
			}
		}
		void dijikstra(){
			int dis[n];
			int vis[n]={0};
			int count=n;
			int node;
			cout<<"enter source node:"<<endl;
			cin>>source;
			dis[source]=0;
			for(int i=0;i<n;i++){ //initialising for all nodes
				if(i!=source){
					dis[i]=999;	
				}
			}
			node=source;
			int min; //dis[i][1]
			while(count>0){
				for(int j=0;j<n;j++){
					if(a[node][j]!=INF){//if edge is present
						if(vis[node]==0){ //not visited
							if(dis[j]>a[node][j]+dis[node]){
							//	dis[j][0]=node;
								dis[j]=a[node][j]+dis[node];
							}
						}
					}
				}
				vis[node]=1;
				count--;
				for(int k=0;k<n;k++){ //for initialising min
					if(vis[k]==0){ //if node not visited
						min=dis[k];
						node=k;
						break;
					}
				}
				for(int k=0;k<n;k++){ //for finding min
					if(vis[k]==0){
						if(min>dis[k]){
							min=dis[k];
							node=k;
						}
					}
				}
			}
			cout<<endl;
			dis[source]=0;
			cout<<"distance calculated:"<<endl;
			for(int i=0;i<n;i++){
				cout<<i<<"\t";
				cout<<dis[i]<<endl;
			}
			cout<<endl;
		}
};
int main(){
	shortest s;
	s.initialise();
	s.dijikstra();
	return 0;
}