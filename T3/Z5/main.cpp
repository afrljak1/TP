//TP 2021/2022: LV 3, Zadatak 5
#include <iostream>
#include <cmath>
#include<deque>

std::deque<int> IzdvojiElemente(std::deque<int>broj, bool vrijednost){
    std::deque<int>novi_vektor;
           // for(int i:broj){
               for(int i=broj.size()-1; i>=0; i--){
            int suma=0;
            int n=i;
            while(n!=0){
                suma+=n%10;
                n/=10;
            }
            if(suma%2==0 && vrijednost==1) novi_vektor.push_front(broj.at(i));
            else if(suma%2!=0 && vrijednost==0)novi_vektor.push_front(broj.at(i));
        }
        return novi_vektor;  
}
int main ()
{
    int n;
    std::cout<<"Koliko zelite unijeti elemenata: ";
    std::cin>>n;
    if(n<=0){
        std::cout<<"Broj elemenata mora biti veci od 0!";
        return 0;
    }
    std::cout<<"Unesite elemente: ";
    std::deque<int>a;
    for(int i=0; i<n; i++){
        int elementi;
        std::cin>>elementi;
        a.push_back(elementi);
    }
    std::deque<int>b=IzdvojiElemente(a,true);
    std::deque<int>c=IzdvojiElemente(a,false);
    for(int i=0; i<b.size(); i++)
    if(i<b.size()-1)
    std::cout<<b.at(i)<<",";
    else std::cout<<b.at(i);
    std::cout<<std::endl;
    for(int i=0; i<c.size(); i++)
    if(i<c.size()-1)
    std::cout<<c.at(i)<<",";
    else std::cout<<c.at(i);
    
    /*for(int i:b)std::cout<<i<<" ";
    std::cout<<std::endl;
    for(int i:c)std::cout<<i<<" ";
	return 0;
    */
}

