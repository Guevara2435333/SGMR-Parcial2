#include "Recurso.h"

Recurso::Recurso(int id, const std::string& nombre)
    : id(id), nombre(nombre), disponible(true) {
}

Recurso::~Recurso() {
}

int Recurso::getId() const {
    return id;
}

const std::string& Recurso::getNombre() const {
    return nombre;
}

bool Recurso::getDisponible() const {
    return disponible;
}

void Recurso::setDisponible(bool estado) {
    disponible = estado;
}
