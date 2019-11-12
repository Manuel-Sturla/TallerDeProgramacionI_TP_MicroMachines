//
// Created by manfer on 10/11/19.
//

#ifndef SERVIDOR_EVENTOSPARSEABLES_H
#define SERVIDOR_EVENTOSPARSEABLES_H


#include <vector>
#include <string>
#define MSJ_FIN "F"
#define SEPARADOR ';'

class EventoParseable {

public:
    virtual std::string obtenerParseado() = 0;

};


#endif //SERVIDOR_EVENTOSPARSEABLES_H
