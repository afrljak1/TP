//TP 2021/2022: LV 4, Zadatak 4
#include <iostream>
#include <cmath>

template <typename NekiTip>void UnosBroja(std::string unos, std::string upozorenje, NekiTip &n){
    NekiTip pom;
  
    while(true){
        std::cout<<unos<<std::endl;
        std::cin>>pom;
        if(!std::cin){
            std::cout<<upozorenje;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout<<std::endl;
        }else{
        if(std::cin.peek()!='\n' && !std::cin.eof()){
            char preostalo=std::cin.get();
            if(preostalo=='.'){
                std::cout<<upozorenje<<std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout<<upozorenje;
                continue;
            }
            }
        
        break;
        }
}
n=pom;
}

int main ()
{
    double n;
    int ekspon;
    UnosBroja("Unesite bazu: ","Neispravan unos, pokusajte ponovo...", n);
    std::cout<<std::endl;
    UnosBroja("Unesite cjelobrojni eksponent: ", "Neispravan unos, pokusajte ponovo...", ekspon);

    auto rezultat=n;
    rezultat=1;
    int broj=ekspon;
    broj=abs(broj);

    for(int i=0; i<broj; i++)rezultat*=n;
    if(ekspon<0) rezultat=1/rezultat;
    std::cout<<n<<" na "<<ekspon<<" iznosi "<<rezultat;
	return 0;
}
