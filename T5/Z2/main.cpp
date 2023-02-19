/* 
    TP 2018/2019: LV 5, Zadatak 2
	
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

template<typename NekiTip, typename NekiTip2>
NekiTip2 RazmijeniBlokove(NekiTip poc, NekiTip kraj, NekiTip2 poc2){
    while(poc!=kraj){
        auto temp=*poc;
        *poc++=*poc2;
        *poc2++=temp;
    }
    return poc2;
}

int main(){
int niz[]{11,23,37,49,50};
std::deque <int> dek{64, 72, 86, 91, 105};
RazmijeniBlokove(dek.begin(),dek.end(),std::begin(niz));
std::cout << "Prvi kontejner: ";
for(int x : niz) std::cout << x << " ";
std::cout << "\nDrugi kontejner: ";
for(int x : dek) std::cout << x << " ";
std::cout << std::endl;

	return 0;
}