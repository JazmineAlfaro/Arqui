#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binario(int m){
	vector<int> binario;
	while(m/2 > 1){
		int c = m%2;
		binario.push_back(c);
		m = m/2;
	}
	if(m/2 == 1){
		int c = m%2;
		binario.push_back(c);
		binario.push_back(1);
		
	}
	reverse(binario.begin(),binario.end());
	int a = binario.size();
	for(int i=0; i<a;i++){
		cout<< binario[i]<<endl ;
	}
}

int complement2(int m){
	vector<int> binario;
	while(m/2 > 1){
		int c = m%2;
		binario.push_back(c);
		m = m/2;
	}
	if(m/2 == 1){
		int c = m%2;
		binario.push_back(c);
		binario.push_back(1);
		
	}
	reverse(binario.begin(),binario.end());
	int a = binario.size();
	for(int i=0;i<a;i++){
		if (binario[i] == 1)
			binario[i] = 0;
		else
			binario[i] = 1;
	}
	
	int sum = 1;
	int i = 1;
	while(sum == 1){
		if(binario[a-i] == 1){
			binario[a-i] = 0;
			i++;
		}
		else{
			binario[a-i] = 1;
			sum = 0;
		}
	}
	
	for(int i=0;i<a;i++)
		cout<<binario[i]<<endl;
}

int main() {
	int m,q;
	cout<<"Ingrese el multiplicando: " << endl;
	cin>> m;
	cout<<"Ingrese el multiplicador: " << endl;
	cin>> q;
	cout<<"El multiplicando  " << m << " en binario es :" << endl;
	binario(m);
	cout<<"El multiplicador  " << q << " en binario es :" << endl;
	binario(q);
	cout<<"El complemento a 2 de  " << m << " es :" << endl;
	complement2(m);
	cout<<"El complemento a 2 de  " << q << " es :" << endl;
	complement2(q);
	return 0;
}

