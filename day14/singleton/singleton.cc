#include "singleton.h"

Log *Log::ptrLog_ = nullptr;

Log::Log() {}

Log *Log::initLog()
{
  if (!ptrLog_)
  {
    ptrLog_ = new Log();
  }
  return ptrLog_;
}
