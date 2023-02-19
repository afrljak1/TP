/* 
    TP 2018/2019: LV 5, Zadatak 7
	
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
#include <vector>
#include <deque>

template<typename NekiTip>
auto SumaBloka(NekiTip pocetak_bloka, NekiTip kraj_bloka) ->decltype(*pocetak_bloka+*kraj_bloka){
    if(pocetak_bloka==kraj_bloka){
        throw std::range_error("Blok je prazan");
    }
    auto suma(*pocetak_bloka);
    while(++pocetak_bloka!=kraj_bloka)
    suma+=*pocetak_bloka;
    return suma;
}
int main ()
{
    
std::deque<double> d{1,2,3,4,5,6,7,8,9};
std::cout<<"Suma bloka je: "<<SumaBloka(d.begin(), d.end());
	return 0;
}