#include <iostream>

bool checkConjecture(long long unsigned int num){
    while(1!=num){
        num = (num%2) ? num=(3*num)+1 : num/=2;
    }
    return true;
}

bool checkRange(long long unsigned int begin, long long unsigned int end){
    for(begin;begin!=end+1;++begin){
        if(!checkConjecture(begin)) return false;
    }
    return true;
}

int main(){
    std::cout<<checkRange(2, 10)<<std::endl;
    return 0;
}
