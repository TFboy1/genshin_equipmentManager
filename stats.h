#pragma once
#include <string>

class Stats {
public:
   
    Stats(const std::string& name, int stats, int ele);
    ~Stats();

    const std::string& getName() const;
    int getStats() const;
    int getEle() const;
    void setStats(int stats);
    void setEle(int ele);

    void setName(std::string name);
private:
    std::string name;
    int stats;
    int ele;
};
