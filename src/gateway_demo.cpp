#include <iostream>
#include <iomanip>
#include "gateway.hpp"

int main() {

    Gateway gateway;

    gateway.addSensor(SensorNode(1, 20.0f));
    gateway.addSensor(SensorNode(2, 50.0f));
    gateway.addSensor(SensorNode(3, 80.0f));
    gateway.addSensor(SensorNode(4, 25.0f));

    std::cout << "========================================\n";
    std::cout << "       C++ GATEWAY DEMONSTRATION\n";
    std::cout << "========================================\n\n";

    std::cout << "Total sensor nodes : "
              << gateway.getTotalNodes() << '\n';

    std::cout << "Valid sensor nodes : "
              << gateway.getValidNodes() << '\n';

    std::cout << "Dry sensor nodes   : "
              << gateway.getDryNodes() << '\n';

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Average moisture   : "
              << gateway.getAverageMoisture() << "%\n";

    std::cout << "\nIrrigation decision : ";

    if (gateway.irrigationRequired()) {
        std::cout << "IRRIGATION REQUIRED\n";
    } else {
        std::cout << "NO IRRIGATION REQUIRED\n";
    }

    return 0;
}
