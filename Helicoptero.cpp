#include "Helicoptero.h"
#include <iostream>

Helicoptero::Helicoptero(int id, const std::string& nombre, const std::string& placa, int capacidad)
    : Vehiculo(id, nombre, placa, capacidad) {
}

Helicoptero::~Helicoptero() {
}

void Helicoptero::ejecutar() {
    std::cout << "  [" << nombre << "] Realizando extraccion aerea" << std::endl;
}

void Helicoptero::mostrarInfo() const {
    std::cout << "  [Helicoptero] ID: " << id
              << " | Nombre: " << nombre
              << " | Matricula: " << placa
              << " | Capacidad: " << capacidad
              << " | Disponible: " << (disponible ? "Si" : "No") << std::endl;
}

std::string Helicoptero::getTipo() const {
    return "Helicoptero";
}
