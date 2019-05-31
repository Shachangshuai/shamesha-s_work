#include <iostream>
using namespace std;
void GetNum(int *&f,int n);
void Bulid(int *&f,int n);
int Plus(int *f,int n);
int main()
{
    int *f,n;
   cin>>n;
    GetNum(f,n);
    Bulid(f,n);
    cout<<Plus(f,n)<<endl;
}
void GetNum(int *&f,int n)
{
    f=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        cin>>f[i];
    }
}
void Bulid(int *&f,int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(f[j]>f[j-1])
            {
                int temp=f[j];
                f[j]=f[j-i];
                f[j-i]=temp;
            }
        }
    }
}
int Plus(int *f,int n)
{
    int a=0;
    for(int i=n-2;i>=0;i--)
    {
        a+=(f[i]+f[i+1]);
        f[i]=f[i]+f[i+1];
    }
    return a;
}