#include "DAL/Abstractions/DRepositoriesAbstraction.h"


DRepositoriesAbstraction::DRepositoriesAbstraction() = default;
DRepositoriesAbstraction::~DRepositoriesAbstraction() = default;


void DRepositoriesAbstraction::create(DEntitiesAbstraction* currEntity) {};
void DRepositoriesAbstraction::deletee(std::size_t currEntityID) {};
void DRepositoriesAbstraction::update(DEntitiesAbstraction* newEntity, std::size_t currEntityID) {};
std::vector <DEntitiesAbstraction*> DRepositoriesAbstraction::getAll() {};
DEntitiesAbstraction* DRepositoriesAbstraction::getEntity(std::size_t entityID) {};