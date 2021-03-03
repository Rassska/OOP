#include "BLL/Abstractions/DTRepositoriesAbstraction.h"


DTRepositoriesAbstraction::DTRepositoriesAbstraction() = default;
DTRepositoriesAbstraction::~DTRepositoriesAbstraction() = default;


void DTRepositoriesAbstraction::create(DTEntitiesAbstraction* currEntity) {};
void DTRepositoriesAbstraction::deletee(std::size_t currEntityID) {};
void DTRepositoriesAbstraction::update(DTEntitiesAbstraction* newEntity, std::size_t currEntityID) {};
std::vector <DTEntitiesAbstraction*> DTRepositoriesAbstraction::getAll() {};
DTEntitiesAbstraction* DTRepositoriesAbstraction::getEntity(std::size_t entityID) {};
void DTRepositoriesAbstraction::showEntitiesList() {};