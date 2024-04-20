#ifndef RECCHECK
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
// add or remove necessary headers as you please


#endif


#include "schedwork.h"


using namespace std;


// a constant that can be used to indicate an INVALID
// worker ID if that is useful to your implementation.
// Feel free to not use or delete.
static const Worker_T INVALID_ID = (unsigned int)-1;




// Add prototypes for any helper functions here




// Add your implementation of schedule() and other helper functions here


bool schedule(
    const AvailabilityMatrix& avail,
    const size_t dailyNeed,
    const size_t maxShifts,
    DailySchedule& sched
)
{
    if(avail.size() == 0U){
        return false;
    }
    sched.clear();
    // Add your code below
    //DailyNeed is row
    //maxShifts is column


/*
n x k
       W  W  W  W
           o  o  o  o
           r  r  r  r
           k  k  k  k
           e  e  e  e
           r  r  r  r
           0  1  2  3


           |  |  |  |
           |  |  |  |
           V  V  V  V


Day 0 -->  1  1  1  1
Day 1 -->  1  0  1  0
Day 2 -->  1  1  0  1
Day 3 -->  1  0  0  1




n x d
The right side of the equal sign is the amount of shifts left
            worker 0 = 2, worker 1 = 2, worker 2 = 2, worker 3 = 2
1 2         worker 0 = 2, worker 1 = 1, worker 2 = 1, worker 3 = 2    
0 2         worker 0 = 1, worker 1 = 1, worker 2 = 0, worker 3 = 2
1 3         worker 0 = 1, worker 1 = 0, worker 2 = 0, worker 3 = 1
0 3         worker 0 = 0, worker 1 = 0, worker 3 = 0, worker 3 = 0
REAL NOTES FROM ME:
MaxShift = 2, d = amount of workers for each day
For each sched recursion
THIS METHOD DOESN'T Work --------------------------------------------->
[Day0][Worker1]
You start at 1 on the top left, the amount of 0 index ID worker is 1
Recurse to the next row and col 0, now       0 index ID worker = 2  [Day1][Worker0]
Recurse to the next row and col 0, now       0 index ID worker = 3 which is greater than Maxshift = 2. [Day2][Worker0] NOT GOOD
Return to go back up to the previous row and find the next 1 true boolean value from avaiabilityMatrix      0 index ID worker = 1, 2 index ID worker = 1    [Day1][Worker2]
Recurse to the next row and col 0, now       0 index ID worker = 2, 2 index ID worker = 1       [Day2][Worker0]
Recurse to the next row and col 0, now       0 index ID worker = 3, 2 index ID worker = 1       [Day3][Worker0] NOT GOOD
Return to previous row and find next boolean 1 true     0 index ID worker = 1, 1 index ID worker = 1, 2 index ID worker = 1     [Day2][Worker1]
Recurse to the next row and col 0, now       0 index ID worker = 2, 1 index ID worker = 1, 2 index ID worker = 1    [Day3][Worker0]. GOOD. Go down next row which is empty and return true
Return to go back up to the previous row and find the next 1 true boolean value from availabilityMatrix (In this case, there is no more 1 true boolean value so we return to go back up the row)
You are now back at row/day 0 and go onto the next 1 which is [Day 0][Worker1]


[Day0][Worker1]
Recurse to the next row and col 0, now the amount of 0 index ID worker = 1 and  1 index ID worker = 1    [Day1][Worker0]  0 index ID worker = 1, 1 index ID worker = 1  
Recurse to the next row and col 0, now the amount of 0 index ID worker is 2 and the amount of 1 index ID worker is 1    [Day2][Worker0]    0 index ID worker = 2, 1 index ID worker = 1
Recurse to the next row and col 0, now the amount of 0 index ID worker is 3 and the amount of 1 index ID worker is 1. NOT GOOD since 3 > (maxshift = 2) [Day3][Worker0]     0 index ID worker = 3, 1 index ID worker = 1
Return to go back up to the previous row and find the next 1 true boolean value from availabilityMatrix [Day 2][Worker1]   0 index ID worker = 1, 1 index ID worker = 2
Recurse to the next row and col 0, now the amount of 0 index ID worker is 2 and the amount of 1 index ID worker is 2. GOOD. Go next row which is empty which returns true. [Day3][Worker0]      0 index ID worker = 2, 1 index ID worker = 2
Since it is true now, go all the way back up to the day 0 row, and sched pushback 1 [Day0][Worker1] which on the top row since that is the one that started this recursion.


[Day0][Worker3]
Now go find the next 1 true boolean on the same row [Day0][Worker3]
Recurse to the next row and col 0, now      0 index ID worker = 1, 2 index ID worker = 1    [Day1][Worker0]
Recurse to the next row and col 0, now      0 index ID worker = 2, 2 index ID worker = 1    [Day2][Worker0]
Recurse to the next row and col 0, now      0 index ID worker = 3, 2 index ID worker = 1    [Day3][Worker0] NOT GOOD
Return to previous row and find next boolean 1 true     0 index ID worker = 1, 1 index ID worker = 1, 2 index ID worker = 1     [Day2][Worker1]
Recurse to the next row and col 0, now      0 index ID worker = 2, 1 index ID worker = 1, 2 index ID worker = 1     [Day3][Worker0] GOOD. Go next row which is empty and it returns true
Since it is true now, keep returning true all the way back up to the day 0 row, and sched pushback 1 [Day0][Worker2] which is on the top row since that is the one that started this recursion


Now go find the next 1 true boolean on the same row [Day0][Worker3]
Recurse to the next row and col 0, now      0 index ID worker = 1, 2 index ID worker = 1    [Day1][Worker0]
Recurse to the next row and col 0, now      0 index ID worker = 2, 2 index ID worker = 1    [Day2][Worker0]
Recurse to the next row and col 0, now      0 index ID worker = 3, 2 index ID worker = 1    [Day3][Worker0] NOT GOOD
Return to previous row and find next boolean 1 true     0 index ID worker = 1, 1 index ID worker = 1, 2 index ID worker = 1     [Day2][Worker1]
Recurse to the next row and col 0, now      0 index ID worker = 2, 1 index ID worker = 1, 2 index ID worker = 1     [Day3][Worker0] GOOD. Go next row which is empty and it returns true
Since it is true now, keep returning true all the way back up to the day 0 row, and sched pushback 1 [Day0][Worker2] which is on the top row since that is the one that started this recursion


//------------------------------------------------------------------>








So we see in the avail matrix above that every worker is available to work on day 0 while only worker
0 and 2 are available on day 1, and so on.
You should produce a schedule solution that is an n by d matrix,
where each row represents a day in the schedule and stores the d IDs
of the workers who have been scheduled to work that day (each entry
must thus be a value in the range 0 to k-1). So given the availability
matrix above and inputs of m=2 and d=2, a valid schedule results would be:
n = days, d = id
n x d
1 2
0 2
1 3
0 3
m = 2 means that is a maximum of 2 shifts
d = 2 means that there can only be 2 workers per day


To count the m's you go down the column and count the same id number
To count the amount of d's, just go count from left to right on the row which is 2


*/
    //cout << "SCHEDULE" << endl;
    //cout << dailyNeed << " " << maxShifts << endl;
/*
    cout << "AvailabilityMatrix" << endl;
    for(size_t i = 0; i < avail.size(); ++i){
        for(size_t j = 0; j < avail.size(); ++j){
            cout << avail[i][j] << " ";
        }
        cout << endl;
    }
*/
   cout << "SCHEDULE" << endl;
   vector<size_t> shifts_each_worker; //This will hold the amount of shifts left for each worker
   //Might need to use maps for shifts_each_worker
   //map<Worker_T, size_t> shifts_each_worker;
   for(size_t i = 0; i < avail.size(); ++i){  //The amount of rows for sched and AvailabilityMatrix is the same
      vector<Worker_T> temp;
      sched.push_back(temp);
   }
   for(size_t i = 0; i < avail[0].size(); ++i){ //The amount of workers/columns for sched
      shifts_each_worker.push_back(maxShifts + 1);  //Put in the amount of shifts for each worker are left
      //cout << "SHIFT FOR EACH WORKER: " << shifts_each_worker[i] << endl;
   }
//LOOK AT THIS: Make a for loop, and have pass vector shifts_each_worker[0], to first column, and then if it doesn't work, backtrack and then pass vector shifts_each_worker[1]
    bool result = Schedule_Recurse_Helper(avail, dailyNeed, maxShifts, sched, 0, 0, 0, shifts_each_worker);
    return result;
}




