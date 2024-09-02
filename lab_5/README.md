# Lab 5: Heart Rate Monitor (pt. 2)

For instructions, please checkout [NFR Learn](https://nfr-learn.ue.r.appspot.com/lessons).

*Note: This lab is split into two parts. This is part 2. You should have completed part 1 before starting this part. This directory does not contain student code. Instead, you should continue working in the same directory as part 1.*

This directory contains the source code for the "doctor" side of the heart rate monitor. The doctor side is responsible for receiving heart rate data from the various heart rate montitors (student-built), and displaying the data on a webpage. This webpage is hosted on the ESP32, and can be accessed by connecting to the ESP32's WiFi network.

To view the webpage, connect to the ESP32's WiFi network. The credentials are as follows:
```
SSID: NFR-Doctor
Password: BreatheInBreatheOut
```

Once connected, open a web browser and navigate to `http://x.x.x.x` (this is the IP address of the ESP32). You should see a webpage displaying the heart rate data from the various monitors.