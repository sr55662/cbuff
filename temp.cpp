
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


#define EPSILON 1e-9
#define F first
#define S second
#define PB push_back
#define MP make_pair

#ifdef DEBUG
#define l cout << "******** "<< __FUNCTION__ <<":" << __LINE__ <<" *************" << endl;
#define c(x) cout << #x << " : " << (x) << endl
#define dbg(x) l; c(x) 
#define dbg2(x,y) l; c(x); c(y)
#define dbg3(x,y,z)l; c(x); c(y); c(z)
#define p(x,y) cout << #x#y << y.x << endl
#else
#define l
#define dbg(x)
#define dbg2(x,y)
#define dbg3(x,y,z)
#define NDEBUG 
#include<assert.h>
#define p(x,y)

#endif

template<class T>
T& mymax( const T& a,  const T& b) {
	cout << typeid(T).name() << endl;
	return const_cast<T&>(b < a ? a : b);
}

class foo {
public:
	foo():x(9) {
		cout << "constructor called " << endl;
	}

	int x;
};

ostream& operator << (ostream& o, const foo& rhs){
		o << rhs.x;
		return o;
}



int main() {
//	freopen ("inp.txt","r",stdin);
//	freopen ("out.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s1("s1");
	string s2("s2");
	cout << mymax(s1,s2) << endl;
	cout << mymax<string>("a3","g4") << endl;

	foo a;
	foo b{};
	dbg2(a,b);
	p(x,a);

}
