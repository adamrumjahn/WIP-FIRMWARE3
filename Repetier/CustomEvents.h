#pragma once
extern void TuningData100MS();
extern void TuningData500MS();
extern void SendTuningData();

//#undef EVENT_TIMER_100MS
//#undef EVENT_TIMER_500MS
//
//#define EVENT_TIMER_100MS {TuningData100MS();}
//#define EVENT_TIMER_500MS {TuningData500MS();}