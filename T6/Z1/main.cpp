/* 
    TP 2018/2019: LV 6, Zadatak 1
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/
#include <iostream>
#include <limits>
#include <math.h>
#include <stdexcept>

template <typename Tip>
Tip* GenerirajStepeneDvojke(int n){
    if(n<=0)throw std::domain_error("Broj elemenata mora biti pozitivan");
    Tip *pok=nullptr;
    try{
        pok=new Tip[n];
    }catch(...){
        throw std::runtime_error("Alokacija nije uspjela");
        delete[]pok;
    }
    Tip max=std::numeric_limits<Tip>::max();
    pok[0]=1;
    int stepen_dvojke=1;
    
    for(int i=0; i<n; i++){
        if(std::numeric_limits<Tip>::max()-pow(2, i)<0){
         
            delete [] pok;
              throw std::overflow_error("Prekoracen dozvoljeni opseg");
        }
        pok[i]=pow(2, i);
      // pok[i]=i*i;
    }
    return pok;
}
int main ()
{
     double broj_elemenata;
    std::cout<<"Koliko zelite elemenata: ";
    std::cin>>broj_elemenata;
    int *pom=nullptr;
    try{
        pom=GenerirajStepeneDvojke<int>(broj_elemenata);
        for(int i=0; i<broj_elemenata; i++)
        std::cout<<pom[i]<<" ";
        delete [] pom;
    }catch(std::domain_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }catch(std::runtime_error izuzetak){
    std::cout<<"Izuzetak: "<<izuzetak.what();
    }	catch(std::overflow_error izuzetak){
    std::cout<<"Izuzetak: "<<izuzetak.what();
}
return 0;
}