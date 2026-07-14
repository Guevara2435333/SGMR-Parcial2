#include "Vehiculo.h"

Vehiculo::Vehiculo(int id, const std::string& nombre, const std::string& placa, int capacidad)
    : Recurso(id, nombre), placa(placa), capacidad(capacidad) {
}

Vehiculo::~Vehiculo() {
}

const std::string& Vehiculo::getPlaca() const {
    return placa;
}

int Vehiculo::getCapacidad() const {
    return capacidad;
}
