import cv2 as cv

img = cv.imread('Image.jpg')
cv.imshow('Image', img)

# Averaging (Image, Kernel)
#  Average of intensities of surrounding pixels in kernel is applied to center
average = cv.blur(img, (7, 7))
cv.imshow('Average', average)

# Gaussian (Image, Kernel, Sigma)
#  Average of products of weights of surrounding pixels in kernel is applied to center
#  Looks more natural
gauss = cv.GaussianBlur(img, (7, 7), 0)
cv.imshow('Gaussian', gauss)

# Median (Image, Kernel Size)
#  Median of intensities of surrounding pixels in kernel is applied to center
#  Reduces substantial amount of noise
median = cv.medianBlur(img, 7)
cv.imshow('Median', median)

# Bilateral (Image, Diameter, Sigma Color, Sigma Space)
#  Blurs image whilst also retaining edges
bilateral = cv.bilateralFilter(img, 10, 35, 25)
cv.imshow('Bilateral', bilateral)

cv.waitKey(0)
input('')
