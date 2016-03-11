#ifndef PCTIMER_H
#define PCTIMER_H

#include <iostream>         // provides: cerr
#include <ctime>            // provides: clock, CLOCKS_PER_SEC and CLK_TCK

class Timer
{
public:
    Timer();
    void start();
    void stop();
    void reset();
    bool isRunning() const;
    double lapTime() const;         // elapsed time without stopping
    double elapsedTime() const;     // since last start
    double cumulativeTime() const;  // total over all start/stops
    double granularity() const;

private:
    bool amRunning;
    clock_t myStartTime;
    clock_t myElapsed;
    clock_t myCumulative;
};

inline Timer::Timer()
: amRunning(false), myElapsed(0), myCumulative(0) {}

inline void Timer::start()
{
  if(amRunning)
    std::cerr << "attempt to start an already running stopwatch" << std::endl;
  else
  {
    amRunning = true;
    myStartTime = clock();
  }
}

inline void Timer::stop()
{
  if(!amRunning)
    std::cerr << "attempt to stop a non-running stopwatch" << std::endl;
  else
  {
    clock_t myEndTime = clock();
    myElapsed = myEndTime - myStartTime;
    myCumulative += myElapsed;            
    amRunning = false;
  }
}

inline void Timer::reset()
{amRunning = false; myElapsed = 0; myCumulative = 0;}
   
inline bool Timer::isRunning() const
{return amRunning;}

inline double Timer::lapTime() const
{return amRunning ? double(clock() - myStartTime) / CLOCKS_PER_SEC : 0.0;}

inline double Timer::elapsedTime() const
{return amRunning ? 0.0 : double(myElapsed) / CLOCKS_PER_SEC;}

inline double Timer::cumulativeTime() const
{return (double(myCumulative) / CLOCKS_PER_SEC) + lapTime();}

inline double Timer::granularity() const
{return 1.0 / CLOCKS_PER_SEC;}

#endif
