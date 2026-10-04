#include "gateway.hpp"

SensorNode::SensorNode(int id, float moisture)
    : node_id(id), moisture(moisture) {
}

int SensorNode::getId() const {
    return node_id;
}

float SensorNode::getMoisture() const {
    return moisture;
}

bool SensorNode::isValid() const {
    return moisture >= 0.0f && moisture <= 100.0f;
}

bool SensorNode::isDry() const {
    return isValid() && moisture < 30.0f;
}


void Gateway::addSensor(const SensorNode& sensor) {
    nodes.push_back(sensor);
}

int Gateway::getTotalNodes() const {
    return static_cast<int>(nodes.size());
}

int Gateway::getValidNodes() const {

    int count = 0;

    for (const SensorNode& sensor : nodes) {
        if (sensor.isValid()) {
            count++;
        }
    }

    return count;
}

int Gateway::getDryNodes() const {

    int count = 0;

    for (const SensorNode& sensor : nodes) {
        if (sensor.isDry()) {
            count++;
        }
    }

    return count;
}

float Gateway::getAverageMoisture() const {

    float total = 0.0f;
    int valid = 0;

    for (const SensorNode& sensor : nodes) {

        if (sensor.isValid()) {
            total += sensor.getMoisture();
            valid++;
        }
    }

    if (valid == 0) {
        return 0.0f;
    }

    return total / valid;
}

bool Gateway::irrigationRequired() const {
    return getDryNodes() > 0;
}
