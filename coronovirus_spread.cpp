/*
There are N people on a street (numbered 1 through N). For simplicity, we'll view them as points on a line. For each valid i, 
the position of the i-th person is Xi. It turns out that exactly one of these people is infected with the virus COVID-19, 
but we do not know which one. The virus will spread from an infected person to a non-infected person whenever the distance between them is at most 2. 
If we wait long enough, a specific set of people (depending on the person that was infected initially) will become infected; 
let's call the size of this set the final number of infected people.
Your task is to find the smallest and largest value of the final number of infected people, i.e. this number in the best and in the worst possible scenario

INPUT
>The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
>The first line of each test case contains a single integer N.
>The second line contains N space-seperated integers X1,X2,…,XN.

OUTPUT
For each test case, print a single line containing two space-separated integers ― the minimum and maximum possible final number of infected people.

CONSTRAINTS
>1≤T≤2,000
>2≤N≤8
>0≤Xi≤10 for each valid i
>X1<X2<…<XN
*/

#include<iostream>
#include<cmath>
using namespace std;

int count_back(int i,int n,int x[])
{
	if(i==0)
		return 0;
	int ret=0,pos=i;
	while(pos>0)
	{
		if(abs(x[pos]-x[pos-1])>2)
			break;
		else
		{
			ret++;
			pos--;
		}
	}
	return ret;
}

int count_front(int i,int n,int x[])
{
	if(i==n-1)
		return 0;
	int ret=0,pos=i;
	while(pos<n-1)
	{
		if(abs(x[pos]-x[pos+1])>2)
			break;
		else{
			ret++;
			pos++;
		}
	}
	return ret;
}

int main()
{
	int t,back,front,min,max,n,total;
	cin>>t;
	while(t>0)
	{
		cin>>n;
		min=20;
		max=0;
		front=0;
		back=0;
		int x[n];
		for(int i=0;i<n;i++)
			cin>>x[i];
		for(int i=0;i<n;i++)
		{
			back=count_back(i,n,x);
			front=count_front(i,n,x);
			total=back+front+1;
			if(total<min)
			{
				min=total;
			}
			if(total>max)
			{
				max=total;
			}
		}
		cout<<min<<" "<<max<<endl;
		t--;
	}
	return 0;
}