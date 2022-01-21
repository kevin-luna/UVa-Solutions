#include <iostream>

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  // TODO: fixme.
  size_t n,f;
  std::cin>>n;
  long int a,b,c,arr[21];
  for(size_t cases=0;cases<n;cases++){
    std::cin>>f;
    arr[cases]=0;
    for(size_t farmers=0;farmers<f;farmers++){
      std::cin>>a;
      std::cin>>b;
      std::cin>>c;
      arr[cases]+=a*c;
    }
  }

  for(size_t cases=0;cases<n;cases++){
    std::cout<<arr[cases]<<std::endl;
  }

  return 0;
}