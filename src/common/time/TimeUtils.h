/* Copyright (c) 2018 vesoft inc. All rights reserved.
 *
 * This source code is licensed under Apache 2.0 License,
 * attached with Common Clause Condition 1.0, found in the LICENSES directory.
 */

#ifndef COMMON_TIME_TIMEUTILS_H_
#define COMMON_TIME_TIMEUTILS_H_

#include <sys/time.h>

namespace nebula {
namespace time {

class TimeUtils final {
public:
    ~TimeUtils() = default;

    static int64_t nowInMSeconds() {
        struct timeval tp;
        gettimeofday(&tp, NULL);
        return tp.tv_sec * 1000 + tp.tv_usec / 1000;
    }

    static int64_t nowInUSeconds() {
        struct timeval tp;
        gettimeofday(&tp, NULL);
        return tp.tv_sec * 1000000 + tp.tv_usec;
    }

    static int64_t nowInSeconds() {
        struct timeval tp;
        gettimeofday(&tp, NULL);
        return tp.tv_sec;
    }

private:
    TimeUtils() = delete;
};

}  // namespace time
}  // namespace nebula

#endif  // COMMON_TIME_TIMEUTILS_H_

