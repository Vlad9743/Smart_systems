#include "temp_api.h"

int64_t count_strings_number(FILE *file_name)
{
    uint64_t strings_number = 0;
    char temp;
            
    while ((temp = fgetc(file_name)) != EOF)
    {
        if (temp == '\n')
        {
            strings_number++;
        }
    }
    fseek(file_name, 0, SEEK_SET);
    return strings_number + 1;
}

int64_t parse_file(FILE *file_name, data_record_t data_array[], uint64_t array_length)
{
    int16_t loc_year;
    int8_t loc_month, loc_day, loc_hour, loc_minute;
    int16_t loc_temperature;
    int64_t current_record = 0;
    int64_t actual_records = 0;
       
    for (current_record; current_record < array_length; current_record++)
    {   
        char temp_string[128];
        int args_num = 0;

        fgets(temp_string, 128, file_name);
        
        args_num = sscanf(temp_string, "%hd;%hhd;%hhd;%hhd;%hhd;%hd",
            &loc_year,
            &loc_month, 
            &loc_day,
            &loc_hour,
            &loc_minute,
            &loc_temperature);

        if (args_num < 6)
        {
            printf("Corrupted data in line %ld.\n", current_record + 1);
        }
        else
        {
            if (loc_year >= 2000 && loc_year <= 2025 &&
                loc_month >= 1 && loc_month <= 12 &&
                loc_day >= 1 && loc_day <= 31 &&
                loc_hour >= 0 && loc_hour <= 24 &&
                loc_minute >= 0 && loc_minute <= 59 &&
                loc_temperature >= -99 && loc_temperature <= 99)
            {    
                data_array[actual_records].year = loc_year;
                data_array[actual_records].month = loc_month;
                data_array[actual_records].day = loc_day;
                data_array[actual_records].hour = loc_hour;
                data_array[actual_records].minute = loc_minute;
                data_array[actual_records].temperature = loc_temperature;
                actual_records++;
            }
            else
            {
                printf("Corrupted data in line %ld.\n", current_record + 1);
                printf("------------------------------\n");
            }
        }
    }
    return actual_records;
}

void month_temp_parameters(data_record_t data_array[], uint64_t array_length, int8_t month)
{
    int8_t temp_max = -99;
    int8_t temp_min = 99;
    int64_t temp_sum = 0;
    int64_t records_in_month = 0;

    for (int64_t i = 0; i < array_length; i++)
    {
        if (data_array[i].month == month)
        {
            if (data_array[i].temperature > temp_max)
            {
                temp_max = data_array[i].temperature;
            }
            if (data_array[i].temperature < temp_min)
            {
                temp_min = data_array[i].temperature;
            }
            records_in_month++;
            temp_sum += data_array[i].temperature;
        }
    }

    if (records_in_month == 0)
    {
        printf("No records for month %hhd.\n", month);
    }
    else
    {
        printf("Month %hhd. Max temp: %hd. Min temp: %hd. Avg temp: %.3f\n",
        month, temp_max, temp_min, (float)temp_sum/records_in_month);
    }
}

void full_temp_parameters(data_record_t data_array[], uint64_t array_length)
{
    month_characteristics_t charecteristics[12];
    for (int i = 0; i < 12; i++)
    {
        charecteristics[i].month_max_temp = -99;
        charecteristics[i].month_min_temp = 99;
        charecteristics[i].month_avg_temp = 0.0;
        charecteristics[i].month_records = 0;
    }
    int8_t current_month;
    for (int64_t i = 0; i < array_length; i++)
    {
        current_month = data_array[i].month;
        
            if (data_array[i].temperature > charecteristics[current_month - 1].month_max_temp)
            {
                charecteristics[current_month - 1].month_max_temp = data_array[i].temperature;
            }
            if (data_array[i].temperature < charecteristics[current_month - 1].month_min_temp)
            {
                charecteristics[current_month - 1].month_min_temp = data_array[i].temperature;
            }
            charecteristics[current_month - 1].month_records++;
            charecteristics[current_month - 1].month_avg_temp += data_array[i].temperature;
    }

    int16_t year_max_temp = -99;
    int16_t year_min_temp = 99;
    int actual_month = 12;
    float year_avg_temp = 0;
    for (int i = 0; i < 12; i++)
    {
        if (charecteristics[i].month_records == 0)
        {
            printf("No records for month %hhd.\n", i + 1);
            charecteristics[i].month_avg_temp = 0;
            actual_month--;
        }
        else
        {
            printf("Month %2hhd. Max temp: %4hd.  ", i + 1, charecteristics[i].month_max_temp);
            printf("Min temp: %4hd.  ", charecteristics[i].month_min_temp);
            printf("Avg temp: %.3f\n", charecteristics[i].month_avg_temp/charecteristics[i].month_records);
        }

        if (charecteristics[i].month_max_temp > year_max_temp)
        {
            year_max_temp = charecteristics[i].month_max_temp;
        }
        if (charecteristics[i].month_min_temp < year_min_temp)
        {
            year_min_temp = charecteristics[i].month_min_temp;
        }
        if ((charecteristics[i].month_records != 0))
        {
            year_avg_temp += charecteristics[i].month_avg_temp/charecteristics[i].month_records;
        }
    }
    year_avg_temp /= actual_month;

    printf("====================================================================\n");
    printf("Year max temp: %hd. Year min temp: %hd. Year average temp: %.4f\n", year_max_temp, year_min_temp, year_avg_temp);
}

int64_t add_record(data_record_t data_array[], int64_t array_length, data_record_t new_record)
{
    array_length++;
    data_array = realloc(data_array, array_length * sizeof(data_record_t));
    data_array[array_length - 1].year = new_record.year;
    data_array[array_length - 1].month = new_record.month;
    data_array[array_length - 1].day = new_record.day;
    data_array[array_length - 1].hour = new_record.hour;
    data_array[array_length - 1].minute = new_record.minute;
    data_array[array_length - 1].temperature = new_record.temperature;

    return array_length;
}

int64_t delete_record(data_record_t data_array[], int64_t array_length, int64_t record_number)
{
    if (record_number < 1 || record_number > array_length)
    {
        return array_length;
    }
    else
    {
        for (int64_t i = record_number - 1; i < array_length - 1; i++)
        {
            data_array[i] = data_array[i+1];
        }
        array_length--;
        data_array = realloc(data_array, array_length * sizeof(data_record_t));
        return array_length;
    }
    return array_length;
}


void sort_by_temp(data_record_t data_array[], int64_t array_length)
{
    for(int64_t i = 0; i < array_length - 1; i++)
    {
        for (int64_t j = 0; j < array_length - 1 - i; j++)
        {
            if (data_array[j].temperature > data_array[j+1].temperature)
            {
                data_record_t temp = data_array[j];
                data_array[j] = data_array[j + 1];
                data_array[j + 1] = temp;
            }
        }
    }
}

void print_temp_array(data_record_t data_array[], uint64_t array_length)
{
    printf("************************************\n");
    printf("####  Year  Month  Day  Hour  Minute  Temp(C)\n");

    for (int i = 0; i < array_length; i++)
    {
        printf("%4d  %4hd  %5hhd  %3hhd  %4hhd  %6hhd  %4hd\n", 
        i + 1,
        data_array[i].year,
        data_array[i].month,
        data_array[i].day,
        data_array[i].hour,
        data_array[i].minute,
        data_array[i].temperature);
    }
}