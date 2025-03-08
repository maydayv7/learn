import cv2 as cv


def rescaleFrame(frame, scale=0.75):  # Resizes images, video, live video
    width = int(frame.shape[1] * scale)
    height = int(frame.shape[0] * scale)
    dimensions = (width, height)
    return cv.resize(frame, dimensions, interpolation=cv.INTER_AREA)


def changeRes(capture, width, height):  # Resizes live video
    # 3,4 -> Object Properties
    capture.set(3, width)
    capture.set(4, height)


capture = cv.VideoCapture('Video.mp4')
while True:
    isTrue, frame = capture.read()
    cv.imshow('Video', frame)

    frame_resized = rescaleFrame(frame)
    cv.imshow('Video Resized', frame_resized)

    if cv.waitKey(20) & 0xFF == ord('d'):
        break

capture.release()
cv.destroyAllWindows()
