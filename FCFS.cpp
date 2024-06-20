#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cout<<"Enter the number of processes"<<endl;
	cin>>n;
	vector<int> v1(n),v2(n);
	cout<<"Enter the burst time:"<<endl;
	for(int i=0;i<n;i++){
		cin>>v1[i];
	}
	int wt=0;
	v2[0]=wt;
	for(int i=1;i<n;i++){
		wt+=v1[i-1];
		v2[i]=wt;
	}
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=v2[i];
	}
	int av=sum/n;
	cout<<""
}
