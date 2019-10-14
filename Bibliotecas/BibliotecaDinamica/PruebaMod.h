#ifndef PRUEBA_MOD_H
#define PRUEBA_MOD_H

#include <vector>
class PruebaMod{
	int modificador = 3;
	std::vector<int>& numeros;
public:
	PruebaMod(std::vector<int>& v);
	void activar();
};

#endif