/* 
    TP 16/17 (LV 11, Zadatak 2)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>

class StedniRacun{

    double stanje;
    static int brojac_brojkreiranih;
    static int brojac_brojaktivnih;

    public:
    StedniRacun(double pocetna=0){
        if(pocetna<0)throw std::logic_error("Nedozvoljeno pocetno stanje");
        else stanje=pocetna;
        brojac_brojkreiranih++;
        brojac_brojaktivnih++;
      }

   ~StedniRacun(){brojac_brojaktivnih--;}
    static int DajBrojKreiranih(){
        return brojac_brojkreiranih;
    }
    static int DajBrojAktivnih(){
        return brojac_brojaktivnih;
    }
    void Ulozi(double x){
        if(x+stanje<0)throw std::logic_error("Transakcija odbijena");stanje=stanje+x;
    }
    void Podigni(double x){
        if(x>stanje)throw std::logic_error("Transakcija odbijena");stanje=stanje-x;
    }
    double DajStanje(){return stanje;}
    void ObracunajKamatu(double kamatna_s){
        if(kamatna_s<0)throw std::logic_error("Nedozvoljena kamatna stopa");
        double ukupno_stanje;
        ukupno_stanje=stanje*kamatna_s/100;
        stanje+=ukupno_stanje;
    }
 
};

int StedniRacun::brojac_brojaktivnih=0;
int StedniRacun::brojac_brojkreiranih=0;

int main(){
StedniRacun s1(1), s2(100);
{ StedniRacun s3(50); } // Nakon "}", "s3" više ne postoji...
std::cout << StedniRacun::DajBrojKreiranih()
 << " " << StedniRacun::DajBrojAktivnih();
	return 0;
}