#pragma once

#include "restorePoint.h"
#include "file.h"

class incremental : public restorePoint {
    std::size_t setRestorePointSize(const restorePoint* restorePoint, std::string_view restorePointName) override;
public:
    explicit incremental(restorePoint* restorePointParent);
    void addFileToRestorePoint(file file) override;
};