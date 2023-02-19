/* 
    TP 16/17 (LV 11, Zadatak 4)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <initializer_list>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdexcept>


class Tim{
char ime_tima[20];
int broj_odigranih, broj_pobjeda, broj_nerijesenih, broj_poraza, broj_datih, broj_primljenih, broj_poena;
public:
Tim(const char ime[]):broj_odigranih(0), broj_pobjeda(0), broj_nerijesenih(0), broj_poraza(0), broj_datih(0), broj_primljenih(0), broj_poena(0){
    if(strlen(ime)>20)throw std::range_error("Predugacko ime tima");
    strncpy(ime_tima, ime, 20);
}
void ObradiUtakmicu(int broj_datih, int broj_primljenih);
const char *DajImeTima()const{return ime_tima;}
int DajBrojPoena()const{return broj_poena;}
int DajGolRazliku()const{return broj_datih-broj_primljenih;}
void IspisiPodatke()const{std::cout<<std::left<<std::setw(20)<<ime_tima<<std::right<<std::setw(4)<<broj_odigranih<<std::setw(4)<<broj_pobjeda<<std::setw(4)<<broj_nerijesenih<<std::setw(4)<<broj_poraza<<std::setw(4)<<broj_datih<<std::setw(4)<<broj_primljenih<<std::setw(4)<<broj_poena<<std::endl;}
};
void Tim::ObradiUtakmicu(int broj_datih, int broj_primljenih){
    if(broj_datih<0 || broj_primljenih<0)throw 
    std::range_error("Neispravan broj golova");
    broj_odigranih++;
    Tim::broj_datih+=broj_datih;
    Tim::broj_primljenih+=broj_primljenih;
   if(broj_datih>broj_primljenih){
       broj_pobjeda++;
       broj_poena+=3;
   }else if(broj_datih<broj_primljenih){
       broj_poraza++;
   }else{
       broj_nerijesenih++;
       broj_poena++;
   }
}

class Liga{
    private:
    int broj_timova;
    const int max_br_timova;
    Tim** timovi;

    public:
    explicit Liga(int velicina_lige):broj_timova(0), max_br_timova(velicina_lige), timovi(new Tim*[velicina_lige]){
        for(int i=0; i<velicina_lige; i++)timovi[i]=nullptr;
    }

    
    //explicit Liga(std::initializer_list<Tim>lista_timova){

    
    ~Liga(){
        for(int i=0; i<broj_timova; i++)delete timovi[i];
        delete [] timovi;
    }
  //  Liga(const Liga &l){

   // }
    Liga(Liga &l):max_br_timova(l.max_br_timova), broj_timova(l.broj_timova), timovi(new Tim*[l.max_br_timova]){
        for(int i=0; i<max_br_timova; i++)timovi[i]=nullptr;
        try{
            for(int i=0; i<broj_timova; i++)
            timovi[i]=new Tim(*l.timovi[i]);
        }catch(...){
            for(int i=0; i<max_br_timova; i++)
            delete timovi[i];
            delete []timovi;
            throw;
        }
    }

    Liga(const Liga &&l):max_br_timova(l.max_br_timova), broj_timova(l.broj_timova){
        timovi=l.timovi;
      //  l.timovi=nullptr;
    }
    Liga &operator=(const Liga &l){
        if(&l!=this){
            if(max_br_timova!=l.max_br_timova)
            throw std::logic_error("Nesaglasni kapacitet liga");
            for(int i=0; i<l.broj_timova; i++)
            *timovi[i]=*l.timovi[i];
            broj_timova=l.broj_timova;
        }
        return *this;
    }
    Liga &operator=(Liga &&l);
    void DodajNoviTim(const char ime_tima[]){
        if(broj_timova==max_br_timova)throw std::range_error("Liga popunjena");
    if(strlen(ime_tima)>20)throw std::range_error("Predugacko ime tima");
    }
    void RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2){

    }
    void IspisiTabelu();

};

int main ()
{

	return 0;
}