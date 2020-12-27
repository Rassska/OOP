#pragma once
#include "restorePoint.h"
#include "file.h"

class newFF : public restorePoint {
    std::size_t setRestorePointSize(const restorePoint* restorePoint, std::string_view restorePointName) override;
public:
    newFF(restorePoint* restorePointParent);
    void addFileToRestorePoint(file file) override;
};