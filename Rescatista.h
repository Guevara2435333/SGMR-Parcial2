#ifndef RESCATISTA_H
#define RESCATISTA_H

#include "Personal.h"

class Rescatista : public Personal {
public:
    Rescatista(int id, const std::string& nombre, const std::string& especialidad);
    ~Rescatista() override;

    void ejecutar() override;
    void mostrarInfo() const override;
    std::string getTipo() const override;
};

#endif
