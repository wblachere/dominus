#include <config.h>
#include <stdlib.h>
#include <stdio.h>
#include <curl/curl.h>

int main (int argc, char* argv[])
{
        char* IP_address;
        char* port;
        char* name;
        int ID_Sensor;

        char http_address[250];

        CURL *curl;
        CURLcode res;

        if (argc != 5)
        {
                printf("Needed 4 arguments but %d given.\nUse this way -> ./temp IP Port ID_Sensor Sensor_name\n", argc-1);
                return 1;
        } else {
                IP_address      = argv[1];                
                port            = argv[2];
                ID_Sensor       = atoi(argv[3]);                
                name            = argv[4];
        }

        sprintf(http_address, "http://%s:%s/json.htm?type=createvirtualsensor&idx=%d&sensorname=%s&sensortype=80", IP_address, port, ID_Sensor, name);
        printf("%s\n", http_address);

        curl_global_init(CURL_GLOBAL_ALL);

        curl = curl_easy_init();
        if (curl)
        {
                

                curl_easy_setopt(curl, CURLOPT_URL, http_address);

                res = curl_easy_perform(curl);

                if(res != CURLE_OK)
                        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                                curl_easy_strerror(res));
                
                curl_easy_cleanup(curl);
        }
        curl_global_cleanup();

        return EXIT_SUCCESS;  
}
