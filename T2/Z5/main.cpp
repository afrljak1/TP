//TP 2020/2021: Tutorijal 2, Zadatak 5
#include <complex>
#include<iostream>

int main ()
{
    std::cout<<"Unesite broj elemenata: "<<std::endl;
    int broj;
    std::cin>>broj;
    double zk, fk;
    
const double PI=4*atan(1);

std::complex<double>suma;
for(int i=1; i<=broj; i++){
    std::cout<<"Z"<<i<<" = ";
    std::cin>>zk;
    std::cout<<"fi"<<i<<" = ";
    std::cin>>fk;
    std::cout<<std::endl;

fk=PI*fk/180;
std::complex<double>temp;
temp=std::polar(zk, fk);
std::complex<double>temp2;
temp2=1./temp;
suma+=temp2;
}
std::complex<double>ukupna_impedansa;
ukupna_impedansa=1./suma;
std::cout<<"Paralelna veza ovih elemenata ima Z = "<<std::abs(ukupna_impedansa)<<" i fi = "<<std::arg(ukupna_impedansa)*(180/PI)<<"."<<std::endl;


    return 0;
}
