/* 
    TP 2018/2019: LV 5, Zadatak 3
	
	Autotestove pisala Nina Slamnik. Prijave gresaka, sugestije i pitanja
	mozete slati na mail nslamnik1@etf.unsa.ba.
	
	NAPOMENA: Tutorijal 5 sadrzi veliki broj ZABRANA, tipa zabrana
			  da se koristi indeksiranje niz[i] ili simulacija indeksiranja
			  npr. *(niz + i); dalje, da su zabranjene for petlje i slicno.
			  
			  To ce tutori rucno pregledati u toku tutorijala te ako
			  student bude PREKRSIO BAREM JEDNU ZABRANU, smatrace se da
			  za taj zadatak NIJE PROSAO NITI JEDAN AUTOTEST!
*/
#include <iostream>
#include <algorithm>
#include <cmath>

void unesi(int &broj)
{
    std::cin>>broj;
}
bool da_li_je_potpuni_kvadrat(int broj){
    int korijen=sqrt(broj);
    if(broj==korijen*korijen)return true;
    return false;
}
bool Najmanji_Broj(int broj1, int broj2){
    broj1=log10(abs(broj1)+1);
    broj2=log10(abs(broj2)+1);
    return(broj1<broj2);
}
bool netrocifren(int broj){
    return abs(broj)<100 || abs(broj)>=1000;
}
int main ()
{
    std::cout<<"Unesite broj elemenata (max. 1000): ";
    int broj_elemenata;
    std::cin>>broj_elemenata;
    std::cout<<"Unesite elemente: ";
    int niz[1000];
    std::for_each(niz, niz+broj_elemenata, unesi);
    std::cout<<"Najveci element niza je "<<*std::max_element(niz, niz+broj_elemenata)<<std::endl;
    std::cout<<"Najmanji element niza se pojavljuje "<<std::count(niz, niz+broj_elemenata, *std::min_element(niz, niz+broj_elemenata))<<" puta u nizu"<<std::endl;
    std::cout<<"U nizu ima "<<std::count_if(niz, niz+broj_elemenata, da_li_je_potpuni_kvadrat)<<" brojeva koji su potpuni kvadrati"<<std::endl;
    std::cout<<"Prvi element sa najmanjim brojem cifara je "<<*std::min_element(niz, niz+broj_elemenata, Najmanji_Broj)<<std::endl;
    int niz2[1000];
    int r;
    r=std::count_if(niz, niz+broj_elemenata, netrocifren);
    std::copy_if(niz, niz+broj_elemenata, niz2, netrocifren);
    std::cout<<"Elementi koji nisu trocifreni su: ";
    std::for_each(niz2, niz2+r, [](int broj){std::cout<<broj<<" ";});
    return 0;
   
}