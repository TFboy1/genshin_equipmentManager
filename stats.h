#pragma once
#include <string>

class Stats {
public:
    Stats(const std::string& name, int stats, int ele);
    ~Stats();
    const std::string& getName() const;//获取姓名
    int getStats() const;//获取状态
    int getEle() const;//获取值
    void setStats(int stats);//设置状态
    void setEle(int ele);//设置值
    void setName(std::string name);//设置姓名

private:
    std::string name;
    int stats;
    int ele;
};
