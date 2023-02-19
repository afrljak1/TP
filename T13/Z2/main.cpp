/* 
    TP 16/17 (LV 13, Zadatak 2)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>

class ApstraktniStudent{
    private:
    std::string ime, prezime;
    int indeks, br_polozenih;
    double prosjek;
    public:
    ApstraktniStudent(std::string ime, std::string prezime, int indeks):
    ime(ime), prezime(prezime), indeks(indeks), br_polozenih(0), prosjek(5){}
    virtual ~ApstraktniStudent(){};

    std::string DajIme() const{return ime;}
    std::string DajPrezime()const{return prezime;}
    int DajBrojIndeksa()const{return indeks;}
    int DajBrojPolozenih()const{return br_polozenih;}
    double DajProsjek()const{return prosjek;}

    void RegistrirajIspit(double ocjena){
        if(ocjena<5 || ocjena>10)throw std::domain_error("Neispravna ocjena");
        if(ocjena>5 ){
            double ukupno=prosjek*br_polozenih;
            //ukupno+=ocjena;
            br_polozenih++;
            prosjek=(ukupno+ocjena)/br_polozenih;
        }
    }
    void PonistiOcjene(){
        br_polozenih=0;
        prosjek=5;
    }
    virtual void IspisiPodatke()const=0;
    virtual ApstraktniStudent* DajKopiju()const=0;
};
class StudentBachelor:public ApstraktniStudent{

public:
StudentBachelor(std::string ime,std::string prezime, int indeks):ApstraktniStudent(ime, prezime, indeks){}
void IspisiPodatke() const override{
    std::cout<<"Student bachelor studija "<<DajIme()<<" "<<DajPrezime()<<", sa brojem indeksa "<<DajBrojIndeksa()<<","<<std::endl<<"ima prosjek "<<DajProsjek()<<"."<<std::endl;
}
StudentBachelor *DajKopiju() const override{
    return new StudentBachelor(*this);
}
};

class StudentMaster:public ApstraktniStudent{
    private:
    int godina_z;
    public:
    StudentMaster(std::string ime, std::string prezime, int indeks, int godina_z):ApstraktniStudent(ime, prezime, indeks), godina_z(godina_z){}
    void IspisiPodatke()const override{
        std::cout<<"Student master studija "<<DajIme()<<" "<<DajPrezime()<<", sa brojem indeksa "<<DajBrojIndeksa()<<","<<std::endl<<"zavrsio bachelor studij godine "<<godina_z<<",ima prosjek "<<DajProsjek()<<"."<<std::endl;}
        ApstraktniStudent* DajKopiju()const override{
            return new StudentMaster(*this);
        }
};

int main ()
{
 /*class Medjed : public ApstraktniStudent {
public:
  Medjed() : ApstraktniStudent("", "", 0) {}
  ~Medjed() { std::cout << "Pozvan ispravan destruktor!\n"; };
  void IspisiPodatke() const {};
  ApstraktniStudent *DajKopiju() const {};
};
*/
	return 0;
}