#ifndef SENSOR_H
#define SENSOR_H

typedef struct {
    int node_id;
    float moisture;
} Sensor;

const char *get_moisture_status(float moisture);
void display_sensor(const Sensor *sensor);

#endif
