#include <iostream>

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  // TODO: fixme.
  size_t t;
  long int a,b;
  std::cin>>t;
  for(size_t i;i<t;i++){
    std::cin>>a;
    std::cin>>b;
    if(a>b){
      std::cout<<">"<<std::endl;
    }else if(a<b){
      std::cout<<"<"<<std::endl;
    }else{
      std::cout<<"="<<std::endl;
    }
  }

  return 0;
}