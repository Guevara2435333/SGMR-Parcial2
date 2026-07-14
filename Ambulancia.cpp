#include "Ambulancia.h"

Ambulancia::Ambulancia(int id, const std::string& nombre, const std::string& placa, int capacidad)
    : Vehiculo(id, nombre, placa, capacidad) {
}

Ambulancia::~Ambulancia() {
}

void Ambulancia::ejecutar() {
    // Pendiente
}

void Ambulancia::mostrarInfo() const {
    // Pendiente
}

std::string Ambulancia::getTipo() const {
    return "Ambulancia";
}
