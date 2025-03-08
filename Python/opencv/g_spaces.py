import cv2 as cv
import matplotlib.pyplot as plt

img = cv.imread('Image.jpg')
cv.imshow('BGR', img)  # BGR Format (Blue Green Red)

# BGR to Grayscale
gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow('Gray', gray)

# BGR to HSV (Hue Saturation Value)
hsv = cv.cvtColor(img, cv.COLOR_BGR2HSV)
cv.imshow('HSV', hsv)

# BGR to LAB (L*a*b)
lab = cv.cvtColor(img, cv.COLOR_BGR2LAB)
cv.imshow('LAB', lab)

# BGR to RGB
rgb = cv.cvtColor(img, cv.COLOR_BGR2RGB)
cv.imshow('RGB', rgb)
plt.imshow(rgb)
plt.show()

cv.waitKey(0)
input('')
