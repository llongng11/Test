#include <iostream>
using namespace std;

void Import(int a[], int &n);
void Swap(int &x, int &y);
void Descending(int a[], int n);
int GCD(int m, int n);
void Insert(int a[], int &n, int Pos, int Item);
void Insert_GCD(int a[], int &n);
void Export(int a[], int n);

int main(){
	int a[100],n;
	Import(a,n);
	Export(a,n);
	return 0;
}

void Import(int a[], int &n){
	do{
		cout<<"Import n = ";
		cin>>n;
	}while(n>100||n<=0);
	cout<<endl;
	for(int i=0;i<n;i++)
		do{
			cout<<"* a["<<i<<"] = ";
			cin>>a[i];
		}while(a[i]<=0);
}

void Swap(int &x, int &y){
	int Temp=x;
	x=y;
	y=Temp;
}

void Descending(int a[], int n){
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]<a[j])
				Swap(a[i],a[j]);
}

int GCD(int m, int n){
	int GCD;
	for(int i=1;i<=m||i<=n;i++)
		if(m%i==0&&n%i==0)
			GCD=i;
	return GCD;
}

void Insert(int a[], int &n, int Pos, int Item){
	n++;
	for(int i=n-1;i>Pos;i--)
		a[i]=a[i-1];
	a[Pos]=Item;
}

void Insert_GCD(int a[], int &n){
	int i=0;
	while(i<n-1){
		Insert(a,n,i+1,GCD(a[i],a[i+1]));
		i+=2;
	}
}

void Export(int a[], int n){
	system("cls");
	cout<<"Original Array a["<<n<<"] = ";
	for(int i=0;i<n;i++)
		cout<<a[i]<<"   ";
	Descending(a,n);
	cout<<endl<<endl<<"* Descending Array a["<<n<<"] = ";
	for(int i=0;i<n;i++)
		cout<<a[i]<<"   ";
	Insert_GCD(a,n);
	cout<<endl<<"* Array with Greatest Common Divisors a["<<n<<"] = ";
	for(int i=0;i<n;i++)
		cout<<a[i]<<"   ";
}
