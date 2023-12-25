#include <iostream>

template <typename I, typename I1>
bool jednako(I it1, I it2, I1 it3){
while(it1!=it2){
if(*it1!=*it3){
return false;
}
it1++;
it3++;
}
return true;
}

int main(int argc, char *argv[])
{
  std::string str1;
  std::string str2;

  std::cout<<"Unesite rijec: "<<std::endl;
  std::cin>>str1;
  for(int i = str1.size()-1; i>=0; i--){
  str2.push_back(str1[i]);
  }

  bool result = jednako(str1.begin(),str1.end(), str2.begin());
  if(result == true){
    std::cout<<"Rijec je palindrom!"<<std::endl;
  }else{
    std::cout<<"Rijec nije palindrom!"<<std::endl;
  }

  
  return 0;
}
