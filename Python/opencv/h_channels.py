import cv2 as cv
import numpy as np

img = cv.imread('Image.jpg')
cv.imshow('Image', img)
print(img.shape)

# Split into color channels
b, g, r = cv.split(img)

# Shape is 1 so displayed as grayscale image
#   White color -> Higher color density
#   Black color -> Lower color density
cv.imshow('Blue Density', b)
print(b.shape)
cv.imshow('Green Density', g)
print(g.shape)
cv.imshow('Red Density', r)
print(r.shape)

# Merge color channels
merged = cv.merge([b, g, r])
cv.imshow('Merged', merged)

# Print colored images
blank = np.zeros(img.shape[:2], dtype='uint8')
cv.imshow('Blue', cv.merge([b, blank, blank]))
cv.imshow('Green', cv.merge([blank, g, blank]))
cv.imshow('Red', cv.merge([blank, blank, r]))

cv.waitKey(0)
input('')
