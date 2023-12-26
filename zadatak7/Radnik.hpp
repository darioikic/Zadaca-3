#pragma once
#include<iostream>

class Radnik{
  private:
  std::string ime_;
  double plata_;
  int godine_;

  public:
  std::string ime(){
  return ime_;
  }
  
  double plata(){
  return plata_;
  }

  double godine(){
  return godine_;
  }

  void unesi_ime(std::string s){
  ime_ = s;
  }

  void unesi_platu(double p){
  plata_ = p;
  }

  void unesi_godine(int g){
  godine_ = g;
  }

  bool operator==(const Radnik& other){
  if(ime_ == other.ime_)
    return true;
  else
    return false;
  }

};
