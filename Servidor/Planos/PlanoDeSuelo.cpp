#include <iostream>
#include "PlanoDeSuelo.h"

PlanoDeSuelo::PlanoDeSuelo(std::string unaConfiguracion) {
  configuracion = unaConfiguracion;
  std::cout << configuracion << std::endl;
}
