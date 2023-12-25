#include<iostream>
#include<list>

template<typename K, typename F, typename T>
T reduce(K kont, F fun, T element){
typename K::iterator it1 = kont.begin();
typename K::iterator it2 = kont.end();

T result;
while(it1!=it2){
if(it1==kont.begin()){
result = fun(element,*it1);
}else{
result = fun(result,*it1);
}
it1++;
}
return result;
}

int main(int argc, char *argv[])
{
  std::list<int> list1{11,4,5,12,6,8,9};

  auto lam = [&](int a, int b){return a+b+1;};

  int start = -12;

  std::cout<<"Output: "<<reduce(list1, lam, start);

  
  return 0;
}
