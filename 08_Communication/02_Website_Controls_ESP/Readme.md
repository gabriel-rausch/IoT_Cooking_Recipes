# Website Controls ESP hardware

In this example the ESP hosts a website that allows the user to control hardware components of the ESP.

After ESP's boot you can connect to its access point. Open the ESPs IP (should be 192.168.1.1, but check main.cpp), a small website appears. If you connected an LED to the specific pin you can now start switching it on or off.

Annotation: consider the html fragment within the file "website-index.h", that is included as a char.

<video controls="controls" src="demo_website_controls_espfilename.mp4">
</video>