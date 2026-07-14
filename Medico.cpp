#include "Medico.h"

Medico::Medico(int id, const std::string& nombre, const std::string& especialidad)
    : Personal(id, nombre, especialidad) {
}

Medico::~Medico() {
}

void Medico::ejecutar() {
    // Pendiente
}

void Medico::mostrarInfo() const {
    // Pendiente
}

std::string Medico::getTipo() const {
    return "Medico";
}
