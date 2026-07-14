#ifndef HELICOPTERO_H
#define HELICOPTERO_H

#include "Vehiculo.h"

class Helicoptero : public Vehiculo {
public:
    Helicoptero(int id, const std::string& nombre, const std::string& placa, int capacidad);
    ~Helicoptero() override;

    void ejecutar() override;
    void mostrarInfo() const override;
    std::string getTipo() const override;
};

#endif
