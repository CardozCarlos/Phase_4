Phase 4 – Ultrasonic Sensor Level Monitoring

This repository contains the development of the Phase 4 project for the Data Analytics course at UNAD.

The project consists of the design, simulation, and analysis of a system based on HCSR04 ultrasonic sensors,
implemented in a PIC 16F877A microcontroller, which measures liquid levels in tanks and controls digital outputs 
according to defined ranges. It also includes data analysis using Python and a public dataset related to IoT environments.

Ultrasonico.c
Source code in C language (CCS PIC C Compiler) for reading two ultrasonic sensors and controlling outputs based on levels. 
It was simulated using MPLAB and Proteus.
Phase_4_Dataset.ipynb
Google Colab notebook in Python that analyzes real-world tank level data (test_dataset.csv) using pandas, matplotlib, and seaborn.
test_dataset.csv
Sample dataset with columns L_T1 and L_T2 corresponding to the levels in two tanks. Used for visualization and statistics in Python.
