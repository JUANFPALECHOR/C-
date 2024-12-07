#ifndef IDGENERATOR_H
#define IDGENERATOR_H

#include <unordered_map>
#include <string>

class IDGenerator {
private:
    static IDGenerator* instance;
    std::unordered_map<std::string, int> counters;

    
    IDGenerator() {}

public:
    
    static IDGenerator* getInstance();

    
    int generarID(const std::string& entidad);
};

#endif 
