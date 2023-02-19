/* 
    TP 2018/2019: LV 6, Zadatak 6
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/
#include <iostream>
#include <stdexcept>
#include <limits>

template <typename Tip>
Tip *GenerirajStepenDvojke(int n){
    if(n<=0) throw std::domain_error("Broj elemenata mora biti pozitivan");
    Tip *pok=nullptr;
    try{
        pok=new Tip[n];
    }catch(...){std::runtime_error("Alokacija nije uspjela");
    delete[] pok;
    }

Tip max=std::numeric_limits<Tip>::max();
pok[0]=1;
int stepen_dvojke(1);
for(int i=1; i<n; i++){
    pok[i]=stepen_dvojke*=2;
    if(stepen_dvojke>=max)
    throw std::overflow_error("Prekoracen dozvoljeni opseg");
}
return pok;
}
int main ()
{
	return 0;
}