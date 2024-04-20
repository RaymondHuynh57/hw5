#ifndef RECCHECK
// For debugging
#include <iostream>
// For std::remove
#include <algorithm>
#include <map>
#include <set>
#endif










#include "wordle.h"
#include "dict-eng.h"
using namespace std;








// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{
    // Add your code here
   
    std::set<std::string> result;
    //std::string test_string;
    size_t in_size = in.size();
    size_t floating_size = floating.size();
    size_t not_dash_in_index = 0;
    //Make a map here that stores a char and bool for later use
    //map<char, bool> float_map;
    set<char> float_set;
    set<char> a_to_z_set;
    //for(size_t i = 0; i < floating.size(); ++i){
        //float_map[floating[i]] = true;
        //float_set.insert(floating[i]);
    //}






    //size_t dash_counter = wordleDashInCounter(in, 0);
    if(in.empty()){
        return result;
    }
//Make a function that will add in floating order. If it returns true, then don't do the second step recursion on line 57










    //for(size_t i = 0; i < in.size(); ++i){
        //if(in[i] == '-'){














        //}
    //}
    //size_t dash_counter = 0;
    //std::string temp = "";
    //wordleDashInCounter(in, 0, dash_counter);














    //if(dash_counter == floating.size()){
        //cout << in << endl;
        //cout << floating << endl;
        //cout << "DASH COUNTER: " << dash_counter << endl;
        //cout << "Floating SIZE: " << floating.size() << endl;












        //size_t no_dash_counter = 0;
        //wordleNoDashInCounter(in, 0, no_dash_counter);
        //wordle_Floating_Recurse_Helper(result, in, floating, dict, float_map, "", in_size, 0, 0, 0, no_dash_counter);












    std::set<size_t> index_next_set;










    //}else{
        //char temp;
        wordle_Helper_Recurse(result, in, floating, dict, float_set, a_to_z_set, index_next_set, "", in_size, 0, 0, 0, "");    //<------ FLOATING[0] at the end parameter DIS IS THE PROBLEM
    //}
    //wordle_Helper_Recurse(result, in, floating, dict, float_map, "", in_size, 0, 0, 0);
    return result;
}










void wordleDashInCounter(const std::string& in, size_t in_index, size_t& dash_counter){
    if(in_index == in.size()){








    }else{
        if(in[in_index] == '-'){
            dash_counter += 1;
        }








        wordleDashInCounter(in, in_index + 1, dash_counter);
    }
}






void wordleNoDashInCounter(const std::string& in, size_t in_index, size_t& dash_no_counter){
    if(in_index == in.size()){










    }else{
        if(in[in_index] != '-'){
            dash_no_counter += 1;
        }
















        wordleNoDashInCounter(in, in_index + 1, dash_no_counter);
    }
}
void wordle_Floating_Recurse_Helper(
    std::set<std::string>& result,
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict,
    std::set<char>& float_set,
    std::string word,
    size_t in_size,
    size_t in_index,
    size_t floating_index,
    size_t not_dash_in_index,
    size_t& no_dash_amount)
{
    //if(floating_index == floating.size()){
    if(in_size == 0){
        if(dict.find(word) != dict.end() && wordle_Helper_Word_Match_Floating(floating, word)){
            //cout << "INSERTTED WORD: " << word << endl;
            result.insert(word);
            //return true;
        }
        //return false;
    }else{
        //cout << "FLOAT RECURSE HELPER" << endl;
        if(in[in_index] != '-'){  //If the in[in_index] does not equal '-', that means that there is a letter that must be placed exactly at that particular index
                    //wordle_Floating_Recurse_Helper(result, in, floating, dict, float_set, word + in[in_index], in_size - 1, in_index + 1, floating_index, not_dash_in_index + 1, no_dash_amount);
                    wordle_Floating_Recurse_Helper(result, in, floating, dict, float_set, word + in[in_index], in_size - 1, in_index + 1, floating_index, not_dash_in_index, no_dash_amount);
        }else{
                //Loops can be whatever number because the in_size will make it only 10 character strings
                if(floating_index < floating.size()){
                    size_t input_size_left = in.size() - floating.size();
                    for(size_t i = 0; i < floating.size(); ++i){
                        wordle_Floating_Recurse_Helper(result, in, floating, dict, float_set, word + floating[i], in_size - 1, in_index + 1, floating_index + 1, not_dash_in_index, no_dash_amount);
                    }
                }
                        //-------------------------------------> //CORRECT ABOVE
                    //Don't have an else statement so that the first recursion case can start at one "a" to "z" as one example case








                //if(floating.size() < in.size() - not_dash_in_index){
      /*
                if(in.size() - no_dash_amount > floating.size()){ //If the amount of dashes is greater than the float size, that means that there are extra spaces to have a to z
                  //cout << "FLOATING.SIZE(): " << floating.size() << endl;
                  //cout << "Subtract: " << in.size() - not_dash_in_index << endl;
                    for(char c = 'a'; c <= 'z'; ++c){
                        wordle_Floating_Recurse_Helper(result, in, floating, dict, float_map, word + c, in_size - 1, in_index + 1, floating_index, not_dash_in_index, no_dash_amount);
                    }
                }
      */      
               
/*
                //-------------------------------------> //CORRECT ABOVE
                //Don't have an else statement so that the first recursion case can start at one "a" to "z" as one example case
               
                for(char c = 'a'; c <= 'z'; ++c){
                    wordle_Floating_Recurse_Helper(result, in, floating, dict, float_map, word + c, in_size - 1, in_index + 1, floating_index, not_dash_in_index);
                }
*/          
               
               
               
                //else{  //If floating_index >= floating.size
















                //}        
//------------------------------------>
                //input_size_left + floating.size() = input.size(), which will make in_size at the end
                //if(input_size_left > 0){    //If it is greater than zero, that means that there are input_size_left amount of spaces left to determine with letters a to z rather than floating letters
                    //for(size_t i = 0; i < input_size_left; ++i){
                        //for(char c = 'a'; c <= 'z'; ++c){
                           // wordle_Floating_Recurse_Helper(result, in, floating, )
                        //}
                       
                    //}
                //}
        }
       
       
    }
}








