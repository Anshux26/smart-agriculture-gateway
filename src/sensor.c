#include <stdio.h>
#include "sensor.h"

const char *get_moisture_status(float moisture) {

    if (moisture < 0 || moisture > 100) {
        return "INVALID";
    }

    if (moisture < 30) {
        return "DRY - ALERT";
    }

    if (moisture <= 70) {
        return "OPTIMAL";
    }

    return "WET";
}

void display_sensor(const Sensor *sensor) {

    printf("%-8d %-16.1f %s\n",
           sensor->node_id,
           sensor->moisture,
           get_moisture_status(sensor->moisture));
}
