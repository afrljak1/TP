//TP 2016/2017: LV 1, Zadatak 4
#include <iostream>
#include <cmath>
int main ()
{
    double broj;
   for(;;){
    std::cout<<"Unesite prirodan broj ili 0 za kraj: ";
    //std::cin>>broj;
    if( !(std::cin>>broj) || broj<0 || int(broj)!=broj){
        std::cout<<"Niste unijeli prirodan broj!"<<std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        continue;
    }
    if(broj==0){
        std::cout<<"Dovidjenja!";
        return 0;
    }
    
    
    int suma(0);
    for(int i=1; i<broj; i++){
        if(int(broj)%i==0)
        suma+=i;
    }
  
    if(suma<broj){
        std::cout<<"Broj "<<broj<<" je manjkav!"<<std::endl;
    }else if(suma>broj){
        std::cout<<"Broj "<<broj<<" je obilan!"<<std::endl;
    }else if(suma==broj){
        std::cout<<"Broj "<<broj<<" je savrsen!"<<std::endl;
            }
   }

	return 0;
}