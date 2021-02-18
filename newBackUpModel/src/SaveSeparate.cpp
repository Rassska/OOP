#include <iostream>
#include <string>
#include <vector>
#include "SaveManager.h"
#include "SaveSeparate.h"
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>

SaveSeparate::SaveSeparate() = default;
SaveSeparate::~SaveSeparate() = default;

void SaveSeparate::save(const BackUp* currBackUp) {
    std::string BackUpSepStoragePath = "/home/m_rassska/dev/OOP/newBackUpModel/BackUpSepStorage";
    mkdir(BackUpSepStoragePath.c_str(), 0777);

    for (std::size_t i = 0; i < currBackUp->getRestorePointStorage().size(); i++) {
        std::string restorePointName = "/RestorePoint№" + std::to_string(i) + '/';
        mkdir ((BackUpSepStoragePath + restorePointName).c_str(), 0777);
        for (std::size_t j = 0; j < currBackUp->getRestorePointStorage()[i]->getCurrPointFiles().size(); j++) {
            
            std::string fileName = "file№ " + std::to_string(j);
            std::ofstream fout(BackUpSepStoragePath + restorePointName + fileName);
            fout << fileName;
        }

    }
    

    // system("rm -rf BackUpSepStorage");
} 