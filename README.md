# Home-Automation-Project
This project implements a smart home automation system using Arduino Uno and various sensors, including DHT (humidity and temperature), PIR (motion), LDR (light), and IR sensors. The system automates the control of household appliances such as a fan and LED lamp based on environmental conditions and motion detection within the home.
Features
Temperature and Humidity Monitoring: The DHT sensor measures temperature and humidity levels within the home.
Motion Detection: The PIR sensor detects motion, triggering actions based on the presence of individuals within the home.
Light Sensing: The LDR sensor measures ambient light levels to adjust the brightness of an LED lamp accordingly.
Fan Control: The system automatically turns on a fan when the temperature exceeds a predefined threshold, providing comfort and ventilation.
LED Lamp Control: The LED lamp is controlled based on both motion detection and ambient light levels, enhancing energy efficiency and convenience.
Real-time Monitoring: Sensor data is displayed in real-time via the Arduino serial monitor, providing insights into environmental conditions within the home.
Technologies Used
Arduino Uno microcontroller
DHT, PIR, LDR, and IR sensors
C/C++ programming language for Arduino sketches
Usage
Connect the sensors and appliances to the Arduino Uno board as per the provided circuit diagram.
Upload the Arduino sketch to the board using the Arduino IDE.
Monitor the sensor data and system behavior in real-time via the Arduino serial monitor.
Customize thresholds and actions as needed to suit specific home automation requirements.
Future Enhancements
Integration with IoT platforms for remote monitoring and control.
Expansion of sensor capabilities to include additional environmental parameters.
Implementation of machine learning algorithms for predictive home automation.
