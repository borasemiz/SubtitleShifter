#include "TimeUtils.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>

static constexpr int HOUR = 1000 * 60 * 60;
static constexpr int MINUTE = 1000 * 60;
static constexpr int SECOND = 1000;

std::string TimeUtils::format(long millis)
{
	const int hours = millis / HOUR;
	const int minutes = (millis - (hours * HOUR)) / MINUTE;
	const int seconds = (millis - (hours * HOUR) - (minutes * MINUTE)) / SECOND;
	const int milliseconds = (millis - (hours * HOUR) - (minutes * MINUTE) - (seconds * SECOND));

	std::stringstream stream;
	stream << std::setfill('0') << std::setw(2) << hours << ":";
	stream << std::setfill('0') << std::setw(2) << minutes << ":";
	stream << std::setfill('0') << std::setw(2) << seconds << ",";
	stream << std::setfill('0') << std::setw(3) << milliseconds;

	return stream.str();
}

long TimeUtils::toMilliseconds(const std::string& formatted)
{
	std::vector<std::string> tokens;
	std::stringstream stream(formatted);
	std::string token;

	while (std::getline(stream, token, ':')) {
		tokens.push_back(token);
	}

	const std::string lastToken(tokens.back());
	tokens.pop_back();

	stream = std::stringstream(lastToken);

	while (std::getline(stream, token, ',')) {
		tokens.push_back(token);
	}

	const int hours = std::stoi(tokens[0]);
	const int minutes = std::stoi(tokens[1]);
	const int seconds = std::stoi(tokens[2]);
	const int milliseconds = std::stoi(tokens[3]);

	return hours * HOUR + minutes * MINUTE + seconds * SECOND + milliseconds;
}
