import cv2 as cv
import numpy as np

img = cv.imread('Image.jpg')
cv.imshow('Image', img)

gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
blur = cv.GaussianBlur(gray, (5, 5), cv.BORDER_DEFAULT)

# Canny Edge Cascade
canny = cv.Canny(blur, 125, 175)
cv.imshow('Canny', canny)

# Contour Type:
#   RETR_LIST -> All Contours
#   RETR_TREE -> Hierarchical Contours
#   RETR_EXTERNAL -> External Contours
# Contour Approximation:
#   CHAIN_APPROX_NONE -> No Approximation
#   CHAIN_APPROX_SIMPLE -> Simple Approximation (Eg. Compresses line to only 2 end points)

contours, hierarchies = cv.findContours(
    canny, cv.RETR_LIST, cv.CHAIN_APPROX_SIMPLE)
print(f'{len(contours)} contour(s) found for canny')

# Thresholding
#   Thresholds determine brightness of pixel based on its density
#   If lesser than specified value, then black, else white (binarizes image)
ret, thresh = cv.threshold(gray, 125, 255, cv.THRESH_BINARY)
cv.imshow('Thresh', thresh)

contours2, hierarchies2 = cv.findContours(
    thresh, cv.RETR_LIST, cv.CHAIN_APPROX_SIMPLE)
print(f'{len(contours2)} contour(s) found for thresh')

# Draw Contours (Image, Contours, Contour IDs, Color, Thickness)
blank = np.zeros(img.shape, dtype='uint8')
cv.drawContours(blank, contours, -1, (0, 0, 255), 1)
cv.imshow('Contours', blank)

cv.waitKey(0)
input('')
