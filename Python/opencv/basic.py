import cv2 as cv

img = cv.imread('Image.jpg')
cv.imshow('Image', img)

# Grayscale Image
gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow('Gray', gray)

# Blur Image (Image, Kernel, Sigma, Border)
blur = cv.GaussianBlur(img, (3, 3), cv.BORDER_DEFAULT)
cv.imshow('Blur', blur)

# Edge Cascade (Image, Thresholds)
canny = cv.Canny(img, 125, 175)
cv.imshow('Canny Edges', canny)

# Dilating Image (Image, Kernel, Iterations, Border)
dilate = cv.dilate(canny, (7, 7), iterations=3)
cv.imshow('Dilated', dilate)

# Eroding Image (Image, Kernel, Iterations, Border)
erode = cv.erode(dilate, (7, 7), iterations=3)
cv.imshow('Erode', erode)

# Resize
resize = cv.resize(img, (500, 500), interpolation=cv.INTER_CUBIC)
cv.imshow('Resize', resize)

# Cropping
crop = img[50:200, 200:400]
cv.imshow('Crop', crop)

cv.waitKey(0)
input('')
