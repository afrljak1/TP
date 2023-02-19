/* 
    TP 16/17 (LV 13, Zadatak 1)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <memory>

const double PI=4*std::atan(1);

class Lik{
public: 
   virtual ~Lik(){}

    virtual void IspisiSpecificnosti()=0;
    virtual double DajObim()const=0;
    virtual double DajPovrsinu()const=0;
    virtual void Ispisi()=0;
    //virtual ~Lik(){}
    

};
class Krug:public Lik{
    private:
    double r;
    public:
    Krug(double r):r(r){
        if(r<=0)throw std::domain_error("Neispravni parametri");
    }
   
    double DajPovrsinu() const{
        return (r*r)*PI;
    }
    double DajObim() const{
        return 2*r*PI;
    }
    void IspisiSpecificnosti(){
                std::cout<<"Krug poluprecnika "<<r<<std::endl;
    }
    void Ispisi(){
        IspisiSpecificnosti();
        std::cout<<"Obim: "<<DajObim()<<" Povrsina: "<<DajPovrsinu()<<std::endl;
    }
};
class Pravougaonik: public Lik{
    private:
    double a, b;
    public:
    Pravougaonik(double a, double b):a(a), b(b){
        if(a<=0 || b<=0)throw std::domain_error("Neispravni parametri");
    }
    
    double DajPovrsinu()const{
        return a*b;
    }
    double DajObim()const{
        return 2*(a+b);
    }
    void IspisiSpecificnosti(){
        std::cout<<"Pravougaonik sa stranicama duzine "<<a<<" i "<<b<<std::endl;
    }
    void Ispisi(){
        IspisiSpecificnosti();
        std::cout<<"Obim: "<<DajObim()<<" Povrsina: "<<DajPovrsinu()<<std::endl;
    }
};
class Trougao:public Lik{
    private:
    double a, b, c;
    public:
    Trougao(double a, double b, double c):a(a), b(b), c(c){
        if(a<=0 || b<=0 || c<=0 || (a+b)<=c || (a+c)<=b || (b+c)<=a){
            throw std::domain_error("Neispravni parametri");
        }

    }
    
    double DajPovrsinu()const{
        //return (a*b)/2;
        double s;
        s=(a+b+c)/2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
    double DajObim()const{
        return a+b+c;
    }
    void IspisiSpecificnosti(){
        std::cout<<"Trougao sa stranicama duzine "<<a<<", "<<b<<" i "<<c<<std::endl;
    }
    void Ispisi(){
        IspisiSpecificnosti();
        std::cout<<"Obim: "<<DajObim()<<" Povrsina: "<<DajPovrsinu()<<std::endl;
    }
};

int main(){
    /*klasa krug
	std::vector<std::shared_ptr<Lik>> krugovi;
		try{
			krugovi.push_back(std::make_shared<Krug>(-5));
		}
		catch(std::domain_error e){
			std::cout << e.what() << std::endl;
		}
		try{
			krugovi.push_back(std::make_shared<Krug>(0));
		}
		catch(std::domain_error e){
			std::cout << e.what() << std::endl;
		}
		try{
			krugovi.push_back(std::make_shared<Krug>(10));
		}
		catch(std::domain_error e){
			std::cout << e.what() << std::endl;
		}
		try{
			krugovi.push_back(std::make_shared<Krug>(5.1));
		}
		catch(std::domain_error e){
			std::cout << e.what() << std::endl;
		}
	for(auto x : krugovi) x->Ispisi();
    */
    
    int n;
    std::cout<<"Koliko zelite likova: "<<std::endl;
    std::cin>>n;
    char unos;
    double a, b, c,r;
    std::vector<std::shared_ptr<Lik>>lik(n);
    for(int i=0; i<n; i++){
        std::cout<<"Lik "<<i+1<<":";
        unos=std::cin.get();
        switch(unos){
        case 'K':
            std::cin>>r;
            if(!std::cin){
                throw std::domain_error("Pogresni podaci, ponovite unos!");
            }
            lik[i]=std::make_shared<Krug>(Krug(r));
            i++;
            break;
        
        }
    }
    
    return 0;
}