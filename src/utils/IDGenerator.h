// IDGenerator.h
#ifndef IDGENERATOR_H
#define IDGENERATOR_H

#include <unordered_map>
#include <string>

class IDGenerator {
private:
    static IDGenerator* instance;
    std::unordered_map<std::string, int> counters;

    // Constructor privado para Singleton
    IDGenerator() {}

public:
    // Obtener la instancia única
    static IDGenerator* getInstance();

    // Generar ID para una entidad específica
    int generarID(const std::string& entidad);
};

#endif // IDGENERATOR_H