// Define any helper functions here












bool wordle_Helper_Word_Match_Floating(const std::string& floating, std::string word){
    map<char, size_t> result_map;
    size_t floating_counter = 0;  //Will be used to count how many times the strings in floating appear in the word
    for(size_t i = 0; i < floating.size(); ++i){
       
        size_t z = 0;
        if(result_map.find(floating[i]) != result_map.end()){ //If there is a value that is the same as the floating index value we have right now, that means that this case is the second, third, fourth.... of the same letter and should start one more index than the last one ended
                z = result_map[floating[i]] + 1;
        }
        for(size_t j = z; j < word.size(); ++j){
            if(floating[i] == word[j]){
                ++floating_counter;
                result_map[floating[i]] = j;  //Store the j index where you stop on the word, so if there is another same letter in floating, then the iteration for the another same letter in floating will start at where the last same old letter ended off
                break;  //Break once we find the matched value so it loops to the next index value of floating
            }
        }
    }
































    if(floating_counter == floating.size()){  //If floating_counter is equal to floating.size() that means that the word does contain all the letters from floating
        return true;
    }
    return false;
}
















































/*
Make a function that will run when during mid step recursion.
This function will loop across the partial completed word and
see if ALL the floating index values can even fit in the word.
If it can't return false. This function will run if in.size() - in_index
< floating.size(). For instance, if input (or in.size())  is 5 and in_index
is 3, along with floating.size() being 2, 2 < 2 which means this function
will not run yet since there is a chance that the two floating index
values will work. On the other hand, if floating.size() is 3,
then it will be 2 < 3 which means that we need to make sure that
1 of the 3 floating index value is already in the partial word
string. If it isn't, that means there is no way for the recursion,
leading this function return false. For example, if the floating
is "ape", and the partial word string is "inferna--", there is
still a chance for the other two letters in the partial word
string to be the p and e from floating. However, if the partial
word string is "inferno--", there is no way for the floating word
to fit ape since only 2 spaces are left while floating.size() is 3.
Therefore, it should return false
The if condition at the end of this function would be if
floating_counter If all of the floating index value except for one
being the blank space is in the word, keep recursing, or else return
and go down a different recursion
*/
bool wordle_Helper_Mid_Recursion_Check(
    const std::string& in,
    const std::string& floating,
    std::string partial_word,
    size_t in_index)
{
/*
  size_t float_counter = 0;
    for(size_t i = 0; i < floating.size(); ++i){
        for(size_t j = 0; j < partial_word.size(); ++j){
            if(floating[i] == partial_word[j]){
                ++float_counter;
































            }
        }
    }
*/
















//---------------------------------------->
    map<char, size_t> result_map;
    size_t floating_counter = 0;  //Will be used to count how many times the strings in floating appear in the word
    for(size_t i = 0; i < floating.size(); ++i){
       
        size_t z = 0;
        if(result_map.find(floating[i]) != result_map.end()){ //If there is a value that is the same as the floating index value we have right now, that means that this case is the second, third, fourth.... of the same letter and should start one more index than the last one ended
                z = result_map[floating[i]] + 1;
        }
        for(size_t j = z; j < partial_word.size(); ++j){  //Partial word is "", not "i" yet
            if(floating[i] == partial_word[j]){
                ++floating_counter;
                result_map[floating[i]] = j;  //Store the j index where you stop on the word, so if there is another same letter in floating, then the iteration for the another same letter in floating will start at where the last same old letter ended off
                break;  //Break once we find the matched value so it loops to the next index value of floating
            }
        }
    }
//--------------------------------------->
    size_t difference = floating.size() - (in.size() - in_index);  //if 2 < 3, then 3 - 2 = 1. if 1 < 3, then 3 - 1 = 2
  if(partial_word == "patted"){
      //cout << "DIFFERENCE: " << difference << endl;
      //cout << "FLOATING COUNTER: " << floating_counter << endl;
      //cout << "partial Word: " << partial_word << endl;
  }
   
    //if(floating_counter == difference){
    if(floating_counter >= difference){
        return true;
    }
    return false;
/*
    if(floating_counter == floating.size()){  //If floating_counter is equal to floating.size() that means that the word does contain all the letters from floating
        return true;
    }
    return false;
*/  
}
































