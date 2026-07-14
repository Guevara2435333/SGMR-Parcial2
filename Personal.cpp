#include "Personal.h"

Personal::Personal(int id, const std::string& nombre, const std::string& especialidad)
    : Recurso(id, nombre), especialidad(especialidad) {
}

Personal::~Personal() {
}

const std::string& Personal::getEspecialidad() const {
    return especialidad;
}
