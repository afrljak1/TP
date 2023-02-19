/* 
    TP 2018/2019: LV 6, Zadatak 3
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/
#include <iostream>
#include <new>
#include <stdexcept> 

int **KreirajTrougao(int n){
    if(n<=0){
        throw std::domain_error("Broj redova mora biti pozitivan");
    }
    int **pok=nullptr;
    try{
        try{
            pok=new int*[n];
        }catch(...){
            for(int i=0; i<n; i++)
           delete []pok; 
        }
        for(int i=0; i<n; i++) pok[i]=nullptr;
        for(int i=0; i<n; i++)pok[i]=new int[2*i+1];

        for(int i=0; i<n; i++){
            for(int j=0; j<2*i+1; j++){
                if(j<(2*i+2)/2){
                    pok[i][j]=(i+2)-j-1;
                }else{
                    pok[i][j]=j-i+1;
               }
            }
        }
        return pok;
    }catch(...){
        for(int i=0; i<n; i++)
        delete pok[i]; 
        delete [] pok;
        throw std::bad_alloc();
    }
    //return pok;
}
int main ()
{
    try{
        int broj_redova;
        std::cout<<"Koliko zelite redova: ";
        std::cin>>broj_redova;
        auto matrica=KreirajTrougao(broj_redova);
        for(int i=0; i<broj_redova; i++){
            for(int j=0; j<2*i+1; j++){
                std::cout<<matrica[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
        for(int i=0; i<broj_redova; i++)
        delete [] matrica[i];
        delete [] matrica;
    }catch(std::domain_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
    }catch(std::bad_alloc poruka){
       // std::cout<<"Izuzetak: Nedovoljno memorije!"<<std::endl;
         std::cout<<"Izuzetak: Nedovoljno memorije!"<<std::endl;
    }
	return 0;
}