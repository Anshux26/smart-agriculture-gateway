#ifndef GATEWAY_HPP
#define GATEWAY_HPP

#include <vector>

class SensorNode {
private:
    int node_id;
    float moisture;

public:
    SensorNode(int id, float moisture);

    int getId() const;
    float getMoisture() const;

    bool isValid() const;
    bool isDry() const;
};

class Gateway {
private:
    std::vector<SensorNode> nodes;

public:
    void addSensor(const SensorNode& sensor);

    int getTotalNodes() const;
    int getValidNodes() const;
    int getDryNodes() const;

    float getAverageMoisture() const;

    bool irrigationRequired() const;
};

#endif
