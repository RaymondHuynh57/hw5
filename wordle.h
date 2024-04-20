#ifndef WORDLE_H
#define WORDLE_H

#ifndef RECCHECK
#include <set>
#include <string>

//Temporary
#include <map>
#endif

/**
 * @brief Returns the list of all legal words in the provided dictionary
 *        that meet the criteria provided in the `in` and `floating`
 *        inputs.
 * 
 * @param [in] in - string of fixed, correct characters and `-`s to indicate
 *                  the length of string and locations that must be filled in
 * @param [in] floating  - Characters that must be used somewhere in the word
 * @param [in] dict - Dictionary of strings of legal words
 * @return std::set<std::string> - Set of all words that meet the criteria
 */
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict);

void wordleDashInCounter(const std::string& in,
    size_t in_index, 
    size_t& dash_counter);
void wordleNoDashInCounter(const std::string& in,
    size_t in_index,
    size_t& dash_no_counter);


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
    size_t& no_dash_amount);

void wordle_Helper(
    std::set<std::string>& result,
    size_t in_size);
//void wordle_Helper_Recurse(

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
    std::string character);

bool isblank(std::string c);
void wordle_Helper_Recurse_Floating(
    std::set<std::string>& result,
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict,
    std::string word,
    size_t in_size,
    size_t floating_index,
    size_t not_dash_in_index);

bool wordle_Helper_Word_Match_Floating(
  const std::string& floating,
  std::string word);



bool wordle_Helper_Mid_Recursion_Check(
    const std::string& in,
    const std::string& floating,
    std::string partial_word,
    size_t in_index);

bool wordle_Helper_Recurse_Loop_Condition(
  const std::string& floating,
  std::string recurse_word);

void wordle_Helper_Recurse_Fill_In_A_To_Z(
  std::set<char>& a_to_z_set);

size_t floating_index_counter(const std::string& word, char c);
#endif