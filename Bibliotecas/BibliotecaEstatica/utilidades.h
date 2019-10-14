#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <vector>
class Sumador {
	std::vector<int>& nums;
public:
	Sumador(std::vector<int>& vector);
	int sumar();
};

#endif