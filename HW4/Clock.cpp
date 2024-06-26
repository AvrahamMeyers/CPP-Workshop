#include "Clock.h"
#include <iostream>

Clock::Clock(int hour, int minute, int seconds) {
	try {
		if (hour > 23)
			throw "more than 24 hours\n";
		if (hour < 0)
			throw "negative number of hours\n";
		if (minute > 59)
			throw "more than 60 minutes\n";
		if (minute < 0)
			throw "negative number of minutes\n";
		if (seconds > 59)
			throw "more than 60 seconds\n";
		if (seconds < 0)
			throw "negative number of seconds\n";
	}
	catch (char* errorMessage) {
		std::cout << "Invalid time - " << errorMessage;
	}
	Clock(0, 0, 0);
}

void Clock::operator+=(int seconds) {
	this->seconds += seconds;

	if (this->seconds >= 60) {
		int extraminutes = this->seconds / 60;
		this->minute += extraminutes;
		this->seconds -= extraminutes * 60;

		if (this->minute >= 60) {
			int extrahour = this->minute / 60;
			this->hour += extrahour;
			this->minute -= extrahour * 60;
		}
	}
}

std::ostream& operator<<(std::ostream& out, const Clock& C) {	
	
	(C.hour < 10) ? out << '0' << C.hour : out << C.hour;
	out << ':';
	(C.minute < 10) ? out << '0' << C.minute : out << C.minute;
	out << ':';
	(C.seconds< 10) ? out << '0' << C.seconds : out << C.seconds << '\n';

	return out;
}

std::istream& operator>>(std::istream& in, Clock& C) {
	char skip;
	in >> C.hour >> skip >> C.minute >> skip >> C.seconds;
	try {
		if (C.hour > 23)
			throw "more than 24 hours\n";
		if (C.hour < 0)
			throw "negative number of hours\n";
		if (C.minute > 59)
			throw "more than 60 minutes\n";
		if (C.minute < 0)
			throw "negative number of minutes\n";
		if (C.seconds > 59)
			throw "more than 60 seconds\n";
		if (C.seconds < 0)
			throw "negative number of seconds\n";
	}
	catch (char* errorMessage) {
		std::cout << "Invalid time - " << errorMessage;
	}
	return in;
}
