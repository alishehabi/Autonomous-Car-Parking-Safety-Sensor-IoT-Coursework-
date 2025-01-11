# Autonomous Car Parking Safety Sensor

## Overview
The **Autonomous Car Parking Safety Sensor** is a robust IoT-based system designed to enhance vehicle and pedestrian safety during parking maneuvers. It integrates multiple sensors—PIR, IR, and Ultrasonic—to provide real-time feedback to drivers through LEDs and a buzzer, ensuring precise parking assistance. This project is a step forward in addressing the challenges of urban parking, promoting efficiency, and reducing accidents.

## Key Features
- **Real-Time Feedback:** Visual (LEDs) and auditory (buzzer) cues guide drivers during parking.
- **Motion Detection:** Activates only when motion is detected using PIR and IR sensors, optimizing power usage.
- **Distance Measurement:** Uses an ultrasonic sensor to calculate and communicate object proximity.
- **Energy Efficiency:** Operates efficiently by deactivating components when not in use.
- **Scalability:** Designed to integrate into vehicles or parking infrastructures.

## Components
1. **Sensors:**
   - HC-SR04 Ultrasonic Sensor: Measures distances to obstacles.
   - HC-SR501 PIR Sensor: Detects motion.
   - IR Sensor: Enhances motion detection reliability.
2. **Indicators:**
   - LEDs (Red, Yellow, Green): Indicate proximity thresholds.
   - Buzzer: Audible alert with variable frequency based on distance.
3. **Controller:**
   - Arduino UNO Wi-Fi Rev2: Processes sensor data and controls outputs.

## System Flow
1. Detect motion using PIR and IR sensors.
2. Activate the ultrasonic sensor to measure object distances.
3. Provide feedback:
   - **Green LED:** Safe distance.
   - **Yellow LED:** Caution—approaching object.
   - **Red LED & Buzzer:** Stop—very close to an obstacle.
<img width="609" alt="Screenshot 2025-01-11 at 17 05 46" src="https://github.com/user-attachments/assets/7023132f-bd03-492c-9d59-05b7750b9ab7" />

<img width="224" alt="Screenshot 2025-01-11 at 17 06 06" src="https://github.com/user-attachments/assets/70fec64a-5fa6-4d8b-bf8d-eba4bdbfab36" />

## Use Cases
- **Vehicle Parking Assistance:** Enhances safety and reduces collision risks.
- **Smart Parking Lots:** Real-time monitoring of parking spaces.
- **Smart Homes:** Integrates with garage doors and security systems for enhanced utility.

## Testing Results
- **Accuracy:** Ultrasonic sensor demonstrated a static error rate of 0.213% and a dynamic error rate of 0.360%.
- **Reliability:** Sensors performed consistently across varying lighting conditions (bright and dark).
- **Energy Efficiency:** Efficient operation by activating components only when motion is detected.

## Future Enhancements
1. **Advanced Sensors:** Incorporate LiDAR or vision-based sensors for higher precision.
2. **Mobile Integration:** Develop a mobile app for real-time monitoring and customization.
3. **Sustainability:** Utilize solar panels for a more eco-friendly power source.
4. **Smart Integration:** Expand compatibility with smart home and city systems.

## Installation & Setup
1. Assemble the components as per the circuit diagram.
2. Upload the code to the Arduino UNO using the Arduino IDE.
3. Power the system using a 9V battery.
4. Test the sensors and ensure proper calibration.

## Contributions
Contributions are welcome! Feel free to submit issues, feature requests, or pull requests.

## References
- [Industry 4.0 Overview](https://www.mckinsey.com/featured-insights/mckinsey-explainers/what-are-industry-4-0-the-fourth-industrial-revolution-and-4ir)
- [Backing Assistance Systems](https://www.sciencedirect.com/science/article/pii/S0022437518303451)
- [Sensor Technologies](https://www.automaticdoorspecialist.co.uk/pir-and-ir-sensors)

---

### License
This project is open-source under the [MIT License](LICENSE).

---
