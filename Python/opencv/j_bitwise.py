import cv2 as cv
import numpy as np

blank = np.zeros((400, 400), dtype='uint8')

rectangle = cv.rectangle(blank.copy(), (30, 30), (370, 370), 255, -1)
cv.imshow("Rectangle", rectangle)

circle = cv.circle(blank.copy(), (200, 200), 200, 255, -1)
cv.imshow("Circle", circle)

# Bitwise AND
cv.imshow("AND", cv.bitwise_and(rectangle, circle))

# Bitwise OR
cv.imshow("OR", cv.bitwise_or(rectangle, circle))

# Bitwise XOR
cv.imshow("XOR", cv.bitwise_xor(rectangle, circle))

# Bitwise NOT
cv.imshow("NOT", cv.bitwise_not(rectangle))

cv.waitKey(0)
input('')
