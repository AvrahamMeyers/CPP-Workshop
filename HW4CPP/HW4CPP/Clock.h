#pragma once
#include <iostream>

class Clock {
	
	friend std::ostream& operator<<(std::ostream& out, const Clock& C);
	friend std::istream& operator>>(std::istream& in, Clock& C);

	int hour = 0;
	int minute = 0;
	int seconds = 0;

public:
		
	void sethour(int hour) { this->hour = hour; }
	int gethour() { return this->hour; }
	void setminute(int minute) { this->minute = minute; }
	int getminute() { return this->minute; }
	void setsecond(int second) { this->seconds = second; }
	int getsecond() { return this->seconds; }

	Clock() : hour(0), minute(0), seconds(0) {};
	Clock(int hour, int minute, int seconds);
	Clock(int hour) : hour(hour), minute(0), seconds(0) {};

	Clock(const Clock& C) : hour(C.hour), minute(C.minute), seconds(C.seconds) {};

	void operator+=(int seconds);

}; 
