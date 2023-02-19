//TP 2020/2021: Tutorijal 2, Zadatak 4
#include <iostream>
#include <complex>

int main ()
{
    std::cout<<"Unesite broj elemenata: "<<std::endl;
    int broj;
    std::cin>>broj;
    double Rk, Xk;

std::complex<double>suma;
for(int i=1; i<=broj; i++){
    std::cout<<"R"<<i<<" = ";
    std::cin>>Rk;
    std::cout<<"X"<<i<<" = ";
    std::cin>>Xk;
    std::cout<<std::endl;

  /*  std::complex<double>broj_impedansi;
    std::cout<<"Z_"<<i<<" = ";
    std::cin>>broj_impedansi;
*/
  std::complex<double>a, b;
  a=std::complex<double>(Rk, Xk);
  b=1./a;
  suma=suma+b;

}
std::complex<double>ukupna_impedansa;
ukupna_impedansa=1./suma;
std::cout<<"Paralelna veza ovih elemenata ima R = "<<real(ukupna_impedansa)<<" i X = "<<std::imag(ukupna_impedansa)<<"."<<std::endl;


    return 0;
}
