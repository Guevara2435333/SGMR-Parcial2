#ifndef MEDICO_H
#define MEDICO_H

#include "Personal.h"

class Medico : public Personal {
public:
    Medico(int id, const std::string& nombre, const std::string& especialidad);
    ~Medico() override;

    void ejecutar() override;
    void mostrarInfo() const override;
    std::string getTipo() const override;
};

#endif
