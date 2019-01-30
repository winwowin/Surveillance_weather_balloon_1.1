# Surveillance_weather_balloon_1.1

The challange was to build a surveillance weather balloon on Raspberry Pi 3 using C++, to collect tempereture, pressure, altitude, coordinate location, pictures, and beam all the data back to ground station.

The balloon need to get all the data and beam back every 10 second, except the picture that also has a manual taking picture function that will send back right away. It also need to be able to drop the payloads at 1000 and 3000 feet, and will deploy the Raspberry Pi and its components at 5000 feet. Parachute mechanism will be deployed after. 

The balloon itself is fully automated, but can be overwrite from the ground station. The server-client model was used as the balloon was set up as the server and ground station as a client. The challanged also required some data security, so the DIY data encryption was used



