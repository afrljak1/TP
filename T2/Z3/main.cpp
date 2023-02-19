//TP 2020/2021: Tutorijal 2, Zadatak 3
#include <iostream>
#include <complex>

int main ()
{
    std::cout<<"Unesite broj elemenata: ";
    int broj;
    std::cin>>broj;

std::complex<double>suma;
for(int i=1; i<=broj; i++){
    std::complex<double>broj_impedansi;
    std::cout<<"Z_"<<i<<" = ";
    std::cin>>broj_impedansi;

    std::complex<double>impedansa;
    suma+=1./broj_impedansi;
}
std::cout<<"\n";
std::complex<double>ukupna_impedansa;
ukupna_impedansa=1./suma;
std::cout<<"Paralelna veza ovih elemenata ima impedansu Z_ = "<<ukupna_impedansa<<"."<<std::endl;


    return 0;
}
