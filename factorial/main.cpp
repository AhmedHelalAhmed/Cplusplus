#include <iostream>

using namespace std;
long double fun(long double x);
long double funr(long double x);
int main()
{
    //int number;
    //cout<<"enter number"<<endl;
    //cin>>number;
    //cout << "factorial = "<<fun(number);

    for(int i=0;i<=1000;i++)
    {
        cout<<"factorial of "<<i<<"\t"<<funr(i)<<endl;
    }





    return 0;
}
long double fun(long double x)
{
long double fact=1;
for(int i=1;i<=x;i++)
fact*=i;
return fact;

}

long double funr(long double x)
{
    if(x<=0)
    {
        return 1;

    }
    return x*funr(x-1);

}

