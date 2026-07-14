#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Recurso.h"
#include "Mision.h"

class Controlador {
private:
    Recurso** inventario;
    int cantidadRecursos;
    int capacidadRecursos;
    int siguienteIdRecurso;

    Mision** misiones;
    int cantidadMisiones;
    int capacidadMisiones;
    int siguienteIdMision;

    void redimensionarInventario();
    void redimensionarMisiones();
    void cargarDatosPrueba();

    void verRecursos() const;
    void verMisiones() const;
    void registrarRecurso();
    void crearMision();
    void asignarRecursoAMision();
    void ejecutarMision();
    void mostrarMenu() const;

    Recurso* buscarRecursoPorId(int id) const;
    Mision* buscarMisionPorId(int id) const;

public:
    Controlador();
    ~Controlador();

    void iniciar();
};

#endif
