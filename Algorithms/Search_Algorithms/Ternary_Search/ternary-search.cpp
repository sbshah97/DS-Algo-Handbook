#include <bits/stdc++.h>
using namespace std;
/*
Problem:
find minimum value of this function in range [l,r]
*/
double f(double x){
    return 2*x*x-12*x+7;
}

int main()
{
    double l,r;
    cin>>l>>r;
    for(int i=0;i<200;i++){
        double m1 = (l*2+r)/3;
        double m2 = (l+r*2)/3;
        if(f(m1)>f(m2))l=m1;
        else r=m2;
    }
    cout<<f(l)<<endl;
}
