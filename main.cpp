#include<iostream>
#include<stdexcept>
#include<unordered_set>

void print(const auto& set){
	for(const auto& elem : set)std::cout<<elem<<' ';
	std::cout<<std::endl;
}

bool checkConjecture(long long unsigned int num){
	if(num <= 0)throw std::invalid_argument("invalid argument");
	std::unordered_set<long long unsigned int> lst;
	while(1!=num){
		num = (num%2) ? (3*num)+1 : num/2;
		if(lst.contains(num))return false;
		lst.insert(num);
    	}
	return true;
}

void checkConjectureVerbose(long long unsigned int num){
	if(num <= 0)throw std::invalid_argument("invalid argument");
	std::unordered_set<long long unsigned int> lst;
	while(1!=num){
		num=(num%2)?(3*num)+1 : num/2;
		if(lst.contains(num))std::cout<<"Infinite loop with number "<<num<<std::endl;
	}
	std::cout<<"Succeed!"<<std::endl;
}


bool checkRange(long long unsigned int begin, long long unsigned int end){
	for(;begin!=end+1;++begin){
		if(!checkConjecture(begin)) return false;
	}
	return true;
}

void checkRangeVerbose(long long unsigned int begin, long long unsigned int end){
	for(;begin!=end+1;++begin){
		if(!checkConjecture(begin))std::cout<<"Check Failed! Failed number: "<< begin<<std::endl;
	}
	std::cout<<"Succeed!"<<std::endl;
}
void checkRangeFullVerbose(long long unsigned int begin, long long unsigned int end){
	for(;begin!=end+1;++begin){
		std::cout<<"Number: "<<begin<<' ';
		checkConjectureVerbose(begin);
	}
}


int main(){
	
	try{
		std::cout<<checkConjecture(345);
		std::cout<<"checkConjectureVerbose test"<<std::endl;
		checkConjectureVerbose(35);
		std::cout<<"===========\ncheckRangeVerbose test"<<std::endl;
		checkRangeVerbose(65, 145);
		std::cout<<"===========\ncheckRangeFullVerbose test"<<std::endl;
		checkRangeFullVerbose(362, 390);
	}
	catch(const std::invalid_argument& e){std::cout<<e.what()<<std::endl;}
	return 0;
}
