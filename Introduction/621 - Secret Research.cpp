#include <iostream>
#include <string>

using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  // TODO: fixme.
  size_t n;
  cin>>n;
  string cadena;

  for(size_t i=0;i<n;i++){
    cin>>cadena;
    if(cadena.compare("1")==0 || cadena.compare("4")==0 || cadena.compare("78")==0){
      cout<<"+"<<std::endl;
    }else if(cadena.substr(cadena.length()-2,2)=="35"){
      cout<<"-"<<std::endl;
    }else if(cadena.substr(0,1)=="9" && cadena.substr(cadena.length()-1,1)=="4"){
      cout<<"*"<<std::endl;
    }else{
      cout<<"?"<<std::endl;
    }
  }

  return 0;
}