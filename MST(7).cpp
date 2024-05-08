#include<iostream>
using namespace std;

class graph{
	int a[20][20],l,u,w,i,j,v,e,visited[20];
	public:
		void input();
		void display();
		void prims();
};

void graph :: input(){
	cout<<"Enter the no. of branches: ";
    cin>>v;

    for(i=0;i<v;i++)
    {
        visited[i]=0;
        for(j=0;j<v;j++)
        {
            a[i][j]=0;
        }
    }

    cout<<"\nEnter the no. of connections: ";
    cin>>e;

    for(i=0;i<e;i++)
    {
        cout<<"Enter the end branches of connections:  "<<endl;
        cin>>l>>u;
        cout<<"Enter the phone company charges for this connection:  ";
        cin>>w;
        a[l-1][u-1]=a[u-1][l-1]=w;
    }
}
void graph :: display(){
	cout<<"\nAdjacency matrix:";
    for(i=0;i<v;i++)
    {
        cout<<endl;
        for(j=0;j<v;j++)
        {
            cout<<a[i][j]<<"   ";
        }
        cout<<endl;
    }
}
void graph :: prims(){
	 int p=0,q=0,total=0,min;
    visited[0]=1;
    for(int count=0;count<(v-1);count++)
    {
        min=999;
        for(i=0;i<v;i++)
        {
            if(visited[i]==1)
            {
                for(j=0;j<v;j++)
                {
                    if(visited[j]!=1)
                    {
                        if(min > a[i][j])
                        {
                            min=a[i][j];
                            p=i;
                            q=j;
    }
   }
  }
 }
}
        visited[p]=1;
        visited[q]=1;
        total=total+min;
        cout<<"Minimum cost connection is"<<(p+1)<<" -> "<<(q+1)<<"  with charge : "<<min<< endl;
        
    }
    cout<<"The minimum total cost of connections of all branches is: "<<total<<endl;
}
int main(){
	int flag,ch;
	graph t;
	flag = 1;
	while(flag==1){
	
	cout<<"*****PRIMS ALGORITHM*****"<<endl;
	cout<<"1)INPUT\n\n2)DISPLAY\n\n3)PRIMS\n\n4)Exit\n"<<endl;
	cout<<"Enter your choice : ";
	cin>>ch;
	
	
		if (ch==1){
			t.input();
			}
		else if (ch==2){
			t.display();
			}
		else if (ch==3){
			t.prims();
			}
		else if (ch==4){
		    cout<<"Exiting the program........"<<endl;
		    exit(0);
	        }
	    else{
	    	cout<<"Wrong input"<<endl;
	    	flag=1;
	    	}
	}
    
}
