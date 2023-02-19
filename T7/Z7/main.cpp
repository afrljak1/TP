/* 
    TP 16/17 (LV 7, Zadatak 7)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/


#include <iostream>
#include <set>

    template<typename NekiTip>
    std::set<NekiTip>Unija(std::set<NekiTip>prvi, std::set<NekiTip>drugi){
        std::set<NekiTip>novi;
        //prvi.merge(drugi);
        for(std::set<NekiTip> i=prvi.begin(); i!=prvi.end(); i++)
        for(std::set<NekiTip> j=drugi.begin(); j!=drugi.end(); j++)
        novi.insert(*i);
        return novi;
    }
int main ()
{
    std::set<std::string>prvi;
    std::set<std::string>drugi;
    std::set<std::string>unija=Unija(prvi,drugi);
 
	return 0;
}