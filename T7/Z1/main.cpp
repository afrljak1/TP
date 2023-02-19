/* 
    TP 16/17 (LV 7, Zadatak 1)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cstring>
#include <new>

template <typename NekiTip>
void SelectionSort(NekiTip &recenica, int velicina){
    int imin, imax;
    for(int i=0; i<velicina-1; i++){
      //  imin=i;
        for(int j=0; j<velicina-i-1; j++){
        //if(recenica[j]<recenica[imin])
        //imin=j;
       // std::swap(recenica[i], recenica[imin]);
       if(strcmp(recenica[j], recenica[j+1])>0)
       std::swap(recenica[j], recenica[j+1]);
    }
}
}
int main ()
{
    int broj_recenica;
    std::cout<<"Koliko zelite recenica: ";
    std::cin>>broj_recenica;
    std::cin.ignore(1000, '\n');
    std::cout<<"Unesite recenice: "<<std::endl;
    //char **recenica=nullptr;
    char**recenica{};
    try{
        recenica=new char*[broj_recenica];
        for(int i=0; i<broj_recenica; i++)
        recenica[i]=nullptr;
        for(int i=0; i<broj_recenica; i++){
            char prostor[1000];
            std::cin.getline(prostor, 1000);
            recenica[i]=new char[std::strlen(prostor)+1];
            std::strcpy(recenica[i], prostor);
        }
        std::cout<<"Sortirane recenice: ";
        SelectionSort(recenica, broj_recenica);
        for(int i=0; i<broj_recenica; i++){
            std::cout<<recenica[i]<<std::endl;
        }
        for(int i=0; i<broj_recenica; i++)
        delete[] recenica[i];
        for(int i=0; i<broj_recenica; i++)
        recenica[i]=nullptr;
        delete[] recenica;
        recenica=nullptr;
    }catch(...){
        delete[] recenica;
        std::cout<<"Problemi s memorijom!";
    }
	return 0;
}