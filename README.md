# ESP32 HTTP Client

Send sensor data from ESP32 to a server using HTTP POST requests over WiFi.

---

## 🚀 Features

- WiFi connection
- HTTP POST requests
- JSON payload transmission
- Periodic sensor data sending
- Compatible with local or cloud servers

---

## 🌐 Architecture

ESP32 sends sensor data to a backend server (Flask / Node.js / REST API).
ESP32 → HTTP Server → Database / Dashboard / AI


---

## 🔌 Example Server Endpoint

Default example in code:
http://192.168.1.10:5000/data


You can replace this with:
- Flask server (Python)
- Node.js Express API
- Cloud API endpoint

---

## 📦 Example Payload

```json
{"ldr": 2345}```

---

## How to Use
1. Install ESP32 board in Arduino IDE
2. Edit WiFi credentials in main.ino
3. Change server IP to your computer/server
4. Run your backend server
5. Upload code to ESP32
6. Open Serial Monitor (115200 baud)
You should see HTTP response codes from the server.

---

## How to Use
```
from flask import Flask, request

app = Flask(__name__)

@app.route("/data", methods=["POST"])
def receive_data():
    print(request.json)
    return {"status": "ok"}

app.run(host="0.0.0.0", port=5000)
```

## 📄 License

MIT License

## 🔗 Credits

ESP32 HTTPClient library is part of the ESP32 Arduino Core:
https://github.com/espressif/arduino-esp32