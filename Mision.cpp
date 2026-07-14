#include "Mision.h"

Mision::Mision(int id, const std::string& nombre, const std::string& ubicacion)
    : id(id), nombre(nombre), ubicacion(ubicacion), cantidadRecursos(0) {
}

Mision::~Mision() {
}

int Mision::getId() const {
    return id;
}

const std::string& Mision::getNombre() const {
    return nombre;
}

const std::string& Mision::getUbicacion() const {
    return ubicacion;
}

int Mision::getCantidadRecursos() const {
    return cantidadRecursos;
}

void Mision::asignarRecurso(Recurso* /*recurso*/) {
    // Pendiente
}

void Mision::ejecutar() {
    // Pendiente
}

void Mision::mostrarInfo() const {
    // Pendiente
}
