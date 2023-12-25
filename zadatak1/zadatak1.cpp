#include <vector>
#include <iostream>

template<typename K, typename F>
K filter(const K& kont, F fun){
K result_;
typename K::const_iterator it1 = kont.begin();
while(it1!=kont.end()){
if(fun(*it1))
  result_.push_back(*it1);
it1++;
}
return result_;
}

int main(int argc, char *argv[])
{
  std::vector<int>v1{1,4,5,8,11,13,14,19,20};
  std::vector<int> rez;

  auto lam = [&](int num){return num%2==0;};

  rez = filter(v1,lam);

  for(const auto& k : rez){
    std::cout<<k<<" ";
  }
  
  return 0;
}
