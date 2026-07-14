#include "Controlador.h"
#include "Ambulancia.h"
#include "Helicoptero.h"
#include "Medico.h"
#include "Rescatista.h"

#include <iostream>
#include <limits>
#include <string>

Controlador::Controlador()
    : inventario(nullptr), cantidadRecursos(0), capacidadRecursos(0), siguienteIdRecurso(1),
      misiones(nullptr), cantidadMisiones(0), capacidadMisiones(0), siguienteIdMision(1) {
    cargarDatosPrueba();
}

Controlador::~Controlador() {
    for (int i = 0; i < cantidadMisiones; i++) {
        delete misiones[i];
        misiones[i] = nullptr;
    }
    delete[] misiones;
    misiones = nullptr;

    for (int i = 0; i < cantidadRecursos; i++) {
        delete inventario[i];
        inventario[i] = nullptr;
    }
    delete[] inventario;
    inventario = nullptr;
}

void Controlador::redimensionarInventario() {
    int nuevaCapacidad = (capacidadRecursos == 0) ? 4 : capacidadRecursos * 2;
    Recurso** nuevo = new Recurso*[nuevaCapacidad];

    for (int i = 0; i < cantidadRecursos; i++) {
        nuevo[i] = inventario[i];
    }

    delete[] inventario;
    inventario = nuevo;
    capacidadRecursos = nuevaCapacidad;
}

void Controlador::redimensionarMisiones() {
    int nuevaCapacidad = (capacidadMisiones == 0) ? 2 : capacidadMisiones * 2;
    Mision** nuevo = new Mision*[nuevaCapacidad];

    for (int i = 0; i < cantidadMisiones; i++) {
        nuevo[i] = misiones[i];
    }

    delete[] misiones;
    misiones = nuevo;
    capacidadMisiones = nuevaCapacidad;
}

void Controlador::cargarDatosPrueba() {
    // 2 ambulancias, 1 helicóptero, 2 médicos, 2 rescatistas, 2 misiones
    if (cantidadRecursos + 7 > capacidadRecursos) {
        while (capacidadRecursos < cantidadRecursos + 7) {
            redimensionarInventario();
        }
    }

    inventario[cantidadRecursos++] = new Ambulancia(siguienteIdRecurso++, "Ambulancia Norte", "ABC-123", 4);
    inventario[cantidadRecursos++] = new Ambulancia(siguienteIdRecurso++, "Ambulancia Sur", "DEF-456", 6);
    inventario[cantidadRecursos++] = new Helicoptero(siguienteIdRecurso++, "Helicoptero Alpha", "HK-789", 8);
    inventario[cantidadRecursos++] = new Medico(siguienteIdRecurso++, "Dra. Maria Lopez", "Trauma");
    inventario[cantidadRecursos++] = new Medico(siguienteIdRecurso++, "Dr. Carlos Ruiz", "Cirugia");
    inventario[cantidadRecursos++] = new Rescatista(siguienteIdRecurso++, "Ana Torres", "Busqueda urbana");
    inventario[cantidadRecursos++] = new Rescatista(siguienteIdRecurso++, "Luis Perez", "Espacios confinados");

    if (cantidadMisiones + 2 > capacidadMisiones) {
        while (capacidadMisiones < cantidadMisiones + 2) {
            redimensionarMisiones();
        }
    }

    misiones[cantidadMisiones++] = new Mision(siguienteIdMision++, "Deslizamiento Cali", "Comuna 18 - Valle del Cauca");
    misiones[cantidadMisiones++] = new Mision(siguienteIdMision++, "Inundacion Yumbo", "Zona industrial - Yumbo");

    // Asignaciones iniciales para probar ejecución de inmediato
    misiones[0]->asignarRecurso(inventario[0]); // Ambulancia Norte
    misiones[0]->asignarRecurso(inventario[2]); // Helicoptero
    misiones[0]->asignarRecurso(inventario[3]); // Dra. Maria
    misiones[0]->asignarRecurso(inventario[5]); // Ana Torres

    misiones[1]->asignarRecurso(inventario[1]); // Ambulancia Sur
    misiones[1]->asignarRecurso(inventario[4]); // Dr. Carlos
    // inventario[6] (Luis Perez) queda disponible para probar la opción 4
}

Recurso* Controlador::buscarRecursoPorId(int id) const {
    for (int i = 0; i < cantidadRecursos; i++) {
        if (inventario[i] != nullptr && inventario[i]->getId() == id) {
            return inventario[i];
        }
    }
    return nullptr;
}

Mision* Controlador::buscarMisionPorId(int id) const {
    for (int i = 0; i < cantidadMisiones; i++) {
        if (misiones[i] != nullptr && misiones[i]->getId() == id) {
            return misiones[i];
        }
    }
    return nullptr;
}

void Controlador::mostrarMenu() const {
    std::cout << "\n========================================" << std::endl;
    std::cout << "  SGMR - Sistema de Gestion de Misiones" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "1. Ver recursos" << std::endl;
    std::cout << "2. Registrar recurso" << std::endl;
    std::cout << "3. Crear Mision" << std::endl;
    std::cout << "4. Asignar recurso a mision" << std::endl;
    std::cout << "5. Ejecutar mision" << std::endl;
    std::cout << "6. Salir" << std::endl;
    std::cout << "Seleccione una opcion: ";
}

