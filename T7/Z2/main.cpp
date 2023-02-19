/* 
    TP 16/17 (LV 7, Zadatak 2)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <cstring>
#include <iostream>
#include <algorithm>
#include <new>
int main ()
{
    try{
        std::cout<<"Koliko zelite recenica: ";
        int br_recenica;
        std::cin>>br_recenica;
        std::cin.ignore(1000, '\n');
        std::cout<<"Unesite recenice: "<<std::endl;
        //try{
        char**recenica=new char*[br_recenica];
        for(int i=0; i<br_recenica; i++){
            recenica[i]=nullptr;
        }
        for(int i=0; i<br_recenica; i++){
            char prostor[1000];
            std::cin.getline(prostor, 1000);
            recenica[i]=new char[std::strlen(prostor)+1];
            strcpy(recenica[i], prostor);
        }
        std::sort(recenica, recenica+br_recenica, [](const char *x, const char* y){
            return std::strcmp(x, y)<0;
        });
        std::cout<<"Sortirane recenice: "<<std::endl;
        for(int i=0; i<br_recenica; i++){
             std::cout<<recenica[i]<<std::endl;
        }
        for(int i=0; i<br_recenica; i++)
            delete [] recenica[i];
            for(int i=0; i<br_recenica; i++)recenica[i]=nullptr;
            delete [] recenica;
            recenica=nullptr;
    }catch(...){
        std::cout<<"Problemi s memorijom!";
    }
	return 0;
}