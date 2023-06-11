#include "mbed.h"

// Blinking rate in milliseconds
#define BLINKING_RATE     500ms

DigitalOut led(LED1);


struct date_t {
    uint8_t Hour;
    uint8_t Minutes;
    uint8_t Seconds;
    uint8_t Day;
    uint8_t Month;
    uint16_t Year;
};

// Prototypes

// Convert Unix timestamp to human-readable string date.
// On success, return pointer to char array, otherwise false.
char* uxtime2date(time_t uxtime);

// Get the day name of the week from Unix timestamp.
// On success, return enum (0-6, Sunday = 0), otherwise false.
int uxtime2day(time_t uxtime);

// Get Unix timestamp of date passed by date_t struct.
time_t date_t2uxtime(struct date_t t);

// Calculate days between two Unix timestamps.
// Return false in case of error
float count_days(time_t t1, time_t t2);

time_t uxt = 994248127;
struct date_t dt = {19,15,27,10,2,2005};
time_t t1 = 984248127;
time_t t2 = 994334527;

int main() {
    
    printf("Date: %s\n", uxtime2date(uxt));
    printf("Day: %i (0-6) 0 = Sunday\n", uxtime2day(uxt));
    printf("Unix timestamp: %u\n", date_t2uxtime(dt));
    printf("%.2f days between t1 = %u and t2 = %u\n", count_days(t1, t2),t1, t2);
    
    
    while (1) {
        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);
          
    }
}

char *uxtime2date(time_t uxtime)
{
    struct tm ts;
    static char buffer[24];
    ts = *localtime(&uxtime);

    if (strftime(buffer, sizeof(buffer), "%d %b %Y %H:%M:%S", &ts) != 0)
    {

        char *data = buffer;
        return data;
    }
    else
    {
        
        return NULL; 
    }
}

int uxtime2day(time_t uxtime)
{
    struct tm ts;
    ts = *localtime(&uxtime);
    int day = ts.tm_wday;
    if (day >= 0 && day <= 6)
    {
        return day;
    }
    else
    {
        return false;
    }

}

time_t date_t2uxtime(struct date_t t)
{
    struct tm ts;

    // Convert date_t to tm structure
    ts.tm_hour = t.Hour;
    ts.tm_min = t.Minutes;
    ts.tm_sec = t.Seconds;
    ts.tm_mday = t.Day;
    ts.tm_mon = t.Month;
    // Calculate years sience 1900
    int years = t.Year - 1900;
    if (years >= 0)
    {
        ts.tm_year = years;
    }
    else
    {
        return false;
    }


    time_t uxtime = mktime(&ts);
    if (uxtime != -1)
    {
        return uxtime;
    }
    else
    {
        return false;
    }
}

float count_days(time_t t1, time_t t2)
{
    if (t2 > t1)
    {
        float days = t2 - t1;
        days = days / 86400;
        return days;
    }
    else
    {
        return false;
    }
}

