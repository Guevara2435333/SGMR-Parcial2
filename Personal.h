#ifndef PERSONAL_H
#define PERSONAL_H

#include "Recurso.h"
#include <string>

class Personal : public Recurso {
protected:
    std::string especialidad;

public:
    Personal(int id, const std::string& nombre, const std::string& especialidad);
    virtual ~Personal();

    const std::string& getEspecialidad() const;
};

#endif
