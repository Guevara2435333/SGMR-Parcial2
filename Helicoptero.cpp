#include "Helicoptero.h"

Helicoptero::Helicoptero(int id, const std::string& nombre, const std::string& placa, int capacidad)
    : Vehiculo(id, nombre, placa, capacidad) {
}

Helicoptero::~Helicoptero() {
}

void Helicoptero::ejecutar() {
    // Pendiente
}

void Helicoptero::mostrarInfo() const {
    // Pendiente
}

std::string Helicoptero::getTipo() const {
    return "Helicoptero";
}