bool Schedule_Recurse_Helper(
    const AvailabilityMatrix& avail,
    const size_t dailyNeed, //d go on the same row
    const size_t maxShifts, //m go down the column and count the same ID number
    DailySchedule& sched,
    size_t row,
    size_t col,
    size_t dailyNeed_counter,
    vector<size_t>& shifts_each_worker
)
{


//START AT ROW 2 FROM THE PHOTO WHERE IT IS NOT SUPPOSE TO RETURN TRUE WHEN GOING DOWN
    /*
         It is likely easiest to recurse over each place in the schedule (i.e. the 2D sched matrix).
         Each recursive call would be responsible for filling in one of the n*d schedule openings,
         ensuring the constraints of availability and the maximum number of shifts allowed for each
         worker is met. If you have already done a lab regarding backtracking search, it would likely
         be beneficial to look it over.


        You may have up to three loops in your code: two for setup and one in your recursive search.
    */
    cout << "daily NEED/idCOUTNER: " << dailyNeed << endl;
    if(row == avail.size()){


        //Make another if condition that detects the size of the avail with the current row we are on and see if the size is equal to the dailyNeed.
        //If they are not equal, that means that we make a temp variable that will store the index that is on the avail[row] current row and then pop back the avail[row] vector
        //Then we recurse with the temp variable plus one for the col parameter in order to ignore the last thing that worked
        return true;
    }else if(dailyNeed == dailyNeed_counter){   //If these two equal, that means sched[current row] is done and we go to next row
        if(Schedule_Recurse_Helper(avail, dailyNeed, maxShifts, sched, row + 1, 0, 0, shifts_each_worker)){
            return true;
        }
        return false;
    }else if(col == 0 && avail[row][col] == 1 && avail_Recurse_Helper_Horizontal(avail, dailyNeed, maxShifts, sched, row, col + 1, dailyNeed, avail[row][col], avail[row][col], shifts_each_worker)){


              cout << "IT IS VERY TRUE HORIZONTAL RIGHT" << endl;
              cout << "SHIFT: " << shifts_each_worker[col] << endl;
             
              if(shifts_each_worker[col] == 1){ //If it is equal to one, that means that the two indexes above the current index is also the same id number which is 3 of them in total being greater than the maxshift if the maxshift is two
                    return false;
              }
              --shifts_each_worker[col];
              sched[row].push_back(col);


               cout << endl;
              cout << endl;
              for(size_t i = 0; i < shifts_each_worker.size(); ++i){
                  cout << "shifts_each_worker: " << shifts_each_worker[i] << endl;
              }
              cout << endl;
              cout << endl;
              if(Schedule_Recurse_Helper(avail, dailyNeed, maxShifts, sched, row + 1, 0, 0, shifts_each_worker)){
                  return true;
              }
              return false;
    }else if(col == 0 && avail[row][col] == 0 && avail_Recurse_Helper_Horizontal_Zero(avail, dailyNeed, maxShifts, sched, row, col + 1, dailyNeed + 1, avail[row][col], avail[row][col], shifts_each_worker)){
              cout << "MAYBE FIX SHIFT HERE" << endl;

              if(col + 1 == avail[row].size()){ //If the next column is just an empty column, that means that 0 is by itself on the row which should return false
                    return false;
              }
               cout << endl;
              cout << endl;
              for(size_t i = 0; i < shifts_each_worker.size(); ++i){
                  cout << "shifts_each_worker: " << shifts_each_worker[i] << endl;
              }
              cout << endl;
              cout << endl;


              if(Schedule_Recurse_Helper(avail, dailyNeed, maxShifts, sched, row + 1, 0, 0, shifts_each_worker)){
                  return true;
              }
/*
              for(size_t i = 0; i < sched.size(); ++i){
                for(size_t j = 0; j < sched[i].size(); ++j){
                    cout << sched[i][j] << " ";
                }
                cout << endl;
              }
*/
/*
              cout << "IT IS VERY TRUE HORIZONTAL RIGHT" << endl;
              cout << "SHIFT: " << shifts_each_worker[col] << endl;
              if(shifts_each_worker[col] == 1){ //If it is equal to one, that means that the two indexes above the current index is also the same id number which is 3 of them in total being greater than the maxshift if the maxshift is two
                    return false;
              }
              --shifts_each_worker[col];
              sched[row].push_back(col);
              if(Schedule_Recurse_Helper(avail, dailyNeed, maxShifts, sched, row + 1, 0, 0, shifts_each_worker)){
                  return true;
              }
              return false;
*/
            cout << "SOMETHING AFTER" << endl;
    }else{
          cout << "Schedule_Recurse_Helper************************************* ROW ROW: " << row << endl;
          cout << "Daily NEED COUNTER: " << dailyNeed_counter << endl;
          cout << "ROW " << row << " COL " << col << " FOR THIS SCHEDULE RECURSE HELPER" << endl;

          cout << endl;
          cout << endl;
          for(size_t i = 0; i < shifts_each_worker.size(); ++i){
              cout << "shifts_each_worker: " << shifts_each_worker[i] << endl;
          }
          cout << endl;
          cout << endl;
         //else{


/*
                if(dailyNeed == dailyNeed_counter){ //If these two equal, that means sched[current row] is done and we go to next row
                    if(Schedule_Recurse_Helper(avail, dailyNeed, maxShifts, sched, row + 1, 0, 0, shifts_each_worker)){
                        return true;
                    }
                    return false;
                }
*/
                //vector<size_t>::iterator it;
                //it = std::find(shifts_each_worker.begin(), shifts_each_worker.end(), 1);
                //cout << "it is found: " << *it << " at index: " << it - shifts_each_worker.begin() << endl;
                //if(Schedule_Recurse_Helper(avail, dailyNeed, maxShifts, sched, )){


                //}


                //if(dailyNeed_counter == dailyNeed - 1 && col == avail[row].size() - 1 && avail[row][col] == 0){ //If this is the last thing you need to add to sched[current row] and all that is left is a zero on the last index of the current row, then we need to find 1 from the beginning of the current row
                    //cout << "WE NEED TO DO THE FIND THING: " << row << " " << col << endl;
                //}
                for(size_t i = col; i < avail[row].size(); ++i){ //Go from left to right of same row
                    if(avail[row][i] == 0){ //If the availabilityMatrix index value is 0
                         if(dailyNeed_counter == dailyNeed - 1 && i == avail[row].size() - 1){ //If this is the last thing you need to add to sched[current row] and all that is left is a zero on the last index of the current row, then we need to find 1 from the beginning of the current row
                                cout << "WE NEED TO DO THE FIND THING: " << row << " " << i << endl;
                                vector<bool>::iterator it;
                                vector<bool> temp = avail[row];
                                it = std::find(temp.begin(), temp.end(), true);
                                cout << "*it value " << *it << " is found at the index " << it - temp.begin() << endl;
                                sched[row].push_back(it - temp.begin());
                                --shifts_each_worker[it - temp.begin()];
                                for(size_t z = 0; z < sched[row].size(); ++z){
                                    cout << "SCHEDULE UPDATED: " << sched[row][z] << endl;
                                }
                                cout << endl;
                                cout << endl;
                                for(size_t o = 0; o < shifts_each_worker.size(); ++o){
                                    cout << "shifts_each_worker: " << shifts_each_worker[o] << endl;
                                }
                                cout << endl;
                                cout << endl;
                                if(Schedule_Recurse_Helper(avail, dailyNeed, maxShifts, sched, row, i + 1, dailyNeed_counter + 1, shifts_each_worker)){    //Make the col passed be i + 1 in order to ignore the current sched value push backed
                                    //--shifts_each_worker[i];
                                    //vector<bool>::iterator it;
                                    //vector<bool> temp = avail[row];
                                    //it = std::find(temp.begin(), temp.end(), true);
                                    //cout << "*it value " << *it << " is found at the index " << it - temp.begin() << endl;


                                    return true;    //Backtracking makes it that you add something before calling recursive function if condition and then if it fails, then you correct it by doing the opposite and return false after all of the loop is done
                                }
                         }
                    }
                    if(avail[row][i] == 1){ //If the availabilityMatrix matrix index value is 1
                        //Schedule_Recurse_Helper(avail, dailyNeed, maxShifts, sched, row + 1, )
                        cout << "row: " << row << " i: " << i << endl;
                        //if(avail_Recurse_Helper(avail, dailyNeed, maxShifts, sched, row + 1, i, shifts_each_worker[i] - 1, avail[row][i])){
                          //if(avail_Recurse_Helper(avail, dailyNeed, maxShifts, sched, row + 1, i, maxShifts, avail[row][i])){
                          if(avail_Recurse_Helper(avail, dailyNeed, maxShifts, sched, row + 1, i, shifts_each_worker[i], avail[row][i])){
                            //Go to next sched recurse helper maybe
                            cout << "AVAIL IS TRUE" << endl;
                            sched[row].push_back(i);
                            --shifts_each_worker[i];
                            cout << endl;
                            cout << endl;
                            for(size_t u = 0; u < sched[row].size(); ++u){
                                cout << "SCHED STUFF: " << sched[row][u] << endl;
                            }
                            cout << endl;
                            cout << endl;

                            cout << "ROW AND COL CHECKER: " << row << " " << i << endl;
                            cout << "ROW AND COL + 1 CHECKER" << row << " " << i + 1 << endl;


                             cout << endl;
                              cout << endl;
                              for(size_t p = 0; p < shifts_each_worker.size(); ++p){
                                  cout << "shifts_each_worker: " << shifts_each_worker[p] << endl;
                              }
                              cout << endl;
                              cout << endl;
                            if(i + 1 == avail[row].size() && dailyNeed_counter < dailyNeed - 1){ //If these two equal, that means that there is still one more we can add to sched[current row] so we will start from the beginning of the same row again and add the first 1 boolean value
                                    vector<bool>::iterator it;
                                    vector<bool> temp = avail[row];
                                    it = std::find(temp.begin(), temp.end(), true);
                                    cout << "*it value " << *it << " is found at the index " << it - temp.begin() << endl;
                                    sched[row].push_back(it - temp.begin());
                                    --shifts_each_worker[it - temp.begin()];
                                    for(size_t z = 0; z < sched[row].size(); ++z){
                                        cout << "SCHEDULE UPDATED: " << sched[row][z] << endl;
                                    }


                                     cout << endl;
                                      cout << endl;
                                      for(size_t o = 0; o < shifts_each_worker.size(); ++o){
                                          cout << "shifts_each_worker: " << shifts_each_worker[o] << endl;
                                      }
                                      cout << endl;
                                      cout << endl;
                                    if(Schedule_Recurse_Helper(avail, dailyNeed, maxShifts, sched, row, i + 1, dailyNeed_counter + 2, shifts_each_worker)){    //Make the col passed be i + 1 in order to ignore the current sched value push backed
                                        //--shifts_each_worker[i];
                                        //vector<bool>::iterator it;
                                        //vector<bool> temp = avail[row];
                                        //it = std::find(temp.begin(), temp.end(), true);
                                        //cout << "*it value " << *it << " is found at the index " << it - temp.begin() << endl;


                                        return true;    //Backtracking makes it that you add something before calling recursive function if condition and then if it fails, then you correct it by doing the opposite and return false after all of the loop is done
                                    }
                            }else{

                                    cout << "OVER HERE YO" << endl;
                                    if(Schedule_Recurse_Helper(avail, dailyNeed, maxShifts, sched, row, i + 1, dailyNeed_counter + 1, shifts_each_worker)){    //Make the col passed be i + 1 in order to ignore the current sched value push backed
                                        //--shifts_each_worker[i];
                                        return true;
                                    }
                            } //<--------------------------
                           


                            sched[row].pop_back();
                            ++shifts_each_worker[i];
                            //return Schedule_Recurse_Helper(); //Make the col passed be i + 1 in order to ignore the current sched value push backed
                        }
                        cout << "------------------------>" << endl;
                        if(i == avail[row].size() - 1 && avail[row][i] == 1 && dailyNeed_counter < dailyNeed){
                            cout << "GET OVER HERE YOU THING" << endl;
                            for(size_t l = 0; l < sched[row].size(); ++l){
                                //cout << sched[row][l] << " ";
                                cout << sched[row][l] << endl;
                               
                            }
                            cout << "SCHED ROW 0 is: " << sched[row][0] << endl;
                            cout << endl;
                            vector<bool>::iterator it;
                            vector<bool> temp = avail[row];

                            //Loop it for each sched[row][p]
                            it = std::find(temp.begin() + sched[row][0] + 1, temp.end(), 1);
                            sched[row].push_back(it - temp.begin());
                            --shifts_each_worker[it-temp.begin()];

                            //cout << "*it has a value of " << *it << " at the index of " << it - temp.begin() << endl;
/*
                            vector<Worker_T> sched_row_temp = sched[row];
                            size_t daily_Need_temp = 0; //This will count the amount of times we find the ones
                            for(size_t h = 0; h < sched_row_temp.size(); ++h){  //This will loop and find the remaining ones
                                it = std::find(temp.begin() + sched[row][h] + 1, temp.end(), 1);
                                cout << "*it has a value of " << *it << " at the index of " << it - temp.begin() << endl;
                                sched[row].push_back(it - temp.begin());
                                --shifts_each_worker[it - temp.begin()];
                                ++daily_Need_temp;
                            }
                           
*/
                            cout << endl;
                            cout << endl;

                            for(size_t o = 0; o < shifts_each_worker.size(); ++o){
                                cout << "shifts_each_worker: " << shifts_each_worker[o] << endl;
                            }
                            cout << endl;
                            cout << endl;

                            if(Schedule_Recurse_Helper(avail, dailyNeed, maxShifts, sched, row, i + 1, dailyNeed_counter + 2, shifts_each_worker)){    //Make the col passed be i + 1 in order to ignore the current sched value push backed
                                        //--shifts_each_worker[i];
                                        //vector<bool>::iterator it;
                                        //vector<bool> temp = avail[row];
                                        //it = std::find(temp.begin(), temp.end(), true);
                                        //cout << "*it value " << *it << " is found at the index " << it - temp.begin() << endl;


                                        return true;    //Backtracking makes it that you add something before calling recursive function if condition and then if it fails, then you correct it by doing the opposite and return false after all of the loop is done
                            }
                        }
                    }
                }
                return false;
                //return true;
                //cout << ":))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))" << endl;
                //Schedule_Recurse_Helper(avail, dailyNeed, maxShifts, sched, row + 1, 0, shifts_each_worker);
          //}
    }




       
   




    //return true;


}


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
    vector<size_t>& shifts_each_worker
)
{
/*
    This function will count the amount of 1's in the availabilityMatrix.
    The amount the amount of 1's is equal to the dailyNeed, then return true
*/


    if(col == avail[row].size()){
         if((id_counter == 0|| (value == 0 && id_counter == 1))){  //If the value = 0, that means that the base value is 0 and id_counter 1 means that the 0 is the only thing on the row which should return false and not push back anything at all
            cout << "IT IS FALSE YO HORIZONTAL RIGHT" << endl;
            //if(real_value == 0 && id_counter == 1){
                //return true;
            //}
            return false;
        }else{
            cout << "IT IS TRUE YO HORITZONTAL RIGHT" << endl;
            return true;
        }
    }else{
        cout << "id COUNTER HORIZONTAL: " << id_counter << endl;
        cout << "value HORIZONTAL: " << avail[row][col] << endl;
        //cout << "REAL VALUE: " << value << endl;
       
        cout << row << " GOIND RIGHT " << col << endl;
        if(id_counter == 0){ //If the counter equals 0, that means there is too many shifts and this worker should not be used //THIS IS THE PROBLEM
            //cout << "ID COUNTER IS OVER MAXSHIFTS" << endl;
            cout << "IT IS FALSE YO HORIZONTAL RIGHT 2" << endl;
            return false;
        }
       
        if(id_counter == 1 && avail[row][col] == 0){
            //cout << "IT IS TRUE YO HORIZONTAL RIGHT 2" << endl;
            //return true;
        }
        //cout << row << " GOIND DOWN " << col << endl;
        cout << "OOOOOOOOOOOOOOOOOOOOOOOOOO HORIZONTAL RIGHT" << endl;
        cout << "row " << row << " col " << col << " WITH THE VALUE OF: " << avail[row][col] << endl;
        if(1 != avail[row][col]){ //If the value does not equal the current value in the recursion, that means that we don't add it to the id_counter
            if(avail_Recurse_Helper_Horizontal(avail, dailyNeed, maxShifts, sched, row, col + 1, id_counter, value, avail[row][col], shifts_each_worker)){
/*
                if(avail[row][col] == 1){ //If it is 1, then push back
                    sched[row].push_back(1);
                }
*/
               
                return true;
            }
           
            cout << "SHIFT AFTER DONE VERY CHECK: " << shifts_each_worker[col] << " COL: " << col << endl;
            cout << "avail[row][col]: " << avail[row][col] << endl;
            if(avail[row][col] == 1){   //If


            }
            return false;
           //return
           
        }else{
            //cout << "INCREASE BY 1 ----------->" << endl;
            --shifts_each_worker[col];
            sched[row].push_back(col);
            if(avail_Recurse_Helper_Horizontal(avail, dailyNeed, maxShifts, sched, row, col + 1, id_counter - 1, value, avail[row][col], shifts_each_worker)){
                //if(avail[row][col] == 1){ //If it is 1, then push back


                //sched[row].push_back(col);
                cout << "row " << row << " col " << col << " WILL SUBTRACT 1 NOW" << endl;
                //}
                return true;
            }
           
            ++shifts_each_worker[col];
            cout << "SHIFT AFTER DONE: " << shifts_each_worker[col] << " COL: " << col << endl;
            sched[row].pop_back();
            return false;
            //return avail_Recurse_Helper_Horizontal(avail, dailyNeed, maxShifts, sched, row, col + 1, id_counter - 1, value);
           
        }
    }
}

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
    vector<size_t>& shifts_each_worker
){
/*
    This function will count the amount of 1's in the availabilityMatrix.
    The amount the amount of 1's is equal to the dailyNeed, then return true
*/


    if(col == avail[row].size()){
        cout << "ID COUNTER FINAL ZERO: " << id_counter << endl;
         if((id_counter == 0 /* || (value == 0 && id_counter == 1)*/)){  //If the value = 0, that means that the base value is 0 and id_counter 1 means that the 0 is the only thing on the row which should return false and not push back anything at all
            cout << "IT IS FALSE YO HORIZONTAL RIGHT ZERO" << endl;
            //if(real_value == 0 && id_counter == 1){
                //return true;
            //}
            return false;
        }else{
            cout << "IT IS TRUE YO HORITZONTAL RIGHT ZERO" << endl;
            return true;
        }
    }else{
        cout << "id COUNTER HORIZONTAL ZERO: " << id_counter << endl;
        cout << "value HORIZONTAL ZERO: " << avail[row][col] << endl;
        //cout << "REAL VALUE: " << value << endl;
       
        cout << row << " GOIND RIGHT ZERO " << col << endl;
        if(id_counter == 0){ //If the counter equals 0, that means there is too many shifts and this worker should not be used //THIS IS THE PROBLEM
            //cout << "ID COUNTER IS OVER MAXSHIFTS" << endl;
            cout << "IT IS FALSE YO HORIZONTAL RIGHT ZERO 2" << endl;
            return false;
        }
       
        if(id_counter == 1 && avail[row][col] == 0){
            //cout << "IT IS TRUE YO HORIZONTAL RIGHT ZERO 2" << endl;
            //return true;
        }
        //cout << row << " GOIND DOWN " << col << endl;
        cout << "OOOOOOOOOOOOOOOOOOOOOOOOOO HORIZONTAL RIGHT ZERO" << endl;
        cout << "row " << row << " col " << col << " WITH THE VALUE OF: " << avail[row][col] << endl;
        if(1 != avail[row][col]){ //If the value does not equal the current value in the recursion, that means that we don't add it to the id_counter
            if(avail_Recurse_Helper_Horizontal_Zero(avail, dailyNeed, maxShifts, sched, row, col + 1, id_counter, value, avail[row][col], shifts_each_worker)){
/*
                if(avail[row][col] == 1){ //If it is 1, then push back
                    sched[row].push_back(1);
                }
*/
               
                return true;
            }
           
            cout << "SHIFT AFTER DONE VERY CHECK ZERO: " << shifts_each_worker[col] << " COL: " << col << endl;
            cout << "avail[row][col] ZERO: " << avail[row][col] << endl;
            if(avail[row][col] == 1){   //If


            }
            return false;
           //return
           
        }else{
            cout << "INCREASE BY 1 -----------> row " << row << " col " << col << endl;
            --shifts_each_worker[col];
            sched[row].push_back(col);
            if(avail_Recurse_Helper_Horizontal_Zero(avail, dailyNeed, maxShifts, sched, row, col + 1, id_counter - 1, value, avail[row][col], shifts_each_worker)){
                //if(avail[row][col] == 1){ //If it is 1, then push back


                //sched[row].push_back(col);
                cout << "row " << row << " col " << col << " WILL SUBTRACT 1 NOW" << endl;
                //}
                return true;
            }
           
            ++shifts_each_worker[col];
            cout << "SHIFT AFTER DONE: " << shifts_each_worker[col] << " COL: " << col << endl;
            sched[row].pop_back();
            return false;
            //return avail_Recurse_Helper_Horizontal(avail, dailyNeed, maxShifts, sched, row, col + 1, id_counter - 1, value);
           
        }
    }
}
//This is for vertical
bool avail_Recurse_Helper(
    const AvailabilityMatrix& avail,
    const size_t dailyNeed, //d go on the same row
    const size_t maxShifts, //m go down the column and count the same ID number
    DailySchedule& sched,
    size_t row,
    size_t col,
    size_t id_counter,
    const Worker_T& value
)
{
    //cout << "avail_Recurse_Helper: "  << endl;
    //cout << row << " AVAIL " << col << endl;
    //Now we must recurse down
    if(row == avail.size()){  //If the row reaches to the empty bottom, then return true
        //cout << "IT IS TRUE YO" << endl;
        if(id_counter == 1){  
            cout << "IT IS FALSE YO" << endl;
            return false;
        }else{
            cout << "IT IS TRUE YO" << endl;
            return true;
        }
        //return true;
    }else{
        cout << "id COUNTER: " << id_counter << endl;
        cout << "value: " << avail[row][col] << endl;
        //cout << "REAL VALUE: " << value << endl;
       
        cout << row << " GOIND DOWN " << col << endl;
        if(id_counter == 1){ //If the counter equals 0, that means there is too many shifts and this worker should not be used //THIS IS THE PROBLEM
            //cout << "ID COUNTER IS OVER MAXSHIFTS" << endl;
            cout << "IT IS FALSE YO 2" << endl;
            return false;
        }
       
        //cout << row << " GOIND DOWN " << col << endl;
        cout << "OOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
        if(value != avail[row][col]){ //If the value does not equal the current value in the recursion, that means that we don't add it to the id_counter
            return avail_Recurse_Helper(avail, dailyNeed, maxShifts, sched, row + 1, col, id_counter, value);
        }else{
            //cout << "INCREASE BY 1 ----------->" << endl;
            return avail_Recurse_Helper(avail, dailyNeed, maxShifts, sched, row + 1, col, id_counter - 1, value);
        }
       


    }
}



