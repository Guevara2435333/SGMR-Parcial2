#ifndef RECURSO_H
#define RECURSO_H

#include <string>

// Clase base abstracta del inventario SGMR
class Recurso {
protected:
    int id;
    std::string nombre;
    bool disponible;

public:
    Recurso(int id, const std::string& nombre);
    virtual ~Recurso();

    int getId() const;
    const std::string& getNombre() const;
    bool getDisponible() const;
    void setDisponible(bool estado);

    virtual void ejecutar() = 0;
    virtual void mostrarInfo() const = 0;
    virtual std::string getTipo() const = 0;
};

#endif