// Define any helper functions here
//MIGHT HAVE TO CHANGE THE RETURN TYPE TO BOOL. THIS IS BECAUSE ONCE THE FUNCTION FINDS THE CORRECT LETTER AT THE PLACE, return true, and then go onto the next index
bool wordle_Helper_Recurse(
    std::set<std::string>& result,
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict,
    std::set<char>& float_set,
    std::set<char>& a_to_z_set,
    std::set<size_t>& index_next_set,
    std::string word,
    size_t in_size,
    size_t in_index,
    size_t floating_index,
    size_t not_dash_in_index,
    string character
    )
{
  //cout << "RECURSE BEGINNING: " << in_size << endl;
 //   std::set<std::string> actual = wordle("-----sion", "rcr", dict);
    //cout << "WORDLE_HELPER_RECURSE: " << in_size << endl;
     //cout << "IN_INDEX: " << in_index << endl;
     //-------------------------------------------------------------------------->
    if(in_size == 0){   //Length of the string that the user wants
    //if(in_size == 6){
        //cout << "END" << endl;
      if(wordle_Helper_Word_Match_Floating(floating, word)){  //If the word passes the float and normal test
        //cout << "FLOAT MATCH IN THIS ONE" << endl;
        //a_to_z_set.erase('a');//<----------------------
        //index_next_set.erase(value);
        //float_set.insert(value);
        //if(word == "nida"){
           //cout << "TRUE" << endl;
        //}
      }else{
        //float_set.erase(value);
        //a_to_z_set.insert('a');
          //cout << "THESE WORDS ARE BAD " << word << endl;
          //cout << "THIS IS FALSE: " << word << endl;
          //a_to_z_set.insert('b');//<----------    This will limiting the a to z loop
          return false;//<----------------
      }








        //cout << "WORD: " << word << endl;//<-------------
        //------------------------------------------------->
       
/*
       if(word == "niad" || word == "niad"){
           cout << "THIS IS " << word << endl;
            std::set<char>::iterator it;
            std::set<size_t>::iterator it_two;
            cout << endl;
            cout << "FLOAT_SET" << endl;
            for(it = float_set.begin(); it != float_set.end(); ++it){
                cout << *it << " ";
            }
            cout << endl;
            cout << "A TO Z SET" << endl;
            for(it = a_to_z_set.begin(); it != a_to_z_set.end(); ++it){
                cout << *it << " ";
            }
            cout << endl;
            cout << "INDEX_NEXT_SET" << endl;








            for(it_two = index_next_set.begin(); it_two != index_next_set.end(); ++it_two){
                cout << *it_two << " ";
            }
            cout << endl;
            cout << endl;
       }
  */
  /*    
        cout << "THIS IS " << word << endl;
            std::set<char>::iterator it;
            std::set<size_t>::iterator it_two;
            cout << endl;
            cout << "FLOAT_SET" << endl;
            for(it = float_set.begin(); it != float_set.end(); ++it){
                cout << *it << " ";
            }
            cout << endl;
            cout << "A TO Z SET" << endl;
            for(it = a_to_z_set.begin(); it != a_to_z_set.end(); ++it){
                cout << *it << " ";
            }
            cout << endl;
            cout << "INDEX_NEXT_SET" << endl;








            for(it_two = index_next_set.begin(); it_two != index_next_set.end(); ++it_two){
                cout << *it_two << " ";
            }
            cout << endl;
*/
        
        
        //cout << "WORD: " << word << " " << not_dash_in_index << "----------------------------------------------------------------------------------->" << endl;//<-------------
        //------------------------------------------------->
       
       
        //------------------------------>
        size_t found = floating.find(character);    //If the previous character added to the word can be found in floating string, then erase the a to z set of 'a'
        if(floating != ""){
            if(found != string::npos){  // if we find it
                //cout << character << " is found in floating string BASE CASE" << endl;
               
                //a_to_z_set.insert('a');
                //a_to_z_set.erase('a');  //<----------
            }else{  //If we can't find the character
                //a_to_z_set.erase('a');
                //cout << character << " is not found in floating string BASE CASE" << endl;
               
               
               
                //a_to_z_set.insert('a'); //<--------------
                //a_to_z_set.erase('a');
            }
        }
       
        //-----------------------------




/*
        if(word == "niad" /*|| word == "niad"){
           cout << "THIS IS AGAIN: " << word << endl;
            std::set<char>::iterator it;
            std::set<size_t>::iterator it_two;
            cout << endl;
            cout << "FLOAT_SET" << endl;
            for(it = float_set.begin(); it != float_set.end(); ++it){
                cout << *it << " ";
            }
            cout << endl;
            cout << "A TO Z SET" << endl;
            for(it = a_to_z_set.begin(); it != a_to_z_set.end(); ++it){
                cout << *it << " ";
            }
            cout << endl;
            cout << "INDEX_NEXT_SET" << endl;








            for(it_two = index_next_set.begin(); it_two != index_next_set.end(); ++it_two){
                cout << *it_two << " ";
            }
            cout << endl;
            cout << endl;
       }
*/
        if(dict.find(word) != dict.end()/* && wordle_Helper_Word_Match_Floating(floating, word)*/){
          //if((dict.find(word) != dict.end() && wordle_Helper_Word_Match_Floating(floating, word)) || floating_index == floating.size() - 1){
            //cout << "INSERTTED WORD: " << word << endl;
            result.insert(word);
            return true;
        }
        return false;
    }else{  //The coding does after this line does not have anything to do with floating which is NOT GOOD
    //Might to have to use a map that has and size_t and a char. Size_t will hold the index and char would be the letter


    //Insert letters that was first used. If it is detected to be a same letter already insertted, that means that we should loop to a different letter instead
    //Erase letters after the recursion is over MAYBE
    //FINAL: THE IF ELSE STATEMENT WITH THE IF STATEMENT RECURSING THE IN ORDER FLOATING AND INSIDE THAT IF, SOMEHOW INCLUDE THE LETTERS THAT ARE ALREADY THERE AS SEEN FROM LINE 200
    char value;
            if(in[in_index] != '-'){  //If the in[in_index] does not equal '-', that means that there is a letter that must be placed exactly at that particular index
                string temp = "";
                temp += in[in_index];




 //size_t finding_stuff = floating.find(floating[i], i + 1);


                if(floating.size() == 1 && in.size() == 3 && in_index == 1){
                    size_t find_previous = floating.find(character, 0);
                    //cout << "WHAT IS CHAR: " << character << endl;






                    if(find_previous != std::string::npos){ //If the previous character is in the floating, then erase a to z set to iterate through the a to z
                        float_set.insert(floating[find_previous]);
                        a_to_z_set.erase('a');
                        //cout << "PREV CHAR IS FLOATING" << endl;
                    }else{  //If the previous character is not in the floating, then insert a to z set
                        //cout << "PREV CHAR NOT IN FLOATING" << endl;
                        float_set.erase(floating[0]);
                        //cout << "INSERT A WHICH IS A PROBLEM" << endl;
                        a_to_z_set.insert('a');
                    }
                }
                //a_to_z_set.erase('a');
                //cout << "ERASE A TO Z AND STUFF AT THIS INDEX" << endl;
                //a_to_z_set.insert('a');
               
                //cout << "BEFORE RECURSE" << endl;
                if(wordle_Helper_Recurse(result, in, floating, dict, float_set, a_to_z_set, index_next_set, word + in[in_index], in_size - 1, in_index + 1, floating_index, not_dash_in_index, temp)){
                    //float_set.insert(in[in_index]); //We insert this
                }
                //cout << "- RECURSE AFTER: " << in_size << endl;
            }else{
                //FINAL: THE IF ELSE STATEMENT WITH THE IF STATEMENT RECURSING THE IN ORDER FLOATING AND INSIDE THAT IF, SOMEHOW INCLUDE THE LETTERS THAT ARE ALREADY THERE AS SEEN FROM LINE 200
                //Use a set to store letters that already have been used
//Get the prior character and if you can't find the prior character, recurse
                //cout << "BEGINNING OR SOMETHING" << endl;
                //cout <<
                //Make a map that will store the char and the amount of times the same letter shows up
                //map<char, size_t> map_floating;
                //map<size_t, char> map_floating;






                //Make an if condition of a different floating.size() loop
               
                //Maybe have a bool parameter and if it is true, then go to the first if condition which is the floating size loop for repeated floating values like ll
                //Make a function that has a for loop that will determine the amount of times the floating index value appears in the word given the parameter floating index value. Return size_t
                //If the floating value appears multiple times, then make the bool parameter be true when recurisng which will then run this if condition which is a for loop for floating specifically for identical floating index values
                //if(identical_floating){ //If this is true, that means that we will use this version for the floating loop
     
                //}
                //If identical floating is true, then avoid all of the inserts and erases from float_set
                for(size_t i = 0; i < floating.size(); ++i){
                  //Use set here
                  //cout << "INSIDE" << endl;
                     //If we find the letter being iterated, then don't do this value and loop to another value that is not in the float set
                    //cout << word << endl;//<------------------------------DEBUGGING STUFF
                    //++map_floating[floating[i]];
                    //cout << "MAP FLOATING: " << map_floating['l'] << endl;








                    //if(in_index == 0){
          /*
                        if(map_floating[floating[i]] > 1){  //If it is greater than 1 or it is 2, that means that there are repeated floating letters
                                cout << "FLOATING[i]: " << floating[i] << endl;
                                cout << "FLOATING INDEX: " << floating_index << endl;
                                if(floating_index == 1){
                                    cout << "INSERT" << endl;
                                    float_set.insert(floating[i]);
                                }else{
                                    cout << "ERASE" << endl;
                                    float_set.erase(floating[i]);
                                }
                               
             
                             
                        }
            */
                    //}


                   
                  //Have a set of size_t which are the indexes of the next identical floating index value
                //if(index_next_set.find(i) != index_next_set.end()){// If we do find the index being iterated, then do this












                //}
                     //std::set<size_t>::iterator it;
                        //for(it = index_next_set.begin(); it != index_next_set.end(); ++it){
                          //cout << *it << " ";
                          //cout << "*it: " << *it << endl;
                        //}
                        //cout << endl;
                    //if(float_set.find(floating[i]) == float_set.end()){  //If we don't find the letter being iterated, then do this value since it is brand new
                   
                   //cout << "ARE WE OUTSIDE" << endl;
                    if((float_set.find(floating[i]) == float_set.end())||(index_next_set.find(i) != index_next_set.end())){  //Combines both if conditions
                        //cout << "ARE WE INSIDE" << endl;
                        float_set.insert(floating[i]);  //Inserts r which is the problem. Index next set might be another problem. i==2==index_next_set Line 1552. Might need a loop to count how many r's are in the word and floating and if the amount of r's in the word is greater than the floating, then break out of this loop and erase a from the a_to_z_set
                   
                        if(word.size() == floating.size()){ //If the added word is the index of 2 but adding it to work will be the index of 3 of word, then erase a_to_z_set and break out of this loop
                            //cout << "THE WORD " << word << " IS GOING TO BE LARGER THAN FLOAT AFTER THIS" << endl;
















                        }
                     //The 2 in the index next set is the problem  
/*      
                        size_t r_temp = floating_index_counter(floating, floating[i]);
                        size_t r_temp_word = floating_index_counter(word, floating[i]);
































                        if(r_temp_word > r_temp){ //If the amount of r's in the word are greater
                            a_to_z_set.erase('a');
                            cout << "IT IS GREATER THAN R" << endl;
                            cout << "WORD is: " << r_temp_word << endl;
                            cout << "floating is: " << r_temp << endl;
                            break;
                        }
*/
                        //Might have to use string find
                        //a_to_z_set.erase('a');
                        //cout << "BEFORE INSERT: " << word << endl;
                        //cout << "WORD TEMP: " << word << endl;
                        size_t finding_stuff = floating.find(floating[i], i + 1);
                        //cout << "floating: " << floating << endl;
                        //cout << "floating[i]: " << floating[i] << endl;
                        //cout << "NEXT INDEX: " << finding_stuff << endl;
                        //if(word == "rrl"){
                            //cout << word << endl;
                        //}
                       
                        if(finding_stuff != std::string::npos){ //If we find it
                            //cout << "FOUND IT" << endl;
                            index_next_set.insert(finding_stuff);//<-----------------
                            //The insert 2 happens HERE ABOVE
                            //std::set<size_t>::iterator it;
                            //cout << "INDEX NEXT SET" << endl;
                           
                        }
                        string temp = "";
                        temp += floating[i];
                        value = floating[i];
                        //cout << "RECURSING ONE************************" << endl;
                        if(index_next_set.find(i) != index_next_set.end()){ //If we can find this, then erase
                            index_next_set.erase(i);
                        }
                        //index_next_set.erase()
                        //cout << "FIRST RECURSE: " << in_size << " " << floating[i] << endl;
                        a_to_z_set.erase('b');
                        if(wordle_Helper_Recurse(result, in, floating, dict, float_set, a_to_z_set, index_next_set, word + floating[i], in_size - 1, in_index + 1, floating_index + 1, not_dash_in_index, temp)){
                            //break;
                            //return true;
                            //cout << "CHARACTER: " << character << endl;
                            //float_set.erase(floating[i]);
                           
                        }
                        //cout << "END OF RECURSION 1**********************************" << endl;
                       
                        float_set.erase(floating[i]);//<-----------




                        //float_set.erase(value);
                        //a_to_z_set.insert('a');






                        if(finding_stuff != std::string::npos){
                            //cout << "ERASE INDEX: " << finding_stuff << endl; //I think we have to erase the previous recursion
                            index_next_set.erase(finding_stuff);
                        }
                        //Need to do another erase of the current
                        //for(it = index_next_set.begin(); it != index_next_set.end(); ++it){
                            //index_next_set.erase(*it);
                        //}
                        index_next_set.erase(i);  //<------------
                       
                        index_next_set.erase(i - 1);




                        //Need to erase a_to_z_set.erase()
                        //a_to_z_set.erase('a');
                        //index_next_set.erase(i);
                        //a_to_z_set.erase('a');






                        //cout << "FLOATING INDEX: " << floating_index << endl;
                        //size_t finding_temp =
                       //else{
                            //float_set.erase(floating[i]); //<---------
                        //}
                       
                       
                    }else{
                       
                       
                    }
                 
                }
                //cout << "AFTER" << endl;






                //size_t found = word.find()
//Need some way to not run the later half
/*
                if(in.size() == floating.size()){ //If the input size and the floating size are the same, it should return
                    return true;
                }
*/
               
                size_t dash_counter = 0;
                wordleDashInCounter(in, 0, dash_counter);
                if(dash_counter == floating.size() && dash_counter == 1){  //If the amount of dashes is equal to the size of floating, then we return from here since it is just the floating in the dashes in the end. This only works with one dash examples
                    //cout << "WE DONE NO GOOD" << endl;
                    return true;
                }
                //cout << "IN BETWEEN " << endl;
                if(floating != "" /*&& !isblank(character) */){ //The stuff inside will only run when the floating is not "". NEED TO FIND THE RIGHT IF CONDITIONS FOR THIS PART BC IT RUINS EVERYTHING
                    //size_t found = floating.find(character);    //If the previous character added to the word can be found in floating string, then erase the a to z set of 'a'. The problem here is the two a's
                    //size_t found = in.find()
                    //cout << "IN: " << in << endl;
                    //cout << "CURRENT INDEX VALUE[ " << in_index - 1 << "]: " << in[in_index - 1] << endl;
                   




                    //size_t found = floating.find(word[in_index]);
                    size_t found = floating.find(value);
                    //if(word[in_index]){












                    //}
                    //cout << "CURRENT INDEX VALUE[ " << in_index << "]: " << in[in_index] << endl;
                    //cout << "CURRENT INDEX VALUE for word[ " << in_index << "]: " << value << endl;
                    if(found != string::npos && in[in_index] == '-'){  // if we find that the current index value is floating, that means we erase a to z set to access them to recurdse to the same floating letter being added
                       
                        //a_to_z_set.erase('a');  //<------------
                       
                    }
                    size_t founding = floating.find(word[in_index - 1]);  //Find if the previous index is a floating
                    //cout << "PREVIOUS INDEX VALUE[ " << in_index - 1 << "]: " << in[in_index - 1] << endl;
                    //cout << "CURRENT PREVIOUS INDEX VALUE for word[ " << in_index - 1 << "]: " << word[in_index - 1] << endl;
 
                    if(founding == string::npos && in[in_index - 1] == '-'){ //Make another if condition to detect for the common letter (a to z) matching with a floating letter to the right. The double d is a problem. Need to find a way to avoid this problem
                        //cout << "INSERT? A TO Z" << endl;








                        //if(founding != std::string::npos){  //If we find it
                            //cout << "FLOATING: " << floating << endl;
                            //cout << "THE INDEX OF FOUNDING IS " << founding << " AND THE VALUE IS " << floating[founding] << endl;
                        //}
                       
                        //a_to_z_set.insert('a');//<-------------------
                    }








                    //Need to make another if condition that will deal with double letters such as double d's
                    //cout << "found: " << found << endl;
                    //cout << "founding: " << founding << endl;
 
                    if(found == founding){  //If these two are equal, that means they are the same letters and should be dealth with
                        //cout << "SOME FOUNDING" << endl;
                        //a_to_z_set.insert('a');
                    }








                    //Make another if condition that detects the two latest non floating characters. For instance if 'a' is not a floating character, it will detect 'aa' at the end of the word
                    if((found == std::string::npos && in[in_index] == '-')&& (founding == std::string::npos && in[in_index - 1] == '-')){ //This will most likely erase in order to ensure that a gets to another a
                        //cout << "CURRENT INDEX VALUE[ " << in_index << "]: " << in[in_index] << endl;
                        //cout << "CURRENT INDEX VALUE for word[ " << in_index << "]: " << value << endl;
                       










                        //cout << "PREVIOUS INDEX VALUE[ " << in_index - 1 << "]: " << in[in_index - 1] << endl;
                        //cout << "CURRENT PREVIOUS INDEX VALUE for word[ " << in_index - 1 << "]: " << word[in_index - 1] << endl;
                        //cout << "THIS ERASE" << endl;
                        //a_to_z_set.erase('a');//<----------------
                    }
                    if(in[in_index - 1] != '-'){ //This if condition will detect if the last letter of word is true letter that was originally in input
                        //cout << "TRUE VALUE INDEX: " << in[in_index - 1] << endl;
                        //a_to_z_set.erase('a');
                    }
                    //size_t found_last = floating.find(word.size() - 1);
                    //size_t found_second_last = floating.find(word.size() - 2);
                    //size_t s = 0;
                   //size_t find_the_float_in_word = word.find()
                    //if(/*(found != std::string::npos && in[in_index] == '-') && */(founding != std::string::npos && in[in_index - 1] == '-')){ //Need to detect two floating numbers in the end next to each other in the end and insert in order to prevent further recursions
                    if(wordle_Helper_Word_Match_Floating(floating, word)){
                        //cout << "FLOAT MATCH IN THIS ONE" << endl;
                        a_to_z_set.erase('a');
                        //index_next_set.erase(value);
                        //float_set.insert(value);
                    }else{
                        //float_set.erase(value);
                        //a_to_z_set.insert('a');
                        //cout << "THESE WORDS ARE BAD " << word << endl;
                    }
/*
                        cout << "TWO FLOATING LETTERS" << endl;
                        cout << "WORD WORD: " << word << endl;
                          size_t found_float = 0;
                          size_t found_float_counter = 0;
                          cout << "FLOATING: " << floating << endl;
                          for(size_t count = 0; count < word.size(); ++count){
                              found_float = floating.find(word[count], 0);
                              cout << "FOUND FLOAT: " << word[count] << " " << found_float << endl;
                              if(found_float != std::string::npos){ //If we find it, we increment the counter
                                  ++found_float_counter;
                              }
                          }








                          if(found_float_counter == floating.size()){ //If they are equal, then erase a to z set
                              cout << "IT TRUE AND WE ERASE NOW" << endl;
                              a_to_z_set.erase('a');
                          }
*/
                        //a_to_z_set.insert('a');
                        //a_to_z_set.erase('a');//<----------- IMPORTANT
                    //}








                    //Need some way to detect two floating values of the same letter. For instance, floating could be 'll'
        /*
                    if(found != std::string::npos ){
                         






                    }
        */
                    //
                    //Might need to make a floating loop for the above if condition
                    //cout << "SIZE COMPARISON: " << in.size() << " " << floating.size() << endl;
                    //cout << "INDEX COMPARISON: " << floating_index << in.size() - 2 << endl;
                    if(in.size() >= floating.size() /*&& floating_index == in.size() - 2*/){ //If the input size is greater than or equal to floating size, then that means we will loop to check each floating value in the word
                         
                          /*
                          cout << "THEY ARE GREATER THAN OR EQUAL TO" << endl;
                          size_t founding_temp = 0;
                          size_t founding_counter = 0;
                          for(size_t i = 0; i < floating.size(); ++i){
                             cout << "floating[i]: " << floating[i] << endl;
                             founding_temp = floating.find(word[in_index - i]);
                             if(founding_temp != std::string::npos && in[in_index - i] == '-'){
                                ++founding_counter;
                             }
                          }
                          if(founding_counter == floating.size()){
                              cout << "END RESULT FLOATING" << endl;
                              a_to_z_set.insert('a');
                          }
                          */
                    }
                             
                    //We now need a way for the a to z at the end to recurse to something else as well
        /*
                   
                    else{  //If we can't find the character
                        //a_to_z_set.erase('a');
                        cout << character << " is not found in floating string" << endl;
                        //if(word == "bid"){
                            //cout << character << " is found in floating string" << endl;
                        //}
                        cout << "FLOATING: " << floating << endl;
                        cout << "INSERT? A TO Z" << endl;
                        a_to_z_set.insert('a'); //Think that this is right but the if conditions are just wrong
                        //a_to_z_set.erase('a');
                    }
        */
                    //cout << "------------------------------------->" << endl;




                }
               if(dash_counter == floating.size()){  //If the amount of dashes is equal to the size of floating, then we return from here since it is just the floating in the dashes in the end.
                    //cout << "THEY ARE THE SAME SIZE" << endl;
                    return true;
               }
                //cout << "YO" << endl;
               
                //Make a counter to subtract the set value to make a. WHen it is a, it will break
                int alpha_counter = 0;  //This will count how much needs to be subtracted
               
               
             
                for(char c = 'a'; c <= 'z'; ++c){
                  //cout << "Current c: " << c << endl;
                  //cout << "YO MAMA" << endl;
                  //if(a_to_z_set.find(c) == a_to_z_set.end()){ //If we can't find the letter, then we should recurse this letter




                    ++alpha_counter;
                   
                    if(a_to_z_set.find(c) == a_to_z_set.end()){ //The first iteration will be a which will cancel out          
                       
                       
                        //cout << "IN ALPHABET" << endl;
                        if(float_set.find(c) == float_set.end()){ //If we can't find the letter, that means that we should recurse this letter. For instance, if a letter from the floating is inside the set, and the letter trying to be added in this loop matches the same letter from that floating in the set, then we should avoid it. That's why we should do the opposite and add the ones that we can't find in the set
                           
                            //Need to somehow not include the 'a' for it to repeat again










                            //float_set.insert(c);
                            //float_set.insert(c - alpha_counter + 1);
                            //cout << "c-counter: " << char(c - alpha_counter + 1) << endl;
                            //a_to_z_set.insert('a'); //<-----








                            //a_to_z_set.erase('a');//<-------------
                            //as_to_z_set.insert(char(c - alpha_counter + 1));
                            //float_set.erase('a'); //<----
                            string temp = "";
                            temp += c;
                           
                            a_to_z_set.erase('b');
                            //cout << "BEFORE RECURSE" << endl;
                            if(wordle_Helper_Recurse(result, in, floating, dict, float_set, a_to_z_set, index_next_set, word + c, in_size - 1, in_index + 1, floating_index, not_dash_in_index + 1, temp)){  //Not dash in index is now for alphabets a to z
                              //break;
                                //return true;
                                //a_to_z_set.erase('b');
                            }else{




                               


                            }


/*
                            if(word == "dia"){ //Detect diaso
                                cout << "IT IS DIAN THIS TIME" << endl;
                                cout << "THE WORD IS: " << word << endl;
                            }
*/




                        //cout << "character: " << c << endl;
                        if(in_size == in.size()){ //If these are the same, then erase from a to z set
                            //cout << "ERASE B " << word << endl;
                            //cout << "COMPARE: " << in_size << " " << in.size() << " " << word << endl;
                            //a_to_z_set.erase('b');
                        }
/*
                         if(word == "dia"){ //Detect diaso
                            std::set<char>::iterator it;
                            std::set<size_t>::iterator it_two;


                            cout << "IT IS DIAN THIS TIME" << endl;
                            cout << "THE WORD IS: " << word << endl;
                            cout << "FLOAT_SET 3" << endl;
                            for(it = float_set.begin(); it != float_set.end(); ++it){
                                cout << *it << " ";
                            }
                            cout << endl;
                            cout << "A TO Z SET 3" << endl;
                            for(it = a_to_z_set.begin(); it != a_to_z_set.end(); ++it){
                                cout << *it << " ";
                            }
                            cout << endl;
                            cout << "INDEX_NEXT_SET 3" << endl;








                            for(it_two = index_next_set.begin(); it_two != index_next_set.end(); ++it_two){
                                cout << *it_two << " ";
                            }
                        }


*/


                       //a_to_z_set.erase('b');
                       //If we can find b in the set, that means we recurse in this one. Erase the stuff in the a to z set
                       if(a_to_z_set.find('b') != a_to_z_set.end()/* && in[in_index] != '-'*/){
                            //cout << "FOUND THE B IN THE WORD: " << word << endl;
                           // cout << "WHAT IS THE INDEX: " << in_index << endl;
                            //cout << "WORD WORD: " << word << "------------>" << endl;
                            //cout << "WHAT IS C: " << c << endl;
                            std::string temporary = "";
                            temporary += c;
                            //a_to_z_set.erase('b');
                            //cout << "FINAL WORD: " << word << endl;
                            //cout << "IN_INDEX: " << in_index << endl;
                            //cout << in[in_index] << endl;
                            //cout << "SPLITTER----------->" << endl;
                            //if(wordle_Helper_Recurse(result, in, floating, dict, float_set, a_to_z_set, index_next_set, word, in_size, in_index, floating_index, not_dash_in_index, temporary)){


                        }
                    }
                }else{
                        //cout << "THE END?" << endl;
                        //if(wordle_Helper_Recurse(result, in, floating, dict, float_set, a_to_z_set, word + , in_size - 1, in_index + 1, floating_index, not_dash_in_index + 1, c)){ //Go over here and figure out what to add to the recursion
                        //}
                        return true;
                        //break;
                    }
                  //cout << "--------------->" << endl;
                }
















            }
  }
  //cout << "END OF RECURSION-------------------------->" << endl;
}


















bool isblank(string c){
    int size = 0;
    char c_temp = c[0];
    for(char temp = 'a'; temp <= 'z'; ++temp){
        if(c_temp != temp){
            ++size;
        }
    }
    return size == 26;
}








size_t floating_index_counter(const string& word, char c){
    size_t counter = 0;
    for(size_t i = 0; i < word.size(); ++i){
        if(c == word[i]){
          ++counter;
        }
    }
    return counter;
}






void wordle_Helper_Recurse_Fill_In_A_To_Z(set<char>& a_to_z_set){
    for(char c = 'a'; c <= 'z'; ++c){
        a_to_z_set.insert(c);
    }
}









