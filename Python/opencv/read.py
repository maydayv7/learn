import cv2 as cv

# Read Image
img = cv.imread('Image.jpg')

# Show Image
cv.imshow('Window', img)

# Wait timeout before key is pressed
# cv.waitKey(0)

# Read Video
#   Takes either path to video file or integer
#   0 -> Webcam; 1,2,3... -> Additional Cameras
capture = cv.VideoCapture('Video.mp4')

# Show Video
while True:
    isTrue, frame = capture.read()

    # Show each frame
    cv.imshow('Video', frame)

    # Close window if key 'q' is pressed
    if cv.waitKey(20) & 0xFF == ord('q'):
        break

capture.release()
cv.destroyAllWindows()
