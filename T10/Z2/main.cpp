/* 
    TP 16/17 (LV 10, Zadatak 2)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iomanip>
#include <ios>
#include <iostream>
#include <math.h>
#include <stdexcept>
 const double PI=4*atan(1);
class Krug{
    double poluprecnik;
    public:
    explicit Krug(double r){
        if(r<=0)throw std::domain_error("Neispravan poluprecnik");poluprecnik=r;
    }
    void Postavi(double x){
        if(x<=0)throw std::domain_error("Neispravan poluprecnik");poluprecnik=x;
    }
    double DajPoluprecnik()const{return poluprecnik;
    }
    double DajObim() const{
        return 2*poluprecnik*PI;
    }
    double DajPovrsinu()const{
        return (PI*pow(poluprecnik,2));
    }
    void Skaliraj(double faktor_skaliranja){
        poluprecnik=poluprecnik*faktor_skaliranja;
        if(faktor_skaliranja<=0)throw std::domain_error("Neispravan faktor skaliranja");
    }
    void Ispisi()const{
        std::cout<<"R="<<std::fixed<<std::setprecision(5)<<DajPoluprecnik()<<" O="<<std::fixed<<std::setprecision(5)<<DajObim()<<" P="<<std::fixed<<std::setprecision(5)<<DajPovrsinu();
    }
};

class Valjak{
    Krug baza;
    double visina=0;
    public:
    explicit Valjak(double r, double h):baza(r){
        if(h<0)throw std::domain_error("Neispravna visina");
        if(r<0)throw std::domain_error("Neispravan poluprecnik");
        visina=h;
       // baza=r;
    }
    void Postavi(double a, double h){
        if(a<0)throw std::domain_error("Neispravan poluprecnik");
        if(h<0)throw std::domain_error("Neispravna visina");
        baza.Postavi(a);
        visina=h;
    }
    Krug DajBazu()const{return baza;}
    double DajPoluprecnikBaze()const{return baza.DajPoluprecnik();}
    double DajVisinu()const{return visina;}
    double DajPovrsinu()const{
        return (2*baza.DajPovrsinu())+(visina*baza.DajObim());
    }
    double DajZapreminu()const{
        return baza.DajPovrsinu()*visina;
    }
    void Skaliraj(double faktor_skaliranja){
        if(faktor_skaliranja<=0)throw std::domain_error("Neispravan faktor skaliranja");
        //faktor_skaliranja=faktor_skaliranja* (visina*baza.DajPoluprecnik());
        baza.Skaliraj(faktor_skaliranja);
    }
    void Ispisi()const;
};
    void Valjak::Ispisi() const{
        std::cout<<"R="<<std::fixed<<std::setprecision(5)<<DajPoluprecnikBaze()<<" H="<<std::fixed<<std::setprecision(5)<<DajVisinu()<<" P="<<std::fixed<<std::setprecision(5)<<DajPovrsinu()<<" V="<<std::fixed<<std::setprecision(5)<<DajZapreminu();
    }

int main ()
{
	return 0;
}