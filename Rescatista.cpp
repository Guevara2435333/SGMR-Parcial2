#include "Rescatista.h"
#include <iostream>

Rescatista::Rescatista(int id, const std::string& nombre, const std::string& especialidad)
    : Personal(id, nombre, especialidad) {
}

Rescatista::~Rescatista() {
}

void Rescatista::ejecutar() {
    std::cout << "  [" << nombre << "] Buscando sobrevivientes en escombros" << std::endl;
}

void Rescatista::mostrarInfo() const {
    std::cout << "  [Rescatista] ID: " << id
              << " | Nombre: " << nombre
              << " | Especialidad: " << especialidad
              << " | Disponible: " << (disponible ? "Si" : "No") << std::endl;
}

std::string Rescatista::getTipo() const {
    return "Rescatista";
}
