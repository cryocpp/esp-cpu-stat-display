# CPU Usage Display on OLED

This project displays your computer’s real-time CPU usage on a 128x64 OLED screen using an ESP32 with the arduino framework.

A Python script collects CPU data using `psutil` and sends it over serial to the esp, which renders it on the display using the U8g2 library.




