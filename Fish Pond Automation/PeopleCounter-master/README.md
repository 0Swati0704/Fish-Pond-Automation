Fish Pond Automation Project Overview

Traditional fish farming methods often lack efficient monitoring and control systems, leading to challenges for fish farmers. These include:

Inadequate Environmental Monitoring: Difficulty in maintaining optimal conditions like temperature, pH levels, and water quality.
Manual Fish Counting: Labor-intensive fish counting methods leading to inaccuracies and inefficiencies.
Limited Control: Insufficient control over environmental factors affecting fish health and growth.

This project aimed to modernize fish farming practices by implementing an IoT-based system. This setup included various sensors: Humidity, Temperature, pH, Solenoid, and Turbidity. Additionally, we deployed a Python model for fish counting utilizing video feed analysis.

Sensors Integrated:
Humidity Sensor
Temperature Sensor
pH Sensor
Solenoid Sensor
Turbidity Sensor

Fish Counting System:

Developed a Python-based model leveraging OpenCV and NumPy libraries.

The model utilized background subtraction, contour detection, and fish tracking techniques.

Code Flow Explanation:
Libraries and Initialization: Imports required libraries, initializes log files, and person counters.
Video Capture and Setup: Uses OpenCV's VideoCapture to read frames, prints video properties.
Region of Interest and Counting Lines: Defines critical areas and lines for tracking.
Background Subtraction and Morphological Operations: Highlights moving objects and refines images.
Fish Tracking: Tracks fish movements, logs events when fish cross predefined lines.
Drawing and Display: Visualizes fish trajectories and count information in real-time.
Real-Time Processing Loop: Continuously processes video frames, updating tracked object details.
This system revolutionizes fish farming, offering precise environmental monitoring and an efficient fish counting mechanism, enhancing productivity and control for fish farmers.

# FishCounter
Basic Fish Counter using Python and OpenCV

Install anaconda
pip install opencv-python

python PeopleCounter.py
