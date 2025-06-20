#include "../cashflow/cashflow.h"

Cashflow::Cashflow(std::string t, double v, bool c, bool a, int he, int ha)
    : type(t), value(v), compulsory(c), active(a), healthChange(he), happinessChange(ha) {}

std::string Cashflow::getType() const {
    return type ;
}

double Cashflow::getValue() const {
    return value ;
}

int Cashflow::getHealthChange() const {
    return healthChange;
}

int Cashflow::getHappinessChange() const {
    return happinessChange;
}

bool Cashflow::isCompulsory() const {
    return compulsory ;
}

bool Cashflow::isActive() const {
    return active ;
}

void Cashflow::setValue(double v) {
    value=v;
}

void Cashflow::toggleActive() {
    if (!compulsory) {
        active = !active;
    }
}
