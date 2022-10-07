# A concurrent computing study with c++

### Table of Contents

1. [Introduction](#introduction)
2. [Experimentation](#experimentation)
3. [Compilation](#compilation)
4. [Execution](#execution)
5. [How to run the program N times on terminal](#how-to-run-the-program-n-times-on-terminal)
6. [Libraries](#libraries)
7. [API Used for This Analysis](#api-used-for-this-analysis)
8. [Specs](#specs)
8. [Authors](#authors)

## Introduction
This is a program to make requests to an external API, sequentially and concurrently, to meansure time elapsed generating two logs with number of requests and time lapse in milliseconds and seconds. 
Inside **logs folder**, the first named **sequential.txt** refers to a sequential programming paradigm, the second named **concurrence.txt** refers to a paradigm that makes use of `concurrence` with `threads`

## Experimentation
Five scenarios where created, each one simulating a number of requests made by clients to the chosen service.
Due to time constraints, 1, 10, 20, 50, 100, 200 and 500 requests where choses, each one being executed 20 times.
The exections times of each version in each of these twenty executions were recorded so that later analyzes could be carried out.

## Compilation
This program is compiled with `g++-11 (Ubuntu 11.2.0-19ubuntu1) 11.2.0`

**How to compile**
remember: this program should be compiled with -lcurl flag
```
$ g++-11 ./sequencial.cpp -o sequencial -lcurl  
```

## Execution
To execute the program, you should add a parameter who represents quantity of requests should be made.
Example of execution that will make 20 requests
```
./sequencial 20
```

## How to run the program N times on terminal
Use this script on terminal to automatize the task
```script
for run in {1..20}; do
./sequencial 100
done
```

## Libraries
* `"<chrono>"` - To meansure time elapsed
* `"<thread>"` - To generate paralel requests
* `"<fstream>"` - To create .txt log files
* `"<libcurl4>"` - To transfer data from an API

## API Used for This Analysis
Repository - [RapidAPI](https://rapidapi.com/hub)
Service - [Roll Dice](https://rapidapi.com/vishukaypri/api/roll-dice1/)

## Specs
Intel® Core™ i7-7700HQ CPU @ 2.80GHz × 8 
16 GB RAM
Ubuntu 22.04 LTS

## Authors
[Rafael Fortunato](https://github.com/obelixlelul)
[Joao de Souza](https://github.com/joaosfvieira)
