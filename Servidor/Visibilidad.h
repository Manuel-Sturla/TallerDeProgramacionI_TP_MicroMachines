#ifndef _VISIBILIDAD_H_
#define _VISIBILIDAD_H_


class Visibilidad {
  private:
    bool visibilidadReducida;
    int duracion;

    void actualizarVisibilidadReducida();
  public:
    Visibilidad();

    void reducirVisibilidad();

    void actualizar();

    ~Visibilidad();
};


#endif
