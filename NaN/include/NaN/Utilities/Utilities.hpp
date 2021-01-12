#pragma once

#define EMPTY_STRING ""
#define ZERO 0

#define NEXT(line) (i + 1 < (uint32_t)line.size() ? line[i + 1] : 0)
#define PREV(line) (i - 1 >= 0 && line.size() > 0 ? line[i - 1] : 0)