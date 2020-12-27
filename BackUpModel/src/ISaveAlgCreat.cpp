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

#include "incremental.h"
#include "file.h"
#include "ISaveAlgCreat.h"


std::string_view ISaveAlgCreat::getPath(){
    return this->m_path;
}
void ISaveAlgCreat::setPath(std::string_view path){
    this->m_path = path;
}