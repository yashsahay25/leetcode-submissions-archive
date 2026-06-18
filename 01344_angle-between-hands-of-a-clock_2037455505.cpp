class Solution {
public:
    double angleClock(int hour, int minutes) {
        // m = 360 in 60 min = 6 deg per min
        // h = 30 in 60 min = 0.5 deg per min + how much ahead of 12 o' clock

        if(hour==12) hour=0;

        double angle = 0.0;
        double minAngle = 6.0*minutes;
        double hAngle = 0.5*minutes + hour*30.0;

        angle = abs(hAngle - minAngle);
        return angle > 180.0 ? (360.0-angle) : angle;
    }
};