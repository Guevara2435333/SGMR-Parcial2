#ifndef MISION_H
#define MISION_H

#include "Recurso.h"
#include <string>

class Mision {
private:
    int id;
    std::string nombre;
    std::string ubicacion;
    Recurso** recursosAsignados;
    int cantidadRecursos;
    int capacidadRecursos;

    void redimensionarRecursos();

public:
    Mision(int id, const std::string& nombre, const std::string& ubicacion);
    ~Mision();

    int getId() const;
    const std::string& getNombre() const;
    const std::string& getUbicacion() const;
    int getCantidadRecursos() const;

    void asignarRecurso(Recurso* recurso);
    void ejecutar();
    void mostrarInfo() const;
};

#endif
