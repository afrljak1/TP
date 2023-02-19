//TP 2021/2022: LV 8, Zadatak 1
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <iomanip>

struct Vrijeme{
    int sati, minute, sekunde;
};

void TestirajVrijeme(const Vrijeme &vrijeme){
    if(vrijeme.sati<0 || vrijeme.minute<0 || vrijeme.sekunde<0 || vrijeme.sati>23 || vrijeme.minute>59 || vrijeme.sekunde>59){
        throw std::domain_error("Neispravno vrijeme");
    }
}

void IspisiVrijeme(const Vrijeme &vrijeme){
    TestirajVrijeme(vrijeme);
    std::cout<<std::setfill('0')<<std::setw(2)<<vrijeme.sati<<":"<<std::setfill('0')<<std::setw(2)<<vrijeme.minute<<":"<<std::setfill('0')<<std::setw(2)<<vrijeme.sekunde<<std::endl;
}

Vrijeme SaberiVrijeme(const Vrijeme &vrijeme1, const Vrijeme &vrijeme2){
    try{
        TestirajVrijeme(vrijeme1);
        TestirajVrijeme(vrijeme2);
    }catch(std::domain_error poruka)
{
std::cout<<poruka.what()<<std::endl;
}

Vrijeme rezultat{vrijeme1.sati+vrijeme2.sati, vrijeme1.minute+vrijeme2.minute, vrijeme1.sekunde+vrijeme2.sekunde};

if(rezultat.sekunde>=60)rezultat.sekunde%=60, rezultat.minute++;
if(rezultat.minute>=60)rezultat.minute=rezultat.minute%60, rezultat.sati++;
if(rezultat.sati>=23)rezultat.sati=rezultat.sati%24;
return rezultat;
}

int main ()
{
    try{
    Vrijeme vrijeme1, vrijeme2;
    std::cout<<"Unesite prvo vrijeme (h m s): ";
    std::cin>>vrijeme1.sati>>vrijeme1.minute>>vrijeme1.sekunde;
    TestirajVrijeme(vrijeme1);
    std::cout<<"Unesite drugo vrijeme (h m s): ";
    std::cin>>vrijeme2.sati>>vrijeme2.minute>>vrijeme2.sekunde;
    TestirajVrijeme(vrijeme2);
    std::cout<<"Prvo vrijeme: ";
    IspisiVrijeme(vrijeme1);
    std::cout<<"Drugo vrijeme: ";
    IspisiVrijeme(vrijeme2);
    std::cout<<"Zbir vremena: ";
    IspisiVrijeme(SaberiVrijeme(vrijeme1, vrijeme2));
    }catch(std::domain_error poruka){
        std::cout<<poruka.what()<<std::endl;
    }
	return 0;
}
