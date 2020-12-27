#pragma once
#include <vector>
#include <string>
#include "backUp.h"
#include "IDelAlgCreat.h"


class backUpApp {
private:
    BackUp m_currStorage;
    std::size_t m_backUpId;
public:
    explicit backUpApp(const std::size_t backUpId);
    void filesToBackUp(std::vector<std::string_view> givenFiles);
    void createRestPoint(std::string_view restPointType);
    void saveRestPointAs(std::string_view givenPoint);
    void deleteFile(std::string_view fileName);
    void addFile(std::string_view fileName);
    IDelAlgCreat* delAlg(std::string_view delAlgName);
    void controlRestorePointsAs(std::string_view controlType);
};