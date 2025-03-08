import cv2 as cv
import numpy as np

img = cv.imread('Image.jpg')
cv.imshow('Image', img)


def translate(img, x, y):  # Translation
    tMatrix = np.float32([[1, 0, x], [0, 1, y]])
    dimensions = (img.shape[1], img.shape[0])

    return cv.warpAffine(img, tMatrix, dimensions)
    # Translate x -> Right and y -> Down


translated = translate(img, -100, 100)
cv.imshow('Translation', translated)


def rotate(img, angle, rotatePoint=None):  # Rotation
    (height, width) = img.shape[:2]

    if rotatePoint is None:
        rotatePoint = (width // 2, height // 2)

    rMatrix = cv.getRotationMatrix2D(rotatePoint, angle, 1.0)
    dimensions = (width, height)

    return cv.warpAffine(img, rMatrix, dimensions)


rotated = rotate(img, 45)
cv.imshow('Rotation', rotated)

# Resizing
resize = cv.resize(img, (500, 500), interpolation=cv.INTER_AREA)  # Shrink
resize = cv.resize(img, (500, 500), interpolation=cv.INTER_LINEAR)  # Enlarge
cv.imshow('Resize', resize)

# Flipping (Image, Code)
#   0 -> Flip Vertically (X Axis)
#   1 -> Flip Horizontally (Y Axis)
#   -1 -> Flip both ways

flip = cv.flip(img, 1)
cv.imshow('Flip', flip)

cv.waitKey(0)
input('')
