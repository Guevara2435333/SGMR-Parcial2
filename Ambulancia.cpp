#include "Ambulancia.h"
#include <iostream>

Ambulancia::Ambulancia(int id, const std::string& nombre, const std::string& placa, int capacidad)
    : Vehiculo(id, nombre, placa, capacidad) {
}

Ambulancia::~Ambulancia() {
}

void Ambulancia::ejecutar() {
    std::cout << "  [" << nombre << "] Transportando paciente via terrestre" << std::endl;
}

void Ambulancia::mostrarInfo() const {
    std::cout << "  [Ambulancia] ID: " << id
              << " | Nombre: " << nombre
              << " | Placa: " << placa
              << " | Capacidad: " << capacidad
              << " | Disponible: " << (disponible ? "Si" : "No") << std::endl;
}

std::string Ambulancia::getTipo() const {
    return "Ambulancia";
}
