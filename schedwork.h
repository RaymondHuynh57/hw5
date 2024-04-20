#ifndef SCHEDWORK_H
#define SCHEDWORK_H

#ifndef RECCHECK
#include <vector>
//Temporary
//#include <map>
#endif

// type for the ID of a worker
typedef unsigned int Worker_T;
// n-by-k Matrix of each of the k workers' availability over an n-day period
typedef std::vector<std::vector<bool>> AvailabilityMatrix;

// n-by-d matrix with the d worker IDs who are scheduled 
// to work on each of the n days
typedef std::vector<std::vector<Worker_T> > DailySchedule;

/**
 * @brief Produces a work schedule given worker availability,
 *        the number of needed workers per day, and the maximum 
 *        shifts any single worker is allowed. Returns true
 *        and the valid schedule if a solution exists, and false
 *        otherwise. 
 * 
 * @param [in]  avail n x k vector of vectors (i.e. matrix) of the availability
 *                    of the k workers for each of the n days
 * @param [in]  dailyNeed Number of workers needed per day (aka d)
 * @param [in]  maxShifts Maximum shifts any worker is allowed over 
 *                        the n day period (aka m)
 * @param [out] sched n x d vector of vectors indicating the d workers
 *                    who are scheduled to work on each of the n days
 * @return true if a solution exists; sched contains the solution
 * @return false if no solution exists; sched is undefined (can be anything)
 */
bool schedule(
    const AvailabilityMatrix& avail,
    const size_t dailyNeed,
    const size_t maxShifts,
    DailySchedule& sched
);

bool Schedule_Recurse_Helper(
    const AvailabilityMatrix& avail,
    const size_t dailyNeed, //d go on the same row
    const size_t maxShifts, //m go down the column and count the same ID number
    DailySchedule& sched,
    size_t row,
    size_t col,
    size_t dailyNeed_counter,
    std::vector<size_t>& shifts_each_worker
);

bool avail_Recurse_Helper_Horizontal(
    const AvailabilityMatrix& avail,
    const size_t dailyNeed, //d go on the same row
    const size_t maxShifts, //m go down the column and count the same ID number
    DailySchedule& sched,
    size_t row,
    size_t col,
    size_t id_counter,
    const Worker_T& value,
    Worker_T real_value,
    std::vector<size_t>& shifts_each_worker
);

bool avail_Recurse_Helper_Horizontal_Zero(  //This function runs when the row beginning starts with a zero as its boolean value
    const AvailabilityMatrix& avail,
    const size_t dailyNeed, //d go on the same row
    const size_t maxShifts, //m go down the column and count the same ID number
    DailySchedule& sched,
    size_t row,
    size_t col,
    size_t id_counter,
    const Worker_T& value,
    Worker_T real_value,
    std::vector<size_t>& shifts_each_worker
);
bool avail_Recurse_Helper(const AvailabilityMatrix& avail,
    const size_t dailyNeed, //d go on the same row
    const size_t maxShifts, //m go down the column and count the same ID number
    DailySchedule& sched,
    size_t row,
    size_t col,
    size_t id_counter,
    const Worker_T& value
);

#endif