#include<cstdio>
#include<cmath>
const double PI = acos(-1.0);

struct Virt{
	double r, i;
	Virt(double r = 0.0, double i = 0.0){
		this->r = r;
		this->i = i;
	}
	Virt operator + (const Virt &x){
		return Virt(r + x.r, i + x.i);
	}
	Virt operator - (const Virt &x){
		return Virt(r - x.r, i - x.i);
	}
	Virt operator * (const Virt &x){
		return Virt(r * x.r - i * x.i, i * x.r + r * x.i);
	}
};

int main(){
	
}
