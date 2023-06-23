#include<iostream>
#include<string>
using namespace std;
class prims{
	private:
		int adj[10][10]; //to store weights of edges, if present
		int n,parent[10],child[10];
		bool visited[10];
		int key[10];
		int inf=1000; //defining infinity
	public:
		void initialise(){
			cout<<"Enter number of nodes:"<<endl;
			cin>>n;
			cout<<"Enter adjacency matrix, weights of edges- if its present, else enter 0"<<endl;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(i<=j){
						cout<<"Node "<<i<<" to Node "<<j<<endl;
						cin>>adj[i][j];	
						adj[j][i]=adj[i][j];
					}
				}
			}
			cout<<endl;
			cout<<"Adjacency Matrix:"<<endl;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					cout<<adj[i][j]<<" ";
				}
				cout<<endl;
			}		
			for(int i=0;i<n;i++){
				visited[i]=false; //if visited in MST then true
			}
			key[0]=0; //starting with root node
			for(int i=1;i<n;i++){
				key[i]=inf; //initialising with infinity
			}
			parent[0]=-1;
		}		
		void mst(){
			int vertex;
			int temp=-1;
		//	int k=0;
			while((checkIfAllElementsArevisited(visited,n))==false){
				vertex=minkey(key, visited,n); 
				visited[vertex]=true;
				for(int i=0;i<n;i++){ //updating key value of neighbour of current vertex
					if(adj[vertex][i]!=0)//node present
					{
						if(key[i]>adj[vertex][i]){
							key[i]=adj[vertex][i];
							parent[i]=vertex; //parent
							child[i]=i; //to child
						//	k++;
						}
					}
				}	
			}
		}
		int minkey(int key[],bool visited[],int n){ //minimum key which is not visited in the mst
			int min=inf,index=0;
			for(int i=0;i<n;i++){
				if(visited[i]==false){ //if node visited then skip
					if(key[i]<min){
						min=key[i];  	
						index=i;
					}
				}
			}
			return index;
		}
		bool checkIfAllElementsArevisited(bool visited[],int n){ 
			for(int i=0;i<n;i++){
				if(visited[i]==false){
					return false; //if false, then the function will return the value and the control will go out of loop
				}
			}
			return true;
		}
		void display(){
			int sum=0;
			cout<<endl;
			cout<<"Edge\tWeight"<<endl; //displaying edges
			for(int i=1;i<n;i++){ 
				cout<<parent[i]<<"-"<<child[i]<<"\t"<<key[i]<<endl;
			}
			for(int i=1;i<n;i++){ //calculating weight
				sum=sum+key[i];
			}
			cout<<endl<<"weight of tree="<<sum;
		}
};
int main(){
	prims p;
	p.initialise();
	p.mst();
	p.display();
	return 0;
}
