/* 
    TP 16/17 (LV 9, Zadatak 4)
	
	Testove pisao Kenan Ekinovic. Za sva pitanja, sugestije
	i zalbe obratiti se na mail: kekinovic1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iomanip>
#include <iostream>
#include <stdexcept>

class Sat{
    private:
    int sati, minute, sekunde;

    public:
    static bool DaLiJeIspravno(int sati, int minute, int sekunde){
        if(sati<0 || sati>23 || minute<0 || minute>59 || sekunde<0 || sekunde>59)return false;
        return true;
    }
         void Postavi(int h, int m, int s){
             if(h<0 || h>23 || m<0 || m>59 || s<0 || s>59)
            throw std::domain_error("Neispravno vrijeme");
            sati=h; minute=m; sekunde=s;
           // h=sati; m=minute; s=sekunde;
    }
    void Ispisi()const{
        std::cout<<std::setw(2)<<std::setfill('0')<<sati<<":"
        <<std::setw(2)<<std::setfill('0')<<minute<<":"
        <<std::setw(2)<<std::setfill('0')<<sekunde;
  }
 int DajSate()const{return sati;}
 int DajMinute()const{return minute;}
 int DajSekunde()const{return sekunde;}

 friend int BrojSekundiIzmedju(const Sat &x1, const Sat &x2){
     return (x1.DajSate()*3600+x1.DajMinute()*60+x1.DajSekunde())-(x2.DajSate()*3600+x2.DajMinute()*60+x2.DajSekunde());
 }
 static int Razmak(const Sat &x1, const Sat &x2){
     return (x1.DajSate()*3600+x1.DajMinute()*60+x1.DajSekunde())-(x2.DajSate()*3600+x2.DajMinute()*60+x2.DajSekunde());
 }
  };
int main ()
{
    
  Sat s, s1, s2;
  std::cout<<"Unesite vrijeme: ";
  s.Postavi(10,15,30);
  s.Ispisi();
  std::cout << std::endl;
  s.Postavi(0,4,3);
  std::cout << s.DajSate() << " "
            << s.DajMinute() << " "
            << s.DajSekunde();

  s.Ispisi();
   s2.Postavi(10,10,15);
  std::cout << BrojSekundiIzmedju(s2, s1) << " "
            << Sat::Razmak(s2, s1) << std::endl;
  std::cout << BrojSekundiIzmedju(s1, s2) << " "
            << Sat::Razmak(s1, s2) << std::endl;
	return 0;
}