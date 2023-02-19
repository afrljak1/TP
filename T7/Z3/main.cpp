/* 
    TP 16/17 (LV 7, Zadatak 3)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <string>
#include <algorithm>
int main ()
{
    try{
        std::cout<<"Koliko zelite recenica: ";
        int br_recenica;
        std::cin>>br_recenica;
        std::cin.ignore(100000, '\n');
        std::cout<<"Unesite recenice: "<<std::endl;
        std::string **recenica={};
        recenica=new std::string*[br_recenica];
        for(int i=0; i<br_recenica; i++)recenica[i]=nullptr;
        for(int i=0; i<br_recenica; i++){
            recenica[i]=new std::string;
            std::getline(std::cin, *recenica[i]);
        }
        std::sort(recenica, recenica+br_recenica, [](const std::string *prvi, const std::string *drugi){
            return *prvi<*drugi;
        });
        std::cout<<"Sortirane recenice: "<<std::endl;
        for(int i=0; i<br_recenica; i++){
            std::cout<<*recenica[i]<<std::endl;
        }
    for(int i=0; i<br_recenica; i++)delete recenica[i];
   delete [] recenica;
    }catch(...){
        std::cout<<"Problemi s memorijom!";
    }
	return 0;
}