void Controlador::verRecursos() const {
    std::cout << "\n--- Inventario de recursos ---" << std::endl;
    if (cantidadRecursos == 0) {
        std::cout << "No hay recursos registrados." << std::endl;
        return;
    }

    for (int i = 0; i < cantidadRecursos; i++) {
        if (inventario[i] != nullptr) {
            inventario[i]->mostrarInfo();
        }
    }

    std::cout << "\n--- Misiones registradas ---" << std::endl;
    verMisiones();
}

void Controlador::verMisiones() const {
    if (cantidadMisiones == 0) {
        std::cout << "No hay misiones registradas." << std::endl;
        return;
    }

    for (int i = 0; i < cantidadMisiones; i++) {
        if (misiones[i] != nullptr) {
            misiones[i]->mostrarInfo();
        }
    }
}

void Controlador::registrarRecurso() {
    int tipo;
    std::string nombre;
    std::string placaOEspecialidad;
    int capacidad = 0;

    std::cout << "\nTipo de recurso:" << std::endl;
    std::cout << "1. Ambulancia" << std::endl;
    std::cout << "2. Helicoptero" << std::endl;
    std::cout << "3. Medico" << std::endl;
    std::cout << "4. Rescatista" << std::endl;
    std::cout << "Opcion: ";
    std::cin >> tipo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (tipo < 1 || tipo > 4) {
        std::cout << "Tipo invalido." << std::endl;
        return;
    }

    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);

    if (tipo == 1 || tipo == 2) {
        std::cout << "Placa/Matricula: ";
        std::getline(std::cin, placaOEspecialidad);
        std::cout << "Capacidad: ";
        std::cin >> capacidad;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
        std::cout << "Especialidad: ";
        std::getline(std::cin, placaOEspecialidad);
    }

    if (cantidadRecursos >= capacidadRecursos) {
        redimensionarInventario();
    }

    Recurso* nuevo = nullptr;
    switch (tipo) {
        case 1:
            nuevo = new Ambulancia(siguienteIdRecurso++, nombre, placaOEspecialidad, capacidad);
            break;
        case 2:
            nuevo = new Helicoptero(siguienteIdRecurso++, nombre, placaOEspecialidad, capacidad);
            break;
        case 3:
            nuevo = new Medico(siguienteIdRecurso++, nombre, placaOEspecialidad);
            break;
        case 4:
            nuevo = new Rescatista(siguienteIdRecurso++, nombre, placaOEspecialidad);
            break;
    }

    inventario[cantidadRecursos++] = nuevo;
    std::cout << "Recurso registrado con ID " << nuevo->getId() << "." << std::endl;
}

void Controlador::crearMision() {
    std::string nombre;
    std::string ubicacion;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Nombre de la mision: ";
    std::getline(std::cin, nombre);
    std::cout << "Ubicacion: ";
    std::getline(std::cin, ubicacion);

    if (cantidadMisiones >= capacidadMisiones) {
        redimensionarMisiones();
    }

    Mision* nueva = new Mision(siguienteIdMision++, nombre, ubicacion);
    misiones[cantidadMisiones++] = nueva;
    std::cout << "Mision creada con ID " << nueva->getId() << "." << std::endl;
}

void Controlador::asignarRecursoAMision() {
    int idMision;
    int idRecurso;

    std::cout << "\nMisiones disponibles:" << std::endl;
    verMisiones();
    std::cout << "ID de la mision: ";
    std::cin >> idMision;

    Mision* mision = buscarMisionPorId(idMision);
    if (mision == nullptr) {
        std::cout << "Mision no encontrada." << std::endl;
        return;
    }

    std::cout << "\nRecursos disponibles:" << std::endl;
    bool hayDisponibles = false;
    for (int i = 0; i < cantidadRecursos; i++) {
        if (inventario[i] != nullptr && inventario[i]->getDisponible()) {
            inventario[i]->mostrarInfo();
            hayDisponibles = true;
        }
    }

    if (!hayDisponibles) {
        std::cout << "No hay recursos disponibles para asignar." << std::endl;
        return;
    }

    std::cout << "ID del recurso: ";
    std::cin >> idRecurso;

    Recurso* recurso = buscarRecursoPorId(idRecurso);
    if (recurso == nullptr) {
        std::cout << "Recurso no encontrado." << std::endl;
        return;
    }

    if (!recurso->getDisponible()) {
        std::cout << "El recurso ya esta asignado a otra mision." << std::endl;
        return;
    }

    mision->asignarRecurso(recurso);
    std::cout << "Recurso asignado correctamente a la mision." << std::endl;
}

void Controlador::ejecutarMision() {
    int idMision;

    std::cout << "\nMisiones disponibles:" << std::endl;
    verMisiones();
    std::cout << "ID de la mision a ejecutar: ";
    std::cin >> idMision;

    Mision* mision = buscarMisionPorId(idMision);
    if (mision == nullptr) {
        std::cout << "Mision no encontrada." << std::endl;
        return;
    }

    mision->ejecutar();
}

void Controlador::iniciar() {
    int opcion = 0;

    do {
        mostrarMenu();
        if (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida. Intente de nuevo." << std::endl;
            continue;
        }

        switch (opcion) {
            case 1:
                verRecursos();
                break;
            case 2:
                registrarRecurso();
                break;
            case 3:
                crearMision();
                break;
            case 4:
                asignarRecursoAMision();
                break;
            case 5:
                ejecutarMision();
                break;
            case 6:
                std::cout << "Saliendo del sistema. Liberando memoria..." << std::endl;
                break;
            default:
                std::cout << "Opcion no valida." << std::endl;
                break;
        }
    } while (opcion != 6);
}
