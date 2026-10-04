#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include "sensor.h"

#define DRY_THRESHOLD 30.0f
#define MAX_NODES 100

int read_integer(const char *message, int *value) {

    char input[100];
    char *end;
    long number;

    printf("%s", message);

    if (fgets(input, sizeof(input), stdin) == NULL) {
        return 0;
    }

    errno = 0;
    number = strtol(input, &end, 10);

    if (end == input || errno == ERANGE) {
        return 0;
    }

    while (*end == ' ' || *end == '\t') {
        end++;
    }

    if (*end != '\n' && *end != '\0') {
        return 0;
    }

    if (number < INT_MIN || number > INT_MAX) {
        return 0;
    }

    *value = (int)number;

    return 1;
}


int read_float(const char *message, float *value) {

    char input[100];
    char *end;
    float number;

    printf("%s", message);

    if (fgets(input, sizeof(input), stdin) == NULL) {
        return 0;
    }

    errno = 0;
    number = strtof(input, &end);

    if (end == input || errno == ERANGE) {
        return 0;
    }

    while (*end == ' ' || *end == '\t') {
        end++;
    }

    if (*end != '\n' && *end != '\0') {
        return 0;
    }

    *value = number;

    return 1;
}


int main(void) {

    int count;

    printf("========================================\n");
    printf("     SMART AGRICULTURE GATEWAY\n");
    printf("     MULTI-NODE MONITORING SYSTEM\n");
    printf("========================================\n\n");


    /* Read number of sensor nodes */

    while (1) {

        if (read_integer("Enter number of sensor nodes: ", &count)) {

            if (count > 0 && count <= MAX_NODES) {
                break;
            }
        }

        printf("Invalid number. Enter a value between 1 and %d.\n\n",
               MAX_NODES);
    }


    Sensor sensors[MAX_NODES];

    float total_moisture = 0.0f;
    int valid_nodes = 0;
    int dry_nodes = 0;


    /* Read sensor data */

    for (int i = 0; i < count; i++) {

        sensors[i].node_id = i + 1;

        while (1) {

	char message[100];

snprintf(message, sizeof(message),
         "Enter moisture for Node %d (0-100): ",
         sensors[i].node_id);

if (read_float(message, &sensors[i].moisture)) {
    break;
}


            printf("Invalid input. Please enter a numeric value.\n");
        }
    }


    /* Display sensor readings */

    printf("\n========================================\n");
    printf("           SENSOR READINGS\n");
    printf("========================================\n");

    printf("%-8s %-16s %s\n",
           "Node ID", "Moisture (%)", "Status");

    printf("----------------------------------------\n");


    for (int i = 0; i < count; i++) {

        display_sensor(&sensors[i]);

        if (sensors[i].moisture >= 0 &&
            sensors[i].moisture <= 100) {

            total_moisture += sensors[i].moisture;
            valid_nodes++;

            if (sensors[i].moisture < DRY_THRESHOLD) {
                dry_nodes++;
            }
        }
    }


    /* Gateway summary */

    printf("\n========================================\n");
    printf("              GATEWAY SUMMARY\n");
    printf("========================================\n");

    printf("Total sensor nodes : %d\n", count);
    printf("Valid sensor nodes : %d\n", valid_nodes);
    printf("Dry sensor nodes   : %d\n", dry_nodes);


    if (valid_nodes > 0) {

        float average = total_moisture / valid_nodes;

        printf("Average moisture   : %.2f%%\n", average);

        printf("\nIrrigation decision : ");

        if (dry_nodes > 0) {
            printf("IRRIGATION REQUIRED\n");
        } else {
            printf("NO IRRIGATION REQUIRED\n");
        }

    } else {

        printf("Average moisture   : N/A\n");

        printf("\nIrrigation decision : CANNOT DETERMINE\n");
    }


    return 0;
}
