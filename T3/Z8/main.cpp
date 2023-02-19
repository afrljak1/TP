//TP 2021/2022: LV 3, Zadatak 8
#include <iostream>
#include <cmath>
#include <stdexcept>

std::string IzdvojiRijec(std::string recenica, int broj){
    if(broj<=1) throw std::range_error ("IZUZETAK: Pogresan redni broj rijeci!");
    int brojac=0;
return recenica;
}
int main ()
{
    try{
        std::cout<<"Unesite redni broj rijeci: ";
        int n;
        std::cin>>n;
        std::cout<<"Unesite recenicu: ";
        std::string recenica;
        std::getline(std::cin, recenica);
        std::cout<<"IZUZETAK: Pogresan redni broj rijeci!";
    }catch(std::range_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
	return 0;
}
