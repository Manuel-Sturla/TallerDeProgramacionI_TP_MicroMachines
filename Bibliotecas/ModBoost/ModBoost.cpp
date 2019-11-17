//
// Created by manfer on 28/10/19.
//
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "ModBoost.h"
#include "../Carro.h"

#define PROB_ACTIVAR 100
void activar(void* carro){
	/* initialize random seed: */
  	srand (time(NULL));
  	int numero = rand() % 100;
  	if (numero > PROB_ACTIVAR){
  		return
  	}
    Carro* autito = static_cast<Carro*>(carro);
    autito->darBoost();
}