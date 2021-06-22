 
#include <iostream>
#include <algorithm>
using namespace std;
 
int findPivorIdx(int A[], int k, int low, int high) {
 
	int pivor = A[low];
	while (low<high)
	{
		while (A[high]>=pivor && low<high)
		{
			high--;
		}
		A[low] = A[high];
 
		while (A[low]<pivor && low<high)
		{
			low++;
		}
		A[high] = A[low];
	}
 
	A[low] = pivor;
 
	return low;
}
 
int findKMin(int A[],int k, int low, int high) {
 
	if (low<high)  
	{
		int pId = findPivorIdx(A,k,low,high);
		if ((pId+1)==k)  
		{
			return A[pId];
		}else if((pId+1)<k) {  
			return findKMin(A,k,pId+1,high);  
		}else if((pId+1)>k){
			return findKMin(A,k,low,pId-1);  
		}
	}
 
	else {  
		return A[low];
	}
}
 
 
int main () {
 
	
	const int N = 16;
	int A[N] = {32,122,34,5,6,74,22,11,55,66,11,33,6,1,4,8};
	int B[N];
	cout<<"原始数据"<<endl;
	for (int i = 0;i<N;i++)
	{
		cout<<A[i]<<" ";
		B[i] = A[i];
	}
	cout<<"\n";
 
	 
	cout<<"排序好的数据"<<endl;
	sort(B,B+N); // first, the one past last
	for (int i = 0;i<N;i++)
	{
		cout<<B[i]<<" ";
	}
	cout<<"\n\n";
 
	for (int i = 1;i<=N;i++)
	{
		cout<<"第"<<i<<"小的数是"<<B[i-1]<<"（正确的） "<<findKMin(A,i,0,N-1)<<" （我写的）"<<endl;
	}
 
	system("pause");
	return 0;
}
