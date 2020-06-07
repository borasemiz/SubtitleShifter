#ifndef TIME_UTILS_H
#define TIME_UTILS_H

#include <string>

namespace TimeUtils {
std::string format(long milliseconds);
long toMilliseconds(const std::string& formatted);
};

#endif // !TIME_UTILS_H
