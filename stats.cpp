#include "stats.h"

Stats::Stats(const std::string &name, int stats, int ele)
    : name(name), stats(stats), ele(ele)
{
}

Stats::~Stats() {}

const std::string &Stats::getName() const
{
    return name;
}

int Stats::getStats() const
{
    return stats;
}

int Stats::getEle() const
{
    return ele;
}

void Stats::setStats(int stats)
{
    this->stats = stats;
}

void Stats::setEle(int ele)
{
    this->ele = ele;
}

void Stats::setName(std::string name)
{
    this->name = name;
}
