#include<iostream>
#define MAX 10000

using namespace std;

int t[MAX];
int x,n;

//test : n=10 
//1 5 20 45 55 56 57 78 99 134

void seqSearch(int key) {
	int i;
	for (i = 0; i < n; ++i) {
		if (t[i] == key) {
			cout << "���ҳɹ����±�Ϊ��" << i+1 << endl;
			break;
		}			
	}
	if (i == n)
		cout << "δ�������в��ҵ�"<< key << endl;

}

void binarySearch(int key) {
	int left,middle,right;
	left = 0;
	right = n - 1;
	
	while ( left <= right) {
		middle = (left+right) / 2;
		if (key == t[middle]) {
			cout << "���ҳɹ����±�Ϊ��" << middle + 1 << endl;
			break;
		}
		else if (key < t[middle])
			right = middle - 1;
		else
			left = middle + 1;

	}
	if (left > right)
		cout << "δ�������в��ҵ�" << key << endl;
}

int main() {
	
	cout << "���������е�������";
	cin >> n;
	
	cout << "���������У�" << endl;
	for (int i = 0; i < n; ++i)
		cin >> t[i];
	
	cout << "��������Ҫ���ҵ�����";
	cin >> x;

	seqSearch(x);
	binarySearch(x);
	
	return 0;
}

