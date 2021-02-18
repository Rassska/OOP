#include <iostream>
#include <string>
#include <vector>
#include "SaveManager.h"
#include "SaveJoin.h"
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <fstream>


SaveJoin::SaveJoin() = default;
SaveJoin::~SaveJoin() = default;


void SaveJoin::save(const BackUp* currBackUp) {
    std::string BackUpJoinStoragePath = "/home/m_rassska/dev/OOP/newBackUpModel/BackUpJoinStorage";
    mkdir(BackUpJoinStoragePath.c_str(), 0777);
    std::ofstream fout(BackUpJoinStoragePath + '/' + "archive");

    for (std::size_t i = 0; i < currBackUp->getRestorePointStorage().size(); i++) {
        std::string restorePointName = "/RestorePoint№" + std::to_string(i) + '/';
        for (std::size_t j = 0; j < currBackUp->getRestorePointStorage()[i]->getCurrPointFiles().size(); j++) { 
            std::string fileName = restorePointName + " file№ " + std::to_string(j) + '\n';
            fout << fileName;
        }

    }
    
} 