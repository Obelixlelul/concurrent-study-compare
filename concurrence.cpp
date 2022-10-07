#include <iostream>
#include <string>
#include <stdio.h>
#include <curl/curl.h>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <threads.h>
#include <thread>
#include <vector>


#define duration(a) std::chrono::duration_cast<std::chrono::milliseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()

typedef std::chrono::high_resolution_clock::time_point TimeVar;

using namespace std;

int main(int argc, char* argv[]) 
{
    
    // Receive iterations quantity as argv[1]
    if(argc == 1 || argc > 2){
        cout << "A single argument referring to the number of requirements must be inserted/n";
        return 1;
    }

    int iterations = std::stoi(argv[1]);

    
    CURLcode res;

    std::vector<std::thread> threads;
        
    auto start = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < iterations; ++i){
            threads.emplace_back([&]{ //creates and starts a thread
                CURL *curl = curl_easy_init();  
                if (curl) {
                    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
                    curl_easy_setopt(curl, CURLOPT_URL, "https://roll-dice1.p.rapidapi.com/rollDice");
                    struct curl_slist *headers = NULL;
                    headers = curl_slist_append(headers, "X-RapidAPI-Key: 0197282ec9msh98c513dba9e4a78p140cd4jsna0d89d7bc822");
                    headers = curl_slist_append(headers, "X-RapidAPI-Host: roll-dice1.p.rapidapi.com");
                    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
                    curl_easy_setopt(curl, CURLOPT_NOBODY, 1); // Comment to see request printed on terminal
                    curl_easy_perform(curl);
                    curl_easy_cleanup(curl);
                }
            });
    }

    for (auto& t : threads) { // wait for all threads to finish
        t.join();
    }
    auto end = std::chrono::high_resolution_clock::now();

    // WRITE IN LOG FILE
    ofstream log;
    log.open("logs/concurrence.txt", ios::out | ios::app);
    if (log.is_open()){
        auto timeMilli = std::chrono::duration_cast<chrono::milliseconds>(end - start).count();
        auto timeSeconds = timeMilli * 0.001;
        log << "Requisitions: "<< iterations <<" | Time elapsed: "<< timeMilli << " ms | " << timeSeconds << " s" << endl;
        log.close();
    }else{
        cout << "File can't be open\n";
        return 1;
    }

    return 0;
}