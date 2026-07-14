#include "Medico.h"
#include <iostream>

Medico::Medico(int id, const std::string& nombre, const std::string& especialidad)
    : Personal(id, nombre, especialidad) {
}

Medico::~Medico() {
}

void Medico::ejecutar() {
    std::cout << "  [" << nombre << "] Estabilizando signos vitales" << std::endl;
}

void Medico::mostrarInfo() const {
    std::cout << "  [Medico] ID: " << id
              << " | Nombre: " << nombre
              << " | Especialidad: " << especialidad
              << " | Disponible: " << (disponible ? "Si" : "No") << std::endl;
}

std::string Medico::getTipo() const {
    return "Medico";
}
