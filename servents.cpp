#include<iostream>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t>0)
	{
		cin>>n;
		if(n<10)
		{
			cout<<"What an obedient servant you are!"<<endl;
		}
		else
			cout<<-1<<endl;
		t--;
	}
}