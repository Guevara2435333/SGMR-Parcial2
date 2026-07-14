#include "Mision.h"
#include <iostream>

Mision::Mision(int id, const std::string& nombre, const std::string& ubicacion)
    : id(id), nombre(nombre), ubicacion(ubicacion),
      recursosAsignados(nullptr), cantidadRecursos(0), capacidadRecursos(0) {}

Mision::~Mision() {
    // Solo libera el arreglo de punteros; los recursos viven en el inventario del Controlador
    delete[] recursosAsignados;
    recursosAsignados = nullptr;
    cantidadRecursos = 0;
    capacidadRecursos = 0;
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

void Mision::redimensionarRecursos() {
    int nuevaCapacidad = (capacidadRecursos == 0) ? 2 : capacidadRecursos * 2;
    Recurso** nuevoArreglo = new Recurso*[nuevaCapacidad];

    for (int i = 0; i < cantidadRecursos; i++) {
        nuevoArreglo[i] = recursosAsignados[i];
    }

    delete[] recursosAsignados;
    recursosAsignados = nuevoArreglo;
    capacidadRecursos = nuevaCapacidad;
}

void Mision::asignarRecurso(Recurso* recurso) {
    if (recurso == nullptr) {
        return;
    }

    if (cantidadRecursos >= capacidadRecursos) {
        redimensionarRecursos();
    }

    recursosAsignados[cantidadRecursos] = recurso;
    cantidadRecursos++;
    recurso->setDisponible(false);
}

void Mision::ejecutar() {
    std::cout << "\n=== Ejecutando mision: " << nombre
              << " (" << ubicacion << ") ===" << std::endl;

    if (cantidadRecursos == 0) {
        std::cout << "  No hay recursos asignados a esta mision." << std::endl;
        return;
    }

    for (int i = 0; i < cantidadRecursos; i++) {
        if (recursosAsignados[i] != nullptr) {
            recursosAsignados[i]->ejecutar();
        }
    }

    std::cout << "=== Fin de la mision ===" << std::endl;
}

void Mision::mostrarInfo() const {
    std::cout << "  [Mision] ID: " << id
              << " | Nombre: " << nombre
              << " | Ubicacion: " << ubicacion
              << " | Recursos asignados: " << cantidadRecursos << std::endl;

    for (int i = 0; i < cantidadRecursos; i++) {
        if (recursosAsignados[i] != nullptr) {
            std::cout << "    -> ";
            recursosAsignados[i]->mostrarInfo();
        }
    }
}
