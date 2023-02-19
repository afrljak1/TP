/* 
    TP 2018/2019: LV 6, Zadatak 4
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/
#include <exception>
#include <iostream>
#include <new>
#include <stdexcept>

int **KreirajTrougao(int n){
    
        if(n<=0)throw std::domain_error("Broj redova mora biti pozitivan");
        int **pok=nullptr;
        try{
        pok=new int*[n];
         pok[0]=new int[n*n];
         pok[0][0]=1;
           
           for(int i=1; i<n; i++){
               pok[i]=pok[i-1]+(2*i-1);
          // }
          // for(int i=0; i<n; i++){
               for(int j=0; j<2*i+1; j++){
                   if(i==0 && j==0)pok[i][j]=1;
                   else if(j==0)pok[i][j]=i+1;
                   else if(j==(2*i+1)-1)pok[i][j]=pok[i][j-1]+1;
                   else pok[i][j]=pok[i-1][j-1];
               }
           }
           
        }catch(...){
            delete[]pok;
            pok=nullptr;
            throw std::bad_alloc();
        }
        return pok;;
        }
 
int main ()
{
    try{
        int broj_redova;
        std::cout<<"Koliko zelite redova: ";
        std::cin>>broj_redova;
        int **temp=KreirajTrougao(broj_redova);
        for(int i=0; i<broj_redova; i++){
            for(int j=0; j<i*i+1; j++){
                std::cout<<temp[i][j]<<' ';
            }
            std::cout<<std::endl;
        }
    
    }catch(std::domain_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
    }catch(...){
        std::cout<<"Izuzetak: Nedovoljno memorije!"<<std::endl;
    }
	return 0;
}