#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class ReportController
{
private:
    
public:
    ReportController();
    void addDailyReport(TaskViewModel* currTaskViewModel);
    ~ReportController();
};


