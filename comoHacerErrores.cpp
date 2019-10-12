#include <iostream>
#define S1(x) #x
#define S2(x) S1(x)
#define POSICION __FILE__ " : " S2(__LINE__) 

void miFuncionError(){
	std::string error("Mi error: ");
	error.append(POSICION);
	throw std::runtime_error(error);
}

int main(){
	try{
		miFuncionError();
	} catch(std::runtime_error e){
		std::cout<<e.what()<<'\n';
	}
	return 0;
}