/*
242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false


The solution to this problem is by using a hash map

we can increment the first string and decrement the second string
if the result gives us 0 then its an anagram



*/

#include <iostream>
#include <unordered_set>
#include <unordered_map>


class Solution {

public:
	bool isAnagram(std::string &s, std::string &t);


};

//We can also pass in the reference of the string to save space and not create a new copy of both
bool Solution::isAnagram(std::string &s, std::string &t){


	//Immediately we can check if both strings are the same length, if they arent, we can
	//Conclude that it is not an anagram

	if (s.length() != t.length()) {
		return false;
	}

	//Create a hash map that will store the key and frequence of the key 
	// The objective is to get 0, this indicates both strings have the exact same values
	// meaning that it is an anagram
	//We want the element to be the key and the frequence of that element to be the value
	std::unordered_map<char, int> letter_freq;

	//Create a for loop that iterates through the first string and includes the frequency
	//Inside of our hash map
	//the key to the hash map is the element that we are cycling thru inside of the string
	//the value is going to be the frequency of that element
	//Increment by 1 for each occurence within the first string
	for (int i = 0; i < s.length(); i++) {

		letter_freq[s[i]]++;
	}

	//Same thing as the first string but for the second string we decrement by 1
	//with each occurence, that way we know the element is inside of both strings
	//if they cancel out and it gives us 0
	for (int i = 0; i < t.length(); i++) {
		
		letter_freq[t[i]]--;
	}
	
	//After iterating through both strings, now we just have to check the hash map
	//And see if each value within the key:value pair is 0, if every single one is 0,
	//Then both strings are an anagram, however if we get anything besides 0, then
	//both strings are not anagrams of each other
	for (const auto& pair : letter_freq) {


		//Pair is just how we iterate through each key:value within the hash map
		//Since we are interating through a hash map, we can use .first and .second
		//To obtain the values of the key and value within the hash map
		//while iterating through the hash map, if any value isnt 0 we can return false
		if (pair.second != 0) {
			return false;
		}
	}


	//If all of the values inside of the key:value pair are 0's then it is an anagram
	//And we can return true
	return true;
}



int main() {


	std::string word1 = "hello";

	std::string word2 = "leloh";

	Solution solution;

	std::cout << std::boolalpha << solution.isAnagram(word1, word2);


	//time complexity = O(n)
	//space complexity = O(1)


	return 0;
}