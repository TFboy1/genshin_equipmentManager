#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "Observer.h"

class Subject {
private:
    std::vector<Observer*> observers;

public:
    // ��ӹ۲���
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    // �Ƴ��۲���
    void detach(Observer* observer) {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    // ֪ͨ���й۲���
    void notify() {
        for (Observer* observer : observers) {
            observer->update();
        }
    }
};
#endif // SUBJECT_H