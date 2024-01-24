#include<iostream>
using namespace std;
int n, a[801], b[801], endof[800][800], endn[800];
bool ca[800][801], cd[800][801], pq[800][801], pd[800][801], nomore[800][802];
long long maxcmem[800];
bool ifpq(int a, int b){
	if(a < b){
		int c = a;
		a = b;
		b = c;
	}
	if(b == 1 && a != 1){
		return 0;
	}
	if(a % b == 0){
		return 1;
	}else{
		return ifpq(b, a % b);
	}
	return 0;
}
long long sum(int st, int ed){
//	cout << endl << "sum" << ' ' << st << ' ' << ed << ' ' << endl;
	long long ans = 0;
	for(int i = st; i <= ed; i++){
		ans += b[i];
//		cout << b[i] << endl;
	}
//	cout << ans << endl;
	return ans;
}
long long more(long long a, long long b){
	if(a >= b){
		return a;
	}
	return b;
}
long long maxc(int st){
	if(st >= n){
		return 0;
	}
	if(maxcmem[st] != -1){
		return maxcmem[st];
	}
	if(endn[st] > 0){
		maxcmem[st] = maxc(st + 1);
		for(int i = 1; i <= endn[st]; i++){
			maxcmem[st] = more(maxcmem[st], maxc(endof[st][i] + 1) + sum(st, endof[st][i]));
		}
		return maxcmem[st];
	}
	maxcmem[st] = maxc(st + 1);
	return maxcmem[st];
}
bool useifpq(int ai, int bi){
	if(pd[ai][bi] == 0){
		pd[ai][bi] = 1;
		pq[ai][bi] = ifpq(a[ai], a[bi]);
	}
	return pq[ai][bi];
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		maxcmem[i] = -1;
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}
	for(int i = 1; i < n; i++){
		if(useifpq(i, i + 1)){
			ca[i][i + 1] = 1;
			endn[i]++;
			endof[i][endn[i]] = i + 1;
		}
	}
	for(int l = 4; l <= n; l += 2){
		for(int st = 1; st + l - 1 <= n; st++){
			int ed = st + l - 1;
			if(ed > st + 1 && useifpq(st, ed) && ca[st + 1][ed - 1]){
				endn[st]++;
				endof[st][endn[st]] = ed;
				ca[st][ed] = 1;
				continue;
			}
			if(ed > st + 1){
				for(int cp = st + 1; cp < ed; cp += 2){
					if(ca[st][cp] && ca[cp + 1][ed]){
						endn[st]++;
						endof[st][endn[st]] = ed;
						ca[st][ed] = 1;
						break;
					}
				}
			}
		}
	} 
//	for(int i = 1; i <= n; i++){
//		cout << endof[i] << ' ';
//	}
//	for(int i = 1; i <= n; i++){
//		cout << maxc(n - i) << ' ';
//	}
//	cout << pq[15][18] << ifpq(a[15], a[18]) << ifpq(3432, 23) << endl;
	cout << maxc(1) << endl;
	return 0;
}
