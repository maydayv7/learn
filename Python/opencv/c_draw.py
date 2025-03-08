import cv2 as cv
import numpy as np

# Blank Image (Height, Width, Color Channels)
blank = np.zeros((500, 500, 3), dtype='uint8')
cv.imshow('Blank', blank)

# 1. Square
blank[200:300, 300:400] = 0, 0, 255
cv.imshow('Square', blank)

# 2. Rectangle (Image, Start, End, Color)
cv.rectangle(blank, (0, 0), (250, 250), (0, 255, 0), thickness=2)
cv.imshow('Rectangle', blank)

# 3. Circle (Image, Centre, Radius)
cv.circle(blank, (blank.shape[1] // 2,
          blank.shape[0] // 2), 40, (255, 0, 0), thickness=3)
cv.imshow('Circle', blank)

# Set 'thickness' to 'CV.FILLED' or -1 to fill shape with color

# 4. Line (Image, Start, End, Color)
cv.line(blank, (0, 0), (500, 500), (255, 255, 255), thickness=2)
cv.imshow('Line', blank)

# 5. Text (Image, Text, Origin, Font Face, Font Scale, Color, Thickness)
cv.putText(blank, 'Hello', (255, 255),
           cv.FONT_HERSHEY_TRIPLEX, 1.0, (0, 255, 255), 2)
cv.imshow('Text', blank)

cv.waitKey(0)
input('')
