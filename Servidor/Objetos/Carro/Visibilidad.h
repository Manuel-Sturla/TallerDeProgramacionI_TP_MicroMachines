#ifndef _VISIBILIDAD_H_
#define _VISIBILIDAD_H_


#include <string>
#include <vector>

class Visibilidad {
  private:
    bool visibilidadReducida;
    int duracion;

    void actualizarVisibilidadReducida();
  public:
    Visibilidad();

    void reducirVisibilidad();

    void actualizar();

    void empaquetar(std::vector<std::string> *destino);

    ~Visibilidad();
};


#endif
