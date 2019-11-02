//
// Created by manfer on 1/11/19.
//

#ifndef PROTOCOLO_COMANDO_H
#define PROTOCOLO_COMANDO_H

#define MSJ_FIN "F"
#define SEPARADOR ';'


class Comando {
public:
    virtual void ejecutar() = 0;
    ~Comando() = default;
};


#endif //PROTOCOLO_COMANDO_H
