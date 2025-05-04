
# Edge AI PPE Violation Detection and MCB Shutdown

This project presents an **Edge AI framework** that performs **real-time Personal Protective Equipment (PPE) violation detection** using a Raspberry Pi and a YOLOv8 model. Upon detecting repeated violations, it **triggers a servo-actuated Miniature Circuit Breaker (MCB) shutdown** via an ESP32 microcontroller.

---

## 🔧 Hardware Components
- Raspberry Pi 4 (64-bit OS)
- ESP32 Dev Board
- SG90 Servo Motor
- USB Camera or Pi Camera Module
- 5V Power Supplies
- UART Serial Connection between Pi and ESP32

---

## 🧠 Software Stack
- Python 3 (Thonny IDE / venv)
- OpenCV
- ONNXRuntime
- YOLOv8 model (trained on custom Roboflow dataset)
- Serial communication (PySerial)
- `libcamera-vid` for Pi camera access

---

## ⚙️ How It Works
1. The Raspberry Pi captures live video and runs YOLOv8 inference in real-time.
2. It detects objects like:
   - ✅ Hardhat, Mask, Safety Vest
   - ❌ NO-Hardhat, NO-Mask, NO-Safety Vest
3. After 10 consecutive violation frames, Pi sends `MCB_OFF` over UART.
4. The ESP32 receives this signal and activates a servo motor to flip the MCB.

---

## 📁 Project Structure
Edge-AI-Real-Time-PPE-Violation-Detection-and-MCB-Shutdown/
├── Dataset_Report.docx          # Summary of dataset characteristics, sources, and annotations
├── PPEvideoscript2.txt          # Script for detection from live video feed, (Goes into Raspberry pi 4)
├── README.md                    # Project overview and instructions (this file)
├── YOLOv8_PPE2Final.ipynb       # Google Colab notebook used for training the YOLOv8 model
├── best.pt                      # Final trained YOLOv8 PyTorch model weights
├── yolov8n.pt                   # YOLOv8n (nano) base model used for transfer learning
├── sketch_apr27a.ino            # Arduino (ESP32) code to receive UART signal and control servo motor
├── best.onnx                    # The Model which is utilized by raspberry pi


