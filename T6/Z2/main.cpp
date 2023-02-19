/* 
    TP 2018/2019: LV 6, Zadatak 2
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/
#include <iostream>
#include <new>
#include <type_traits>
#include <vector>

template< typename NekiTip>
auto KreirajIzvrnutiNiz(NekiTip pocetak, NekiTip iza_kraja)->typename std::remove_reference<decltype(*pocetak)>::type*{
   int temp=0; 
   NekiTip pomocna=pocetak;
   while(pomocna!=iza_kraja)
    {
    temp++;
    pomocna++;
    }
typename std::remove_reference<decltype(*pocetak)>::type*pok=nullptr;
try{
    pok=new typename std::remove_reference<decltype(*pocetak)>::type[temp];
}catch(...){
    delete[]pok;
    throw std::bad_alloc();
}

return pok;
}
int main ()
{ 
    try{
    int broj_elemenata;
    int unos_elemenata;
    std::cout<<"Koliko zelite elemenata: ";
    std::cin>>broj_elemenata;
    //double temp;
    std::vector<double>temp;
    temp.resize(broj_elemenata);
    std::cout<<"Unesite elemente: ";
    for(int i=0; i<broj_elemenata; i++){
        std::cin>>unos_elemenata;
        temp[i]=unos_elemenata;
    }
    std::cout<<"Kreirani niz: ";
    auto temp2=KreirajIzvrnutiNiz(temp.begin(), temp.end());
    for(int i=0; i<broj_elemenata; i++)
    std::cout<<temp2[i]<<" ";
    delete [] temp2;
    }catch(...){
        std::cout<<"Nedovoljno memorije!";
    }
	return 0;
}