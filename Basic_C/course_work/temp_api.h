#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <getopt.h>

typedef struct data_record_t
{
    int16_t year;
    int8_t month;
    int8_t day;
    int8_t hour;
    int8_t minute;
    int16_t temperature;
} data_record_t;

typedef struct month_characteristics_t
{
    int16_t month_max_temp;
    int16_t month_min_temp;
    float month_avg_temp;
    int64_t month_records;
} month_characteristics_t;

int64_t count_strings_number(FILE *file_name);

int64_t parse_file(FILE *file_name, data_record_t data_array[], uint64_t array_length);

void month_temp_parameters(data_record_t data_array[], uint64_t records_number, int8_t month);

void full_temp_parameters(data_record_t data_array[], uint64_t records_number);

int64_t add_record(data_record_t data_array[], int64_t array_length, data_record_t new_record);

int64_t delete_record(data_record_t data_array[], int64_t array_length, int64_t record_number);

void sort_by_temp(data_record_t data_array[], int64_t array_length);

void print_temp_array(data_record_t data_array[], uint64_t array_length);