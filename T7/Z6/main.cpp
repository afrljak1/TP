/* 
    TP 16/17 (LV 7, Zadatak 6)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include<list>

template<typename NekiTip>
std::list<NekiTip>SortirajListu(std::list<NekiTip>&lista){
    for(auto it=lista.begin(); it!=lista.end(); it++){
        for(auto j=lista.begin(); j!=lista.end(); j++){
            if(*it<*j){
                auto temp=*it;
                *it=*j;
                *j=temp;
            }
        }
    } return lista;
}
int main ()
{
    std::list<int>lista;
    std::cout<<"Koliko ima elemenata: ";
    int br_elemenata;
    std::cin>>br_elemenata;
    std::cout<<"Unesite elemente: ";
    for(int i=0; i<br_elemenata; i++){
        int x=0;
        std::cin>>x;
        lista.push_back(x);
    }
SortirajListu(lista);
std::cout<<"Sortirana lista: ";
for(auto x:lista)std::cout<<x<<" ";
	return 0;
}