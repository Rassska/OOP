#include <iostream>
#include <string>
#include <vector>
#include "SaveManager.h"
#include "BackUp.h"

SaveManager::SaveManager() = default;
SaveManager::~SaveManager() = default;


void SaveManager::saveAs(const BackUp* currBackUp, ISave* currSaveAlg) {
    currSaveAlg->save(currBackUp);
}