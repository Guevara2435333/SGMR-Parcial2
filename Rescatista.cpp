#include "Rescatista.h"

Rescatista::Rescatista(int id, const std::string& nombre, const std::string& especialidad)
    : Personal(id, nombre, especialidad) {
}

Rescatista::~Rescatista() {
}

void Rescatista::ejecutar() {
    // Pendiente
}

void Rescatista::mostrarInfo() const {
    // Pendiente
}

std::string Rescatista::getTipo() const {
    return "Rescatista";
}
