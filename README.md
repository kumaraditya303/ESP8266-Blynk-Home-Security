# ESP8266 Blynk Home Security -> An IOT Project

## This project uses Blynk IOT platform and sends email and mobile notification when an intruder is detected via PIR Sensor. The email sent contains the time when the intruder was detected by fetching the current time from http://pool.ntp.org/ via NTPClient.

<br>

# Get Started!

## Prerequisites

- [Python](https://www.python.org/)
- Install PlatformIO

```bash
$ pip install platformio
```

- [Blynk Account](https://blynk.io/)
- NodeMCU or ESP8266 compatible board

## Setup

> This projet uses [PlatformIO](https://platformio.org/) for compilation and uploading to the board.

- Create account on Blynk App
- Create a new project and add email and notification widgets.

- Download the project using git.

```bash
$ git clone https://github.com/kumaraditya303/ESP8266-Blynk-Home-Security.git
```

- Update the credentials in [config.h](./include/config.h) and the token sent at your email.

- Connect PIR Sensor or Pin D5 or as per your configuration.

- Connect your board with the computer and compile the project.

```bash
$ platformio run
```

- Done!

# Project made and maintained by [Kumar Aditya](https://github.com/kumaraditya303)
