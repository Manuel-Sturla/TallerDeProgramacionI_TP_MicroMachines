#include <iostream>

class ExcepcionConPos : public std::runtime_error {
private:
	static std::string crearMensaje(const char* archivo, int linea, std::string& mensaje){
		std::string falla("Error: " + mensaje);
		falla.append(" en el archivo: ");
		falla.append(archivo);
		falla.append(" en la linea: ");
		falla.append(std::to_string(linea));
		return falla;
	}

public:
	ExcepcionConPos(const char* archivo, int linea, std::string mensaje) 
	: std::runtime_error(crearMensaje(archivo, linea, mensaje)) {}
	
};

void miFuncionError(){
	throw ExcepcionConPos(__FILE__, __LINE__, "mi mensaje");
}

int main(){
	try{
		miFuncionError();
	} catch(std::runtime_error e){
		std::cout<<e.what()<<'\n';
	}
	return 0;
}