//
// Created by manfer on 28/10/19.
//
#include <stdlib.h>
#include <time.h>

#include "ModBoost.h"

#define PROB_ACTIVAR 100
void activar(CarroDTO_t* carro){
  	srand (time(NULL));
  	int numero = rand() % 100;
  	if (numero > PROB_ACTIVAR){
  		return;
  	}
    carro->boost = true;
}