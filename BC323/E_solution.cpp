#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
int main(void) {
	int n,x;
	mint ans;
	
	cin>>n>>x;
	vector<int>t(n);
	for(int i=0;i<n;i++)cin>>t[i];
	vector<mint>p(x+1);
	p[0]=1;
	if(t[0]>x)ans+=p[0]/((mint)n);
	for(int i=1;i<=x;i++){
		for(int j=0;j<n;j++)if(t[j]<=i)p[i]+=p[i-t[j]];
		p[i]/=((mint)n);
		if(i+t[0]>x)ans+=p[i]/((mint)n);
	}
	cout<<ans.val()<<endl;
	return 0;
}