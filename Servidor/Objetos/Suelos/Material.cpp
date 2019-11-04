#include "Material.h"

void Material::empaquetarMaterial(std::vector<std::string> *destino) {
  destino -> emplace_back(id);
}
