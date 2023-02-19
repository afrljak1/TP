/* 
    TP 16/17 (LV 10, Zadatak 4)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
class Ugao{
    double radijani;
    public:
    Ugao(double radijani = 0);
Ugao(int stepeni, int minute, int sekunde){
double rezultat=stepeni+minute/60+sekunde/3600;
}
void Postavi(double radijani);
void Postavi(int stepeni, int minute, int sekunde);
double DajRadijane() const;
void OcitajKlasicneJedinice(int &stepeni, int &minute, int &sekunde);
int DajStepene() const;
int DajMinute() const;
int DajSekunde() const;
void Ispisi() const;
void IspisiKlasicno() const;
Ugao &SaberiSa(const Ugao &u);
Ugao &PomnoziSa(double x);
friend Ugao ZbirUglova(const Ugao &u1, const Ugao &u2){
    return Ugao(u1.radijani+u2.radijani);
}
friend Ugao ProduktUglaSaBrojem(const Ugao &u, double x){
    return Ugao(u.radijani*x);
}
};
int main ()
{
	return 0;
}