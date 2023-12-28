#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "Observer.h"

class Subject
{
private:
    std::vector<Observer *> observers;

public:
    // 添加观察者
    void attach(Observer *observer)
    {
        observers.push_back(observer);
    }

    // 移除观察者
    void detach(Observer *observer)
    {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end())
        {
            observers.erase(it);
        }
    }

    // 通知所有观察者
    void notify()
    {
        for (Observer *observer : observers)
        {
            observer->update();
        }
    }
};
#endif // SUBJECT_H