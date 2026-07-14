#ifndef VEHICULO_H
#define VEHICULO_H

#include "Recurso.h"
#include <string>

class Vehiculo : public Recurso {
protected:
    std::string placa;
    int capacidad;

public:
    Vehiculo(int id, const std::string& nombre, const std::string& placa, int capacidad);
    virtual ~Vehiculo();

    const std::string& getPlaca() const;
    int getCapacidad() const;
};

#endif
