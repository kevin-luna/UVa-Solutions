#include <iostream>
#include <string>

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  // TODO: fixme.
  std::string sentence;
  size_t posdquotes,cdquotes=0;

  while(std::getline(std::cin,sentence)){

    while((posdquotes=sentence.find_first_of("\""))<sentence.length()){
      ++cdquotes;
      if(cdquotes%2){
        sentence.replace(posdquotes,1,"``");
      }else{
        sentence.replace(posdquotes,1,"\'\'");
      }
      ++posdquotes;
    }
    std::cout<<sentence<<std::endl;
  }

  return 0;
}