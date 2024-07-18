import cv2
import numpy as np

lower_color = np.array([0, 120, 70])
upper_color = np.array([10, 255, 255])

cap = cv2.VideoCapture(0)  
def is_ball_in_hoop(x, y, w, h):
    hoop_x, hoop_y, hoop_w, hoop_h = 300, 200, 100, 100
    return (x > hoop_x and x + w < hoop_x + hoop_w and
            y > hoop_y and y + h < hoop_y + hoop_h)

while True:
    ret, frame = cap.read()
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    mask = cv2.inRange(hsv, lower_color, upper_color)
    contours, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    
    for contour in contours:
        area = cv2.contourArea(contour)
        if area > 500:  
            x, y, w, h = cv2.boundingRect(contour)
            cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)
            
            if is_ball_in_hoop(x, y, w, h):
                print("Shot made!")
            else:
                print("Shot missed!")

    cv2.imshow("Frame", frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
