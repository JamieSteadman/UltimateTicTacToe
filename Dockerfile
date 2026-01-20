FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive
ENV DISPLAY=:0

# Install GTK, build tools, and VNC stack
RUN apt-get update && apt-get install -y \
    build-essential \
    pkg-config \
    libgtk-3-dev \
    xvfb \
    x11vnc \
    novnc \
    websockify \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy source code
COPY . .

# Build your app
RUN make

# noVNC setup
RUN mkdir -p /opt/novnc \
    && ln -s /usr/share/novnc/vnc.html /opt/novnc/index.html

RUN ln -sf /usr/share/novnc/vnc_auto.html /usr/share/novnc/index.html

# Startup script
COPY start.sh /start.sh
RUN chmod +x /start.sh

EXPOSE 8080

CMD ["/start.sh"]
