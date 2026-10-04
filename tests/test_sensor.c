#include <stdio.h>
#include <string.h>
#include "sensor.h"

int main(void) {

    int passed = 0;
    int failed = 0;

    printf("====================================\n");
    printf("       SENSOR VALIDATION TESTS\n");
    printf("====================================\n\n");

    /* Test 1: Dry sensor */
    if (strcmp(get_moisture_status(20.0), "DRY - ALERT") == 0) {
        printf("Test 1 PASS: Dry sensor\n");
        passed++;
    } else {
        printf("Test 1 FAIL: Dry sensor\n");
        failed++;
    }

    /* Test 2: Optimal sensor */
    if (strcmp(get_moisture_status(50.0), "OPTIMAL") == 0) {
        printf("Test 2 PASS: Optimal sensor\n");
        passed++;
    } else {
        printf("Test 2 FAIL: Optimal sensor\n");
        failed++;
    }

    /* Test 3: Wet sensor */
    if (strcmp(get_moisture_status(80.0), "WET") == 0) {
        printf("Test 3 PASS: Wet sensor\n");
        passed++;
    } else {
        printf("Test 3 FAIL: Wet sensor\n");
        failed++;
    }

    /* Test 4: Negative value */
    if (strcmp(get_moisture_status(-5.0), "INVALID") == 0) {
        printf("Test 4 PASS: Negative reading rejected\n");
        passed++;
    } else {
        printf("Test 4 FAIL: Negative reading rejected\n");
        failed++;
    }

    /* Test 5: Value above 100 */
    if (strcmp(get_moisture_status(150.0), "INVALID") == 0) {
        printf("Test 5 PASS: Value above 100 rejected\n");
        passed++;
    } else {
        printf("Test 5 FAIL: Value above 100 rejected\n");
        failed++;
    }

    printf("\n====================================\n");
    printf("Tests passed : %d\n", passed);
    printf("Tests failed : %d\n", failed);
    printf("====================================\n");

    return failed == 0 ? 0 : 1;
}
