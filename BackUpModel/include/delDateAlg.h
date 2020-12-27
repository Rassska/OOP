#include "IDelAlgCreat.h"
#include "restorePoint.h"

class DateAlg : public IDelAlgCreat{
private:
    time_t m_timeLim;
public:
    explicit DateAlg(const time_t timeLim) : m_timeLim(timeLim) {}
    static std::size_t limitWithDate(const time_t limit, const std::vector<restorePoint*>& restorePoints);
    std::size_t limit(const std::vector<restorePoint*>& rps) const override;
};