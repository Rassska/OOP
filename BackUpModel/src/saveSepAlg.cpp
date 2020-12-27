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
#include "saveSepAlg.h"

void SeparateAlgorithm::saveFiles(BackUp currBackUp){
    bool check;
    for(auto it : currBackUp.getAlllRestorePointsPointer()){
        std::string_view restorePointName = it->getRestorePointName();
        check = false;
        for(auto files : it->getRestorePointFiles()){
            std::string newFileName = files.getFileName().substr(0, files.getFileName().find_first_of('.'));
            std::string temp = {m_path.begin(), m_path.end()};

            std::ofstream outFile(temp + "FolderOfSeparateFiles2/" + newFileName + ".outFile");
            if(!outFile.is_open()) {
                throw std::runtime_error("outFile cannot be opened for some reasons!\n");
            }
            outFile << files.getFileName() << '\n';
            outFile << files.getFileSize() << '\n';
            outFile << files.getFileTimeAsCtime() << '\n';
        }
    }
}