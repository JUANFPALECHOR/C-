// IDGenerator.cpp
#include "IDGenerator.h"

IDGenerator* IDGenerator::instance = nullptr;

IDGenerator* IDGenerator::getInstance() {
    if (!instance) {
        instance = new IDGenerator();
    }
    return instance;
}

int IDGenerator::generarID(const std::string& entidad) {
    if (counters.find(entidad) == counters.end()) {
        counters[entidad] = 1; // Iniciar en 1
    } else {
        counters[entidad]++;
    }
    return counters[entidad];
}
