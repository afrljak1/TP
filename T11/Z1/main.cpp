/* 
    TP 16/17 (LV 11, Zadatak 1)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
class NeobicnaKlasa{
public:
explicit NeobicnaKlasa(int n){
    std::cout<<"Direktna inicijalizacija"<<std::endl;
}
NeobicnaKlasa(double n){
    std::cout<<"Kopirajuca inicijalizacija"<<std::endl;
}
};
int main ()
{
NeobicnaKlasa k1(5);
NeobicnaKlasa k2 = 5;
	return 0;
}