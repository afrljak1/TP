//TP 2021/2022: LV 4, Zadatak 1
#include <cstdlib>
#include <iostream>
#include <cmath>

int Cifre(long long int n, int &c_min, int &c_max){
    
   int broj_cifara=1;
   
  c_min=std::abs(n%10);
  c_max=std::abs(n%10);
  n/=10;
  while(n!=0){
      int c=n%10;
      if(c<c_min)c_min=c;
      if(c>c_max)c_max=c;
      n/=10;
      broj_cifara++;
  }
  return broj_cifara;
}
int main ()
{
    long long int n;
    int a, b;
    std::cout<<"Unesite broj: ";
    std::cin>>n;
    int cifre=Cifre(n, a, b);
    std::cout<<"Broj "<<n<<" ima "<<cifre<<" cifara, najveca je "<<b<<" a najmanja "<<a<<".";
	return 0;
}
