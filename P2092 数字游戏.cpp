#include<iostream>
using namespace std;
long long q, n, p[100000];
int main(){
	cin >> q;
	for(long long i = 2; i * i <= q; i++){
		while(q % i == 0){
			q /= i;
			p[n] = i;
			n++;
			
		}
		if(i * i >= q / i && i >= 1000 && n == 0){
			cout << 2;
			return 0;
		}
		if(n >= 2){
			break;
		}
		if(i % 2 == 1){
			i++;
		}
	}
	if(q > 1 && n != 0){
		n++;
	}
	
	if(n == 0){
		cout << 1 << endl << 0;
		return 0;
	}
	if(q == 1 && n == 1){
		cout << 1 << endl << 0;
		return 0;
	}
	
	if(n > 2){
		cout << 1 << endl << p[0] * p[1];
	}
	else {
		cout << 2;
	}
	return 0;
}
