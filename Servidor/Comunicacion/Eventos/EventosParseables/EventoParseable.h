#ifndef SERVIDOR_EVENTOSPARSEABLES_H
#define SERVIDOR_EVENTOSPARSEABLES_H


#include <vector>
#include <string>
#define SEPARADOR ';'

class EventoParseable {

public:
    virtual std::string obtenerParseado() = 0;

};


#endif //SERVIDOR_EVENTOSPARSEABLES_H
