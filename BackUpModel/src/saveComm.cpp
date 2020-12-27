#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include <ctime>
#include <unordered_map>
#include <list>
#include <map>
#include <ctime>
#include <filesystem>
#include <utility>
#include <functional>

#include "newFF.h"
#include "backUp.h"
#include "saveComm.h"

void CommonAlgorithm::saveFiles(BackUp givenBackUp){
    std::string temp = {m_path.begin(), m_path.end()};
    std::ofstream outFile(temp + "new_archive2.outFile");
    for(auto it : givenBackUp.getAlllRestorePointsPointer()){
        std::string_view nameRP = it->getRestorePointName();
        for(auto currFile : it->getRestorePointFiles()){
            outFile << it->getRestorePointName() << it->getRestorePointId() << ".\n";
            outFile <<currFile.getFileName() <<'\n';
            outFile <<currFile.getFileSize() <<'\n';
            outFile << currFile.getFileTimeAsCtime() <<'\n';
        }
    }
}