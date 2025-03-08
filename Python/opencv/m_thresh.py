import cv2 as cv

img = cv.imread('Image.jpg')
cv.imshow('Image', img)
gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

# Simple Thresholding (Grayscale Image, Threshold, Maximum Value, Threshold Type)
#   Thresholds determine brightness of pixel based on its density
#   If lesser than specified value, then black, else white (binarizes image)
threshold, thresh = cv.threshold(gray, 150, 255, cv.THRESH_BINARY)
cv.imshow('Simple Thresholded', thresh)

threshold, thresh_inv = cv.threshold(gray, 150, 255, cv.THRESH_BINARY_INV)
cv.imshow('Simple Thresholded Inverse', thresh_inv)

# Adaptive Thresholding (Grayscale Image, Threshold, Maximum Value, Adaptive Method, Threshold Type, Kernel Size, C Value)
#  Determines optimum threshold value automatically
#  Method -> MEAN or GAUSSIAN
#  C -> Integer subtracted from mean, to fine-tune thresholding
adaptive_thresh = cv.adaptiveThreshold(
    gray, 255, cv.ADAPTIVE_THRESH_MEAN_C, cv.THRESH_BINARY, 11, 3)
cv.imshow('Adaptive Thresholded', adaptive_thresh)

cv.waitKey(0)
input('')
