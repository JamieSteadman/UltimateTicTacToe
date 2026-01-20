#!/bin/bash
set -e

# Start virtual display
Xvfb :0 -screen 0 1280x800x24 &

# Start VNC server
x11vnc -display :0 -nopw -forever -shared &

# Launch your GTK app
./main &

# Start noVNC
websockify --web=/usr/share/novnc/ 8080 localhost:5900
