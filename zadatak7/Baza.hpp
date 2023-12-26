#pragma once
#include "Radnik.hpp"
#include<list>
#include<stdexcept>

class BazaRadnika{
private:
std::list<Radnik> lista;
public:
void ucitaj(std::istream&);
void unos(std::istream&);
bool brisanje(std::string);
void ispisi(std::ostream&);
double prosjecna_plata();
double prosjecna_starost();
};

void BazaRadnika::ucitaj(std::istream& in){
  std::string ime;
  double plata;
  int godine;

  Radnik r;

  while(in>>ime && in>>plata && in>>godine){
  
    r.unesi_ime(ime);
    r.unesi_platu(plata);
    r.unesi_godine(godine); 
    lista.push_back(r);
  }

  std::clearerr(stdin);
  std::cin.clear();

}

double BazaRadnika::prosjecna_plata(){
double result = 0;
for(auto& k : lista){
result = k.plata()+result;
}
return result/lista.size();
}

double BazaRadnika::prosjecna_starost(){
double result = 0;
for(auto& k : lista){
result = k.godine()+result;
}
return result/lista.size();
}


void BazaRadnika::ispisi(std::ostream& out){
for(auto& k : lista){
  out<<k.ime()<<" "<<k.plata()<<" "<<k.godine()<<std::endl;
}
}

void BazaRadnika::unos(std::istream& in){

  std::string ime;
  double plata;
  int godine;

  std::cout<<"Unesite ime radnika: "<<std::endl;
  in>>ime;
  std::cout<<"Unesite platu radnika: "<<std::endl;
  in>>plata;
  std::cout<<"Unesite godine radnika: "<<std::endl;
  in>>godine;

  Radnik r;
  r.unesi_ime(ime);
  r.unesi_platu(plata);
  r.unesi_godine(godine);

  if(lista.empty()){
  lista.push_back(r);
  }else{
    int counter=0;
    for(auto& k : lista){
    if(r==k){
      counter=1;
    }
    }
    if(counter==0){
      std::cout<<"Unos je uspjesan!"<<std::endl;
      lista.push_back(r);
    }else{
      throw(std::domain_error{"Radnik je vec u bazi!"});
    }
  }
}

bool BazaRadnika::brisanje(std::string ime){
  std::list<Radnik>::iterator it1,it2;
  it1 = lista.begin();
  it2 = lista.end();
  Radnik r;

  while(it1!=it2){
    r=*it1;
    if(r.ime()==ime){
      lista.erase(it1);
      break;
    }
    it1++;
  }
  if(it1==it2){
  return false;
  }else{
  return true;
  }

}
