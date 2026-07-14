#ifndef AMBULANCIA_H
#define AMBULANCIA_H

#include "Vehiculo.h"

class Ambulancia : public Vehiculo {
public:
    Ambulancia(int id, const std::string& nombre, const std::string& placa, int capacidad);
    ~Ambulancia() override;

    void ejecutar() override;
    void mostrarInfo() const override;
    std::string getTipo() const override;
};

#endif
