#include <iostream>
#include <list>

template<typename K, typename F>
K map(K& kont, F fun){
typename K::iterator it1,it2;
it1 = kont.begin();
it2 = kont.end();

K rez;

while(it1!=it2){
rez.push_back(fun(*it1));
it1++;
}
return rez;
}

int main(int argc, char *argv[])
{

  std::list<int> lista{1,5,6,11,7};
  std::list<int> rez;

  auto lam = [&](int num){return num*2;};
  rez = map(lista,lam);
  for(auto& k : rez){
    std::cout<<k<<" ";
  }
  
  return 0;
}
