/* 
    TP 16/17 (LV 10, Zadatak 1)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>

class StedniRacun{
    double stanje;
    public:
    StedniRacun(double pocetna=0){
        if(pocetna<0)throw std::logic_error("Nedozvoljeno pocetno stanje");
        stanje=pocetna;
    }
    void Ulozi(double x){
        if(x+stanje<0)throw std::logic_error("Transakcija odbijena");
        stanje=stanje+x;
    }
    void Podigni(double x){
        if(x>stanje)throw std::logic_error("Transakcija odbijena");
        stanje=stanje-x;
    }
    double DajStanje(){
        return stanje;
        }
    void ObracunajKamatu(double kamatna_s){
        if(kamatna_s<0){
            throw std::logic_error("Nedozvoljena kamatna stopa");
        }
        double ukupno_stanje;
        ukupno_stanje=stanje*kamatna_s/100;
        stanje+=ukupno_stanje;
    }
};
int main(){
    double stanje;
    std::cout<<"Unesite pocetno stanje: ";
    std::cin>>stanje;
    StedniRacun s1=150; 
s1.Podigni(100);
std::cout << s1.DajStanje()<<std::endl;
s1.Podigni(-20);
std::cout << s1.DajStanje()<<std::endl;
s1.Podigni(-20);
std::cout << s1.DajStanje()<<std::endl;
	return 0;
}