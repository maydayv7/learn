import cv2 as cv
import numpy as np

img = cv.imread('Image.jpg')
cv.imshow('Image', img)
gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

# Laplacian (Grayscale Image, Data Depth)
#  Black -> White: Positive Slope, else Negative
lap = cv.Laplacian(gray, cv.CV_64F)
lap = np.uint8(np.absolute(lap))
cv.imshow('Laplacian', lap)

# Sobel
#  Computes gradients in 2 directions
sobelx = cv.Sobel(gray, cv.CV_64F, 1, 0)
sobely = cv.Sobel(gray, cv.CV_64F, 0, 1)
sobel = cv.bitwise_or(sobelx, sobely)
cv.imshow('Sobel', sobel)

# Canny
canny = cv.Canny(gray, 150, 175)
cv.imshow('Canny', canny)

cv.waitKey(0)
input('')
