#include "Baza.hpp"

int main(int argc, char *argv[])
{
  BazaRadnika b1;

  std::cout<<"Unos: "<<std::endl;
  b1.ucitaj(std::cin);
  std::cout<<"Ispis: "<<std::endl;
  b1.ispisi(std::cout);

  std::cout<<"Unos pojedinacnog radnika: "<<std::endl;
  try{b1.unos(std::cin);}catch(std::domain_error err){std::cout<<err.what()<<std::endl;};
  b1.ispisi(std::cout);
  std::string ime_za_brisanje;
  std::cout<<"Unesite ime koje zelite ukloniti: "<<std::endl;
  std::cin>>ime_za_brisanje;
  bool a = b1.brisanje(ime_za_brisanje);
  if(a){
    std::cout<<"Radnik obrisan: "<<std::endl;
  }
  b1.ispisi(std::cout);
  double p_plata,p_starost;
  p_plata = b1.prosjecna_plata();
  p_starost = b1.prosjecna_starost();

  std::cout<<"Prosjecna plata: "<<p_plata<<std::endl;
  std::cout<<"Prosjecna starost: "<<p_starost<<std::endl;


  return 0;
}